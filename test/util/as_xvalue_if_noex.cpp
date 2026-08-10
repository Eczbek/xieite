#include <xte/trait/is_callable.hpp>
#include <xte/util/as_xvalue_if_noex.hpp>

struct throwing_move_ctor {
	throwing_move_ctor() = default;
	throwing_move_ctor(const throwing_move_ctor&) = default;
	throwing_move_ctor(throwing_move_ctor&&) noexcept(false) {}
};

struct fail {
	fail() = default;
	fail(const fail&) = delete;
	fail(fail&&) noexcept(false) {}
};

static_assert(^^decltype(xte::as_xvalue_if_noex(0)) == ^^int&&);
static_assert(^^decltype(xte::as_xvalue_if_noex(throwing_move_ctor())) == ^^const throwing_move_ctor&);
static_assert(!xte::is_callable<decltype(xte::as_xvalue_if_noex), fail>);
