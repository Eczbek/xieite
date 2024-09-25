#pragma once

#include <xieite/boolean.hpp>
#include <xieite/concatenate.hpp>

#define XIEITE_IF(condition_) XIEITE_IF_PRIMITIVE(XIEITE_BOOLEAN(condition_))
#define XIEITE_IF_PRIMITIVE(boolean_) XIEITE_CONCATENATE_PRIMITIVE(XIEITE_IF_PRIMITIVE_, boolean_)
#define XIEITE_IF_PRIMITIVE_0(then_, ...) __VA_ARGS__
#define XIEITE_IF_PRIMITIVE_1(then_, ...) then_
