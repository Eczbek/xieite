#include <xte/math/bit_ceil.hpp>
#include <limits>

static_assert(xte::bit_ceil(0) == 1);
static_assert(xte::bit_ceil(1) == 1);
static_assert(xte::bit_ceil(2) == 2);
static_assert(xte::bit_ceil(3) == 4);
static_assert(xte::bit_ceil(5) == 8);
static_assert(xte::bit_ceil(9) == 16);
static_assert(xte::bit_ceil(17) == 32);
static_assert(xte::bit_ceil(33) == 64);
static_assert(xte::bit_ceil(65) == 128);
static_assert(xte::bit_ceil(129) == 256);
static_assert(xte::bit_ceil(257) == 512);
static_assert(xte::bit_ceil(513) == 1024);
static_assert(xte::bit_ceil(1025) == 2048);

static_assert(xte::bit_ceil(std::numeric_limits<int>::lowest()) == std::numeric_limits<int>::lowest());
static_assert(xte::bit_ceil(std::numeric_limits<unsigned>::max()) == 0);
