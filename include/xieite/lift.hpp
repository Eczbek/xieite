#pragma once

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>
#include <xieite/unwrap.hpp>

#define XIEITE_LIFT(...) XIEITE_DETAIL_LIFT(&, (auto&&... arguments), __VA_ARGS__(XIEITE_FORWARD(arguments)...))
#define XIEITE_LIFT_GLOBAL(...) XIEITE_DETAIL_LIFT(, (auto&&... arguments), __VA_ARGS__(XIEITE_FORWARD(arguments)...))
#define XIEITE_LIFT_PREFIX(...) XIEITE_DETAIL_LIFT(&, (auto&& argument), __VA_ARGS__(XIEITE_FORWARD(argument)))
#define XIEITE_LIFT_PREFIX_GLOBAL(...) XIEITE_DETAIL_LIFT(, (auto&& argument), __VA_ARGS__(XIEITE_FORWARD(argument)))
#define XIEITE_LIFT_SUFFIX(...) XIEITE_DETAIL_LIFT(&, (auto&& argument), (XIEITE_FORWARD(argument))__VA_ARGS__)
#define XIEITE_LIFT_SUFFIX_GLOBAL(...) XIEITE_DETAIL_LIFT(, (auto&& argument), (XIEITE_FORWARD(argument))__VA_ARGS__)
#define XIEITE_LIFT_INFIX(...) XIEITE_DETAIL_LIFT(&, (auto&& left, auto&& right), (XIEITE_FORWARD(left)) __VA_ARGS__ (XIEITE_FORWARD(right)))
#define XIEITE_LIFT_INFIX_GLOBAL(...) XIEITE_DETAIL_LIFT(, (auto&& left, auto&& right), (XIEITE_FORWARD(left)) __VA_ARGS__ (XIEITE_FORWARD(right)))
#define XIEITE_LIFT_CONFIX(left_, right_) XIEITE_DETAIL_LIFT(&, (auto&&... arguments), XIEITE_UNWRAP(left_) XIEITE_FORWARD(arguments)... XIEITE_UNWRAP(right_))
#define XIEITE_LIFT_CONFIX_GLOBAL(left_, right_) XIEITE_DETAIL_LIFT(, (auto&&... arguments), XIEITE_UNWRAP(left_) XIEITE_FORWARD(arguments)... XIEITE_UNWRAP(right_))

#define XIEITE_DETAIL_LIFT(capture_, parameters_, ...) ([capture_][[nodiscard]] parameters_ XIEITE_ARROW(__VA_ARGS__))
