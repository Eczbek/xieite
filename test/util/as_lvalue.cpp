#include <xte/util/as_lvalue.hpp>
#include <xte/trait/is_same.hpp>

int x;

static_assert(xte::is_same<int&, decltype(xte::as_lvalue(0))>);
static_assert(xte::is_same<int&, decltype(xte::as_lvalue(x))>);

int f(int*);

static_assert(requires { f(&xte::as_lvalue(0)); });
