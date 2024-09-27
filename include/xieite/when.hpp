#pragma once

#include <xieite/eat.hpp>
#include <xieite/if.hpp>
#include <xieite/scan.hpp>

#define XIEITE_WHEN(value_) XIEITE_IF(value_)(XIEITE_SCAN, XIEITE_EAT)
