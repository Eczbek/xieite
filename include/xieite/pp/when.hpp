#pragma once

#include "../pp/eat.hpp"
#include "../pp/if.hpp"
#include "../pp/scan.hpp"

#define XIEITE_WHEN(x) XIEITE_IF(x)(XIEITE_SCAN, XIEITE_EAT)
