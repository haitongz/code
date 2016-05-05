#include "query_types.h"
#include "KeyWordsToVector.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TCompactProtocol.h>
#include <thrift/protocol/TBinaryProtocol.h>

#include <iostream>
using namespace std;

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;


int main(int argc, char *argv[]) {
  boost::shared_ptr<TSocket> socket(new TSocket("10.47.12.30", 7513));
  boost::shared_ptr<TTransport> transport(new TFramedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  typedef com::mediav::query::ResponseVector Tokens;

  com::mediav::query::KeyWordsToVectorClient client(protocol);
  transport->open();
//  int32_t version = client.getCurrentVersion();
  com::mediav::query::KeyWords  keywords;
  keywords.keywords = "北京";
  Tokens token;
  client.keywordsToVector(token,keywords);

  cout << "Now is " << token.tokenInfos.back().id << endl;
  transport->close();

  return 0;
}
