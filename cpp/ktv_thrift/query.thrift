#!/usr/local/bin/thrift --cpp --php --java

namespace cpp com.mediav.query
namespace java com.mediav.query
namespace php com.mediav.query

/**
** 用户的单条query 信息
*/
struct QueryInfo {
  1: required list<string> tokens; // query分词后的结果
  2: optional i64 timestamp;       // query的时间
  3: optional i32 source;          // query的来源
}

/**
** 用户的单条URL访问信息
*/
struct UrlInfo {
  1: required string url;    // 用户访问的URL
  2: optional i64 timestamp; // 用户访问该URL的时间(秒)
}

/**
** 用户的单个商品访问信息
*/
struct ProductInfo {
  1: required string id;      // 用户访问的商品id
  2: optional i64 timestamp;  // 用户访问该商品的时间(秒)
}

/**
** 用户在同一个网站上的多个商品访问信息
*/
struct SiteProductInfo {
  1: required list<ProductInfo> productInfos;  // 用户访问的商品信息
  2: optional string src;                      // 用户访问的商品网站，例如"taobao"
}

/**
** 用户的Query,URL和商品访问数据,以Thrift格式存储,以⼀个UserId为key
*/
struct UserQuery {
  1: required list<QueryInfo> queries;         // 所有query信息,按时间由近到远排序
  2: optional string uid;                      // 360 uid
  3: optional i64 lastUpdateTime;              // 写入RTDB的时间
  4: optional list<UrlInfo> urls;              // 用户访问的所有URL的信息
  5: optional list<SiteProductInfo> products;  // 用户访问的所有商品的信息
  6: optional bool latestDateData;             // 是否来自最新一天的原始数据
  7: optional bool firstMvidData;              // 当一个uid/mid对应到多个不同的mvid时，是否是第一个mvid的数据
  8: optional string mid;                      // URL数据中的mid
}

/**
* 表示Vector中的⼀个元素,稀疏表⽰
*/
struct TokenInfo {
  1: required i64 id;       // word/phrase对应的id
  2: optional i32 weight=1; // 在id上的weight,默认为1
}

/**
* 计算后的⼀个Query Session
*/
struct QuerySession {
  1: optional list<TokenInfo> tokenInfos; // QuerySession下的向量化表⽰,内部的TokenInfo预先排序
  2: optional i32 score;                  // 当前QuerySession的score
  3: optional i64 sessionId;              // 唯一标识该QuerySession的id
  4: optional i64 timestamp;              // 该QuerySession的时间戳
  5: optional i32 source;                 // 用户query的来源
}

/**
** 对搜索标签和querySession使用同一个结构储存，
** source = “search.label”.hashcode 时表示搜索标签，
*/
typedef QuerySession SearchLabels

/**
** ⽤户的搜索标签数据,以Thrift格式存储,以⼀个MVID为key
*/
struct UserInfo {
  1: required list<QuerySession> querySessions; // 一个用户的query session,按照价值从⾼到低排序
  2: optional string mvid;                      // mediav cookie
  3: optional i64 lastUpdateTime;               // 写入RTDB的时间
  4: optional i32 experimentId;                  // 记录策略实验id
  5: optional SearchLabels searchLabels;      	// 用户身上的搜索标签，不同标签之间关系为或
}

/**
** 对每一个搜索标签使用和TokenInfo相同结构储存
*/
typedef TokenInfo SearchLabel

/**
** 投放关键字设置的标签数据,以Thrift格式存储,以⼀个KeywordId为key
*/
struct KeywordLabelInfo {
  1: required i64 keywordId;			// keyword id
  2: required i32 solutionId;			// keyword对应的solutionid
  3: optional i64 lastUpdateTime;		// 写入RTDB的时间
  4: optional list<SearchLabel> searchLabels;	// 投放关键字设置的标签，不同标签之间关系为或
}

/**
** 投放关键字设置的标签数据在aerospike中更新的版本信息
*/
struct KeywordLabelVersionInfo
{
  1: required i32 version,                        // 版本号
  2: required i64 timestamp,                      // 版本生成时间
  3: optional i64 maxId,                          // aerospike数据表中的最大id
}

/**
** 投放关键字设置的标签数据在aerospike中的存储结构
*/
struct KeywordLabelData
{
  1: required map<i64, KeywordLabelInfo> keywordLabelData,   // Keyword Label数据信息
}

/**
** 投放设置返回的关键字向量
*/
struct ResponseVector {
  1: optional list<TokenInfo> tokenInfos; // QuerySession下的向量化表⽰示，内部的TokenInfo预先排序
  2: optional i32 ktvVersion; //ktv 版本号
}

/**
** 投放设置发给向量化服务的请求
*/
struct KeyWords {
  1: required string keywords; //投放设置中设置的原始关键字
  2: optional i32 solutionId; //投放设置的投放ID
  3: optional i32 keywordId; //投放设置中的关键字ID
}

/**
** 更新数据返回的Response
*/
struct Response {
  1: optional i32 returnCode;
  2: optional string message;
}

/**
** 关键词创意的一些基本信息
*/
struct KeywordCreative {
  1: optional i32 creativeId; //关键词创意ID
  2: optional string title;   //关键词创意的标题
  3: optional string content;    //关键词创意的内容
}

/**
** 关键词创意的Feature
*/
struct KeywordCreativeFeature{
  1: required i64 kcfId;  //Feature经过Hash后的Id. (选用i64是为了尽量减少Hash冲突的可能性)
  2: optional string featureName;  //该Feature的名称. (这个是可选的，仅当该Feature需要被用来作为某个组合Feature的原子Feature的时候，才需要这个名称来作为筛选条件;默认是不会有Feature名称的)
}

/**
** 某个关键词创意所提取出的对应的所有Feature
*/
struct KeywordCreativeResponse{
  1: optional i32 creativeId;	//关键词创意ID
  2: optional list<KeywordCreativeFeature> features;  //提取出的features
}

enum PeerStatus
{
P_READY = 0,
P_STOP = 1,
P_PAUSE = 2,
P_DEL = 3,
}

/**
** 返回给投放设置结果的服务
*/
service KeyWordsToVector {
  ResponseVector keywordsToVector(1:KeyWords request);
  list<ResponseVector> keywordsToVectors(1:list<KeyWords> request);
  Response reload(1:map<string, string> conf);
  
  /*定时查询服务状态接口*/
  PeerStatus GetPeerStatus();
  
  i32 getCurrentVersion();
  /*返回特定ktvVersion的分词结果，目前先忽略这个参数*/
  ResponseVector keywordsToVectorWithVersion(1:KeyWords request, 2:i32 ktvVersion);
  list<ResponseVector> keywordsToVectorsWithVersion(1:list<KeyWords> request, 2:i32 ktvVersion)

  /*根据提供的关键词基本信息,返回提取出的features*/
  KeywordCreativeResponse keywordCreativeToFeatures(1:KeywordCreative request);

  /*根据批量提供的关键词基本信息,批量返回提取出的features*/
  list<KeywordCreativeResponse> batchKeywordCreativeToFeatures(1:list<KeywordCreative> request); 

  Response reloadKeywordCreativeConfigure(1:map<string, string> conf);
}

