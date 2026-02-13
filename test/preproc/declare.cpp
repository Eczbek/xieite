#include <xte/preproc/declare.hpp>

template<int x>
requires(x > 0)
int a;

template<int x>
XTE_DECLARE(int b, a<x>);

static_assert(!([]<int x = 0> { return requires { b<x>; }; })());
static_assert(requires { b<1>; });

template<int x>
requires(x > 0)
struct A {};

template<int x>
XTE_DECLARE_TYPE(struct B, A<x>) {};

static_assert(!([]<int x = 0> { return requires { typename B<x>; }; })());
static_assert(requires { typename B<1>; });
