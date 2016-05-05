# thrift --gen cpp WhatTime.thrift
clang++ -Wall -std=c++11 -stdlib=libc++ -I /usr/local/Cellar/thrift/0.9.2/include -c TimeService.cpp
clang++ -Wall -std=c++11 -stdlib=libc++ -I  /usr/local/Cellar/thrift/0.9.2/include -c WhatTime_constants.cpp
clang++ -Wall -std=c++11 -stdlib=libc++ -I  /usr/local/Cellar/thrift/0.9.2/include -c WhatTime_types.cpp
clang++ -Wall -std=c++11 -stdlib=libc++ -I  /usr/local/Cellar/thrift/0.9.2/include -c server.cpp
clang++ -Wall -std=c++11 -stdlib=libc++ -L /usr/local/Cellar/thrift/0.9.2/lib TimeService.o WhatTime_constants.o WhatTime_types.o server.o -o server -lthrift
clang++ -Wall -std=c++11 -stdlib=libc++ -I  /usr/local/Cellar/thrift/0.9.2/include -c client.cpp
clang++ -Wall -std=c++11 -stdlib=libc++ -L /usr/local/Cellar/thrift/0.9.2/lib TimeService.o WhatTime_constants.o WhatTime_types.o client.o -o client -lthrift

