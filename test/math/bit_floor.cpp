#include <xte/math/bit_floor.hpp>
#include <limits>

static_assert(xte::bit_floor(0) == 0);
static_assert(xte::bit_floor(1) == 1);
static_assert(xte::bit_floor(2) == 2);
static_assert(xte::bit_floor(3) == 2);
static_assert(xte::bit_floor(7) == 4);
static_assert(xte::bit_floor(15) == 8);
static_assert(xte::bit_floor(31) == 16);
static_assert(xte::bit_floor(63) == 32);
static_assert(xte::bit_floor(127) == 64);
static_assert(xte::bit_floor(255) == 128);
static_assert(xte::bit_floor(511) == 256);
static_assert(xte::bit_floor(1023) == 512);
static_assert(xte::bit_floor(2047) == 1024);

static_assert(xte::bit_floor(-1) == std::numeric_limits<int>::lowest());
static_assert(xte::bit_floor(-2) == std::numeric_limits<int>::lowest());
static_assert(xte::bit_floor(-3) == std::numeric_limits<int>::lowest());
static_assert(xte::bit_floor(-4) == std::numeric_limits<int>::lowest());
