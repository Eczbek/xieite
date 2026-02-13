#include <xte/trait/non_copyable.hpp>
#include <xte/util/xvalue.hpp>

struct S : xte::non_copyable {};

static_assert(requires { S(); });
static_assert(!requires (S s) { requires requires { S(s); }; });
static_assert(requires (S s) { S(xte::xvalue(s)); });
static_assert(!requires (S lhs, S rhs) { requires requires { lhs = rhs; }; });
static_assert(requires (S lhs, S rhs) { lhs = xte::xvalue(rhs); });
