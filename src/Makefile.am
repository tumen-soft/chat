AUTOMAKE_OPTIONS=subdir-objects
AM_CPPFLAGS = -I$(top_srcdir)/include  -fpermissive -g
#bin_PROGRAMS=chat
#chat_SOURCES=main.cpp #client.cpp

#lib_LTLIBRARIES=libtest.la
#libtest_la_SOURCES=client.cpp client.h
#libtest_la_CFLAGS=-fPIC
#libtest_la_CPPFLAGS=-fPIC
#libtest_la_CXXFLAGS=-fPIC -I$(top_srcdir)/include -fpermissive


bin_PROGRAMS=chat
chat_SOURCES=main.cpp #client.cpp
chat_CXXFLAGS= -I$(top_srcdir)/lib
chat_LDADD= -lclient -lserver -L../lib
