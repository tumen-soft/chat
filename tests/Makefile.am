AM_CXXFLAGS = -fpermissive

check_PROGRAMS = test1 client_test test3 test4
test1_SOURCES = test1.cpp 
client_test_SOURCES = client_test.cpp
client_test_CXXFLAGS= -I$(top_srcdir)/lib  -fpermissive
client_test_LDADD= -lclient -L../lib
test3_SOURCES = test3.cpp
test4_SOURCES = test4.cpp
TESTS = $(check_PROGRAMS)
