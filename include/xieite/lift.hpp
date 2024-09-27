#pragma once

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>
#include <xieite/unwrap.hpp>

#define XIEITE_LIFT(...) XIEITE_LIFT_CAPTURE(&, __VA_ARGS__)
#define XIEITE_LIFT_CAPTURE(captures_, ...) XIEITE_DETAIL_LIFT(captures_, (auto&&... arguments), __VA_ARGS__(XIEITE_FORWARD(arguments)...))
#define XIEITE_LIFT_PREFIX(...) XIEITE_LIFT_PREFIX_CAPTURE(&, __VA_ARGS__)
#define XIEITE_LIFT_PREFIX_CAPTURE(captures_, ...) XIEITE_DETAIL_LIFT(captures_, (auto&& argument), __VA_ARGS__(XIEITE_FORWARD(argument)))
#define XIEITE_LIFT_SUFFIX(...) XIIETE_LIFT_SUFFIX_CAPTURE(&, __VA_ARGS__)
#define XIEITE_LIFT_SUFFIX_CAPTURE(captures_, ...) XIEITE_DETAIL_LIFT(captures_, (auto&& argument), (XIEITE_FORWARD(argument))__VA_ARGS__)
#define XIEITE_LIFT_INFIX(...) XIEITE_LIFT_INFIX_CAPTURE(&, __VA_ARGS__)
#define XIEITE_LIFT_INFIX_CAPTURE(captures_, ...) XIEITE_DETAIL_LIFT(captures_, (auto&& left, auto&& right), (XIEITE_FORWARD(left)) __VA_ARGS__ (XIEITE_FORWARD(right)))
#define XIEITE_LIFT_CONFIX(left_, right_) XIEITE_LIFT_CONFIX_CAPTURE(&, left_, right_)
#define XIEITE_LIFT_CONFIX_CAPTURE(captures_, left_, right_) XIEITE_DETAIL_LIFT(captures_, (auto&&... arguments), XIEITE_UNWRAP(left_) XIEITE_FORWARD(arguments)... XIEITE_UNWRAP(right_))

#define XIEITE_DETAIL_LIFT(captures_, parameters_, ...) ([XIEITE_UNWRAP(captures_)][[nodiscard]] parameters_ XIEITE_ARROW(__VA_ARGS__))
