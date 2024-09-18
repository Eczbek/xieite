#pragma once

#include <xieite/eat.hpp>
#include <xieite/if.hpp>
#include <xieite/scan.hpp>

#define XIEITE_WHEN($value) XIEITE_IF($value)(XIEITE_SCAN, XIEITE_EAT)
