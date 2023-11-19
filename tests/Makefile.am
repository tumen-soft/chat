AM_CXXFLAGS = -fpermissive

check_PROGRAMS = test1 client_test server_test test4
test1_SOURCES = test1.cpp 
client_test_SOURCES = client_test.cpp
client_test_CXXFLAGS= -I$(top_srcdir)/include  -fpermissive
client_test_LDADD= -lchat -L../lib
server_test_SOURCES = server_test.cpp
server_test_CXXFLAGS= -I$(top_srcdir)/include  -fpermissive
server_test_LDADD= -lchat -L../lib
test4_SOURCES = test4.cpp
TESTS = $(check_PROGRAMS)
