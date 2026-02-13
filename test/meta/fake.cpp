#include <xte/meta/fake.hpp>

struct S {
	S() = delete;

	void f() &&;
};

static_assert(requires { xte::fake<S>().f(); });
