#include <xte/preproc/define_cast.hpp>
#include <xte/preproc/fwd.hpp>
#include <xte/util/as_const.hpp>
#include <xte/util/as_lvalue.hpp>

struct Cast {
	int x;

	XTE_DEFINE_CAST(constexpr, auto&& self,
		XTE_FWD(self).x
	)
};

static_assert(requires { static_cast<int&&>(Cast()); });
static_assert(requires { static_cast<const int&&>(xte::as_const(Cast())); });
static_assert(requires { static_cast<int&>(xte::as_lvalue(Cast())); });
static_assert(requires { static_cast<const int&>(xte::as_const(xte::as_lvalue(Cast()))); });
