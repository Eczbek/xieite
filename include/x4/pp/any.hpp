#pragma once

#include "../pp/not.hpp"

#define X4ANY(...) X4NOT(__VA_OPT__(0))
