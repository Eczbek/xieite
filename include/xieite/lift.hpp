#pragma once

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

#define XIEITE_LIFT(...) XIEITE_DETAIL_LIFT(, ..., __VA_ARGS__)
#define XIEITE_LIFT_LOCAL(...) XIEITE_DETAIL_LIFT(&, ..., __VA_ARGS__)
#define XIEITE_LIFT_ONE(...) XIEITE_DETAIL_LIFT(,, __VA_ARGS__)
#define XIEITE_LIFT_ONE_LOCAL(...) XIEITE_DETAIL_LIFT(&,, __VA_ARGS__)
#define XIEITE_LIFT_M(...) XIEITE_DETAIL_LIFT_M(.,  __VA_ARGS__)
#define XIEITE_LIFT_M_PTR(...) XIEITE_DETAIL_LIFT_M(->, __VA_ARGS__)

#define XIEITE_DETAIL_LIFT(capture_, ellipsis_, ...) \
	[capture_][[nodiscard]](auto&& ellipsis_ XIEITE_DETAIL_args) \
		XIEITE_ARROW_PARAM( \
			(decltype(XIEITE_DETAIL_args)&& ellipsis_ XIEITE_DETAIL_args), \
			__VA_ARGS__(XIEITE_FWD(XIEITE_DETAIL_args) ellipsis_) \
		)
#define XIEITE_DETAIL_LIFT_M(access_, ...) \
	[][[nodiscard]](auto&& XIEITE_DETAIL_obj, auto&&... XIEITE_DETAIL_args) \
		XIEITE_ARROW_PARAM( \
			(decltype(XIEITE_DETAIL_obj)&& XIEITE_DETAIL_obj, decltype(XIEITE_DETAIL_args)&&... XIEITE_DETAIL_args), \
			(XIEITE_FWD(XIEITE_DETAIL_obj) access_ __VA_ARGS__(XIEITE_FWD(XIEITE_DETAIL_args)...)) \
		)
