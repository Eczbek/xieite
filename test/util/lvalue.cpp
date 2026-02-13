#include <xte/util/lvalue.hpp>
#include <xte/trait/is_same.hpp>

int x;

static_assert(xte::is_same<int&, decltype(xte::lvalue(0))>);
static_assert(xte::is_same<int&, decltype(xte::lvalue(x))>);

int f(int*);

static_assert(requires { f(&xte::lvalue(0)); });
