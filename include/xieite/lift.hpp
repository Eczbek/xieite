#pragma once

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

#define XIEITE_LIFT(...) XIEITE_DETAIL_LIFT(&, __VA_ARGS__)
#define XIEITE_GLIFT(...) XIEITE_DETAIL_LIFT(, __VA_ARGS__)

#define XIEITE_DETAIL_LIFT(capture, ...) ([capture][[nodiscard]](auto&&... XIEITE_DETAIL_ARGS) XIEITE_ARROW(__VA_ARGS__(XIEITE_DETAIL_FWD(capture, XIEITE_DETAIL_ARGS)...)))
