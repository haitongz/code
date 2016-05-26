#include <iostream>
#include <string>
#include <sys/time.h>
#include <sstream>
#include <stdio.h>
#include "concat.h"

using namespace std;
using namespace theypsilon;
using namespace std;

#define OUT_IN_REPEATE_NUM 1000000
#define IN_REPEATE_NUM 60

string s1="abcedfg";
string s2="hijklmn";
string s3="opqrst";
void  plusTest(string& ret)
{
    for(int i=0; i<IN_REPEATE_NUM; i++)
    {
        ret += s1;
        ret += s2;
        ret += s3;
    }
}
void  appendTest(string& ret)
{
    for(int i=0; i<IN_REPEATE_NUM; i++)
    {
        ret.append(s1);
        ret.append(s2);
        ret.append(s3);
    }
}
void  addTest(string& ret)
{
  for(int i=0; i<IN_REPEATE_NUM; i++)
  {
    ret = s1 + s2 + s3;
  }
}
void sprintfTest(string& ret)
{
    const size_t length=26*IN_REPEATE_NUM;
    char tmp[length];
    char* cp = tmp;
    size_t strLength=s1.length()+s2.length()+s3.length();
    for(int i=0; i<IN_REPEATE_NUM; i++)
    {
        sprintf(cp,"%s%s%s", s1.c_str(), s2.c_str(),s3.c_str());
        cp+=strLength;
    }
    ret = tmp;
}

void  ssTest(string& ret)
{
    stringstream ss;
    for(int i=0; i<IN_REPEATE_NUM; i++)
    {
        ss<<s1;
        ss<<s2;
        ss<<s3;
    }
    ret = ss.str();
}

void  concatTest(string& ret)
{
    for(int i=0; i<IN_REPEATE_NUM; i++)
    {
        ret = concat(s1, s2, s3);
    }
}
int main() {
    string ss, plus, append, sprintf, concat, add;
    struct timeval sTime, eTime;

    gettimeofday(&sTime, NULL);
    for(int i=0; i<OUT_IN_REPEATE_NUM; i++)
    {
        sprintf="";
        sprintfTest(sprintf);
    }
    gettimeofday(&eTime, NULL);
    long SprintfTime = (eTime.tv_sec-sTime.tv_sec)*1000000+(eTime.tv_usec-sTime.tv_usec); //exeTime 单位是微秒

    gettimeofday(&sTime, NULL);
    for(int i=0; i<OUT_IN_REPEATE_NUM; i++)
    {
        append="";
        appendTest(append);
    }
    gettimeofday(&eTime, NULL);
    long AppendTime = (eTime.tv_sec-sTime.tv_sec)*1000000+(eTime.tv_usec-sTime.tv_usec); //exeTime 单位是微秒

    gettimeofday(&sTime, NULL);
    for(int i=0; i<OUT_IN_REPEATE_NUM; i++)
    {
        ss="";
        ssTest(ss);
    }
    gettimeofday(&eTime, NULL);
    long SsTime = (eTime.tv_sec-sTime.tv_sec)*1000000+(eTime.tv_usec-sTime.tv_usec); //exeTime 单位是微秒

    gettimeofday(&sTime, NULL);
    for(int i=0; i<OUT_IN_REPEATE_NUM; i++)
    {
        plus="";
        plusTest(plus);
    }
    gettimeofday(&eTime, NULL);
    long PlusTime = (eTime.tv_sec-sTime.tv_sec)*1000000+(eTime.tv_usec-sTime.tv_usec); //exeTime 单位是微秒

    gettimeofday(&sTime, NULL);
    for(int i=0; i<OUT_IN_REPEATE_NUM; i++)
    {
        concat="";
        concatTest(concat);
    }
    gettimeofday(&eTime, NULL);
    long concatTime = (eTime.tv_sec-sTime.tv_sec)*1000000+(eTime.tv_usec-sTime.tv_usec); //exeTime 单位是微秒

    gettimeofday(&sTime, NULL);
    for(int i=0; i<OUT_IN_REPEATE_NUM; i++)
    {
        add="";
        concatTest(add);
    }
    gettimeofday(&eTime, NULL);
    long addTime = (eTime.tv_sec-sTime.tv_sec)*1000000+(eTime.tv_usec-sTime.tv_usec); //exeTime 单位是微秒

    cout<<"PlusTime is :   "<<PlusTime<<endl;
    cout<<"AppendTime is : "<<AppendTime<<endl;
    cout<<"SsTime is :     "<<SsTime<<endl;
    cout<<"SprintfTime is :"<<SprintfTime<<endl;
    cout<<"ConcatTime is :"<<concatTime<<endl;
    cout<<"AddTime is :"<<addTime<<endl;
    if(ss==sprintf && append==plus && ss==plus && plus == concat && plus == add)
    {
        cout<<"They are same"<<endl;
    }
    else
    {
        cout<<"Different!"<<endl;
        cout<<"Sprintf: "<<sprintf<<endl;
        cout<<"ss:        "<<ss<<endl;
        cout<<"Plus:     "<<plus<<endl;
        cout<<"Append:"<<append<<endl;
    }

}
