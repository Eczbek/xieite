#include <xte/math/bit_ceil.hpp>
#include <xte/math/highest.hpp>
#include <xte/math/lowest.hpp>

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

static_assert(xte::bit_ceil(xte::lowest<int>) == xte::lowest<int>);
static_assert(xte::bit_ceil(xte::highest<unsigned>) == 0);
