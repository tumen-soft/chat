AUTOMAKE_OPTIONS=subdir-objects
lib_LIBRARIES=libchat.a
lib_LTLIBRARIES=libchat.la
libchat_a_SOURCES=client.cpp server.cpp
libchat_la_SOURCES=client.cpp server.cpp
libchat_la_CFLAGS=-fPIC
libchat_la_CPPFLAGS=-fPIC
libchat_la_CXXFLAGS=-fPIC -I$(top_srcdir)/include -fpermissive
libchat_a_CXXFLAGS=-fPIC -I$(top_srcdir)/include -fpermissive 
#lib_LTLIBRARIES=libserver.la
#libserver_la_SOURCES=server.cpp
#libserver_la_CFLAGS=-fPIC
#libserver_la_CPPFLAGS=-fPIC
#libserver_la_CXXFLAGS=-fPIC -I$(top_srcdir)/include -fpermissive

