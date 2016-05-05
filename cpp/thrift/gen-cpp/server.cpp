// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "TimeService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::roctime;

class TimeServiceHandler : virtual public TimeServiceIf {
 public:
  TimeServiceHandler() {
    // Your initialization goes here
  }

  int32_t TellMeTime() {
    // Your implementation goes here
    time_t now_time = time(NULL);
    return now_time;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<TimeServiceHandler> handler(new TimeServiceHandler());
  shared_ptr<TProcessor> processor(new TimeServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

