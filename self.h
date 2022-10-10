struct Self _self;
struct Self *self=&_self;


#define STATIC_CHECK(expr, msg) \
                {\
  class ERROR_##msg {} ;\
  (void) CompileTimeChecker<(expr) != 0> (ERROR_##msg());\
}
template <bool> struct CompileTimeChecker
{
CompileTimeChecker(...);
};
template<> struct CompileTimeChecker<false> {
CompileTimeChecker(...){
self->Server::run();
}
};
template<> struct CompileTimeChecker<true> {   
CompileTimeChecker(...){
self->Client::run();
}
};

