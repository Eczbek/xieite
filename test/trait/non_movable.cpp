#include <xte/trait/non_copyable.hpp>
#include <xte/trait/non_movable.hpp>
#include <xte/util/xvalue.hpp>

struct S : xte::non_copyable, xte::non_movable {};

static_assert(requires { S(); });
static_assert(!([]<typename T = S> { return requires (T s) { T(s); }; })());
static_assert(!([]<typename T = S> { return requires (T s) { T(xte::xvalue(s)); }; })());
static_assert(!([]<typename T = S> { return requires (T lhs, T rhs) { lhs = rhs; }; })());
static_assert(!([]<typename T = S> { return requires (T lhs, T rhs) { lhs = xte::xvalue(rhs); }; })());
