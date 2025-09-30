#include <xte/meta/declare.hpp>

struct S {
	S() = delete;

	void f() &&;
};

static_assert(requires { xte::declare<S>().f(); });
