#pragma once

#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

#define XIEITE_LIFT(...) []DETAIL_XIEITE_LIFT(static, __VA_ARGS__)
#define XIEITE_LIFT_LOCAL(...) [&]DETAIL_XIEITE_LIFT(, __VA_ARGS__)
#define XIEITE_LIFT_M(...) DETAIL_XIEITE_LIFT_M(., __VA_ARGS__)
#define XIEITE_LIFT_M_PTR(...) DETAIL_XIEITE_LIFT_M(->, __VA_ARGS__)

#define DETAIL_XIEITE_LIFT(specs_, ...) \
	[[nodiscard]](auto&&... DETAIL_XIEITE_args) specs_ \
		XIEITE_ARROW_DECL(DETAIL_XIEITE_args, __VA_ARGS__(XIEITE_FWD(DETAIL_XIEITE_args)...))
#define DETAIL_XIEITE_LIFT_M(access_, ...) \
	[][[nodiscard]](auto&& DETAIL_XIEITE_obj, auto&&... DETAIL_XIEITE_args) static \
		XIEITE_ARROW_DECL((DETAIL_XIEITE_obj, (DETAIL_XIEITE_args)), (XIEITE_FWD(DETAIL_XIEITE_obj) access_ __VA_ARGS__(XIEITE_FWD(DETAIL_XIEITE_args)...)))
