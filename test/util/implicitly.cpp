#include <xte/util/implicitly.hpp>

struct A {
	bool implicit;

	constexpr A() : implicit(true) {}

	explicit constexpr A(auto&&) : implicit(false) {}
};

struct B {
	explicit(false) constexpr operator A() const {
		return {};
	}
};

static_assert(xte::implicitly<A>(B()).implicit);
