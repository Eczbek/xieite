#include <xte/trait/is_same.hpp>
#include <xte/util/unmove.hpp>

int x;

static_assert(xte::is_same<int&, decltype(xte::unmove(0))>);
static_assert(xte::is_same<int&, decltype(xte::unmove(x))>);

int f(int*);

static_assert(requires { f(&xte::unmove(0)); });
