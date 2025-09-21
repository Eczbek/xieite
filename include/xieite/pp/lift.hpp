#ifndef DETAIL_XIEITE_HEADER_PP_LIFT
#	define DETAIL_XIEITE_HEADER_PP_LIFT
#
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#
#	define XIEITE_LIFT(...) ([]DETAIL_XIEITE_LIFT(/* static */, __VA_ARGS__))
#	define XIEITE_LIFT_LOCAL(...) ([&]DETAIL_XIEITE_LIFT(, __VA_ARGS__))
#	define XIEITE_LIFT_IFX(...) DETAIL_XIEITE_LIFT_IFX(, __VA_ARGS__)
#	define XIEITE_LIFT_MEMBER(...) DETAIL_XIEITE_LIFT_IFX(..., __VA_ARGS__)
#
#	define DETAIL_XIEITE_LIFT(_specs, ...) \
		[[nodiscard]](auto&&... DETAIL_XIEITE_args) _specs XIEITE_ARROW( \
			__VA_ARGS__(XIEITE_FWD(DETAIL_XIEITE_args)...) \
		)
#	define DETAIL_XIEITE_LIFT_IFX(_ellipsis, ...) \
		([][[nodiscard]](auto&& DETAIL_XIEITE_lhs, auto&&_ellipsis DETAIL_XIEITE_rhs) /* static */ XIEITE_ARROW( \
			XIEITE_FWD(DETAIL_XIEITE_lhs)__VA_ARGS__(XIEITE_FWD(DETAIL_XIEITE_rhs)_ellipsis)) \
		)
#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=121900
