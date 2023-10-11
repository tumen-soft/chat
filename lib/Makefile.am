AUTOMAKE_OPTIONS=subdir-objects

lib_LTLIBRARIES=libclient.la libserver.la
libclient_la_SOURCES=client.cpp
libclient_la_CFLAGS=-fPIC
libclient_la_CPPFLAGS=-fPIC
libclient_la_CXXFLAGS=-fPIC -I$(top_srcdir)/include -fpermissive

#lib_LTLIBRARIES=libserver.la
libserver_la_SOURCES=server.cpp
libserver_la_CFLAGS=-fPIC
libserver_la_CPPFLAGS=-fPIC
libserver_la_CXXFLAGS=-fPIC -I$(top_srcdir)/include -fpermissive

