#include <xte/data/opt.hpp>

struct A {
	A(int) {}

	A(A&&) = delete;
};

static_assert(requires { xte::opt<A>(0); });
