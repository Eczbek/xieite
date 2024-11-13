#pragma once

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

#define XIEITE_LIFT(...) XIEITE_DETAIL_LIFT(, ..., __VA_ARGS__)
#define XIEITE_LIFT_LOCAL(...) XIEITE_DETAIL_LIFT(&, ..., __VA_ARGS__)
#define XIEITE_LIFT_ONE(...) XIEITE_DETAIL_LIFT(,, __VA_ARGS__)
#define XIEITE_LIFT_LOCAL_ONE(...) XIEITE_DETAIL_LIFT(&,, __VA_ARGS__)

#define XIEITE_DETAIL_LIFT(capture, ellipsis, ...) \
	[capture][[nodiscard]](auto&& ellipsis XIEITE_DETAIL_ARGS \
	XIEITE_ARROW(__VA_ARGS__(XIEITE_FWD(XIEITE_DETAIL_ARGS) ellipsis)))
