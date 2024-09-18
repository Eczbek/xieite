#pragma once

#include <xieite/boolean.hpp>
#include <xieite/concatenate.hpp>

#define XIEITE_IF($condition) XIEITE_IF_PRIMITIVE(XIEITE_BOOLEAN($condition))
#define XIEITE_IF_PRIMITIVE($boolean) XIEITE_CONCATENATE_PRIMITIVE(XIEITE_IF_PRIMITIVE_, $boolean)
#define XIEITE_IF_PRIMITIVE_0($then, ...) __VA_ARGS__
#define XIEITE_IF_PRIMITIVE_1($then, ...) $then
