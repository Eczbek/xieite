#pragma once

#include <xieite/eat.hpp>
#include <xieite/if.hpp>
#include <xieite/scan.hpp>

#define XIEITE_WHEN(x) XIEITE_IF(x)(XIEITE_SCAN, XIEITE_EAT)
