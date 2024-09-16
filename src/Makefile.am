AUTOMAKE_OPTIONS=subdir-objects
AM_CPPFLAGS = -I$(top_srcdir)/include -fpermissive 
if DEBUG
AM_CPPFLAGS += -DDEBUG
else
AM_CPPFLAGS +=
endif

#bin_PROGRAMS=chat
#chat_SOURCES=main.cpp #client.cpp

#lib_LTLIBRARIES=libtest.la
#libtest_la_SOURCES=client.cpp client.h
#libtest_la_CFLAGS=-fPIC
#libtest_la_CPPFLAGS=-fPIC
#libtest_la_CXXFLAGS=-fPIC -I$(top_srcdir)/include -fpermissive


bin_PROGRAMS=chat
chat_SOURCES=chat.cpp main.cpp
chat_CXXFLAGS= -I$(top_srcdir)/libchat
chat_LDADD= -lchat -L../libchat
