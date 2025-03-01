#pragma once

#include "../pp/eat.hpp"
#include "../pp/if.hpp"
#include "../pp/scan.hpp"

#define X4WHEN(x) X4IF(x)(X4SCAN, X4EAT)
