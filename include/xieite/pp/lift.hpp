#ifndef DETAIL_XIEITE_HEADER_PP_LIFT
#	define DETAIL_XIEITE_HEADER_PP_LIFT
#
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#
#	define XIEITE_LIFT(...) ([]DETAIL_XIEITE_LIFT(static, __VA_ARGS__))
#	define XIEITE_LIFT_LOCAL(...) ([&]DETAIL_XIEITE_LIFT(, __VA_ARGS__))
#	define XIEITE_LIFT_IFX(...) \
		([][[nodiscard]](auto&& DETAIL_XIEITE_obj, auto&&... DETAIL_XIEITE_args) static \
			XIEITE_ARROW(XIEITE_FWD(DETAIL_XIEITE_obj)__VA_ARGS__(XIEITE_FWD(DETAIL_XIEITE_args)...)))
#
#	define DETAIL_XIEITE_LIFT(specs_, ...) \
		[[nodiscard]](auto&&... DETAIL_XIEITE_args) specs_ \
			XIEITE_ARROW(__VA_ARGS__(XIEITE_FWD(DETAIL_XIEITE_args)...))
#endif
