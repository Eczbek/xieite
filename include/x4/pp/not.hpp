#pragma once

#include "../pp/check.hpp"
#include "../pp/cat.hpp"
#include "../pp/probe.hpp"

#define X4NOT(x) X4CHECK(X4PCAT(DETAIL_X4NOT, x))

#define DETAIL_X4NOT0 X4PROBE(~)
