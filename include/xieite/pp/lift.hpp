#pragma once

#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

#define XIEITE_LIFT(...) []XIEITE_DETAIL_LIFT(static, __VA_ARGS__)
#define XIEITE_LIFT_LOCAL(...) [&]XIEITE_DETAIL_LIFT(, __VA_ARGS__)
#define XIEITE_LIFT_M(...) XIEITE_DETAIL_LIFT_M(.,  __VA_ARGS__)
#define XIEITE_LIFT_M_PTR(...) XIEITE_DETAIL_LIFT_M(->, __VA_ARGS__)

#define XIEITE_DETAIL_LIFT(specs_, ...) \
	[[nodiscard]](auto&&... XIEITE_DETAIL_args) specs_ \
		XIEITE_ARROW_PARAM( \
			(decltype(XIEITE_DETAIL_args)&&... XIEITE_DETAIL_args), \
			__VA_ARGS__(XIEITE_FWD(XIEITE_DETAIL_args)...) \
		)
#define XIEITE_DETAIL_LIFT_M(access_, ...) \
	[][[nodiscard]](auto&& XIEITE_DETAIL_obj, auto&&... XIEITE_DETAIL_args) static \
		XIEITE_ARROW_PARAM( \
			(decltype(XIEITE_DETAIL_obj)&& XIEITE_DETAIL_obj, decltype(XIEITE_DETAIL_args)&&... XIEITE_DETAIL_args), \
			(XIEITE_FWD(XIEITE_DETAIL_obj) access_ __VA_ARGS__(XIEITE_FWD(XIEITE_DETAIL_args)...)) \
		)
