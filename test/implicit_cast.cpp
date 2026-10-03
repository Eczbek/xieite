#include <xte/implicit_cast.hpp>

struct A {
	bool implicit;

	constexpr A() : implicit(true) {}

	constexpr explicit A(auto&&) : implicit(false) {}
};

struct B {
	constexpr explicit(false) operator A() const {
		return {};
	}
};

static_assert(xte::implicit_cast<A>(B()).implicit);
