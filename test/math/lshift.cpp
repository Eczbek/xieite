#include <xte/math/lshift.hpp>
#include <xte/math/width.hpp>
#include <cstdint>

static_assert(xte::lshift(std::uint8_t(0), 0) == 0);
static_assert(xte::lshift(std::uint8_t(1), 0) == 1);
static_assert(xte::lshift(std::uint8_t(1), 1) == 2);
static_assert(xte::lshift(std::uint8_t(1), 2) == 4);
static_assert(xte::lshift(std::uint8_t(1), 3) == 8);
static_assert(xte::lshift(std::uint8_t(1), 4) == 16);
static_assert(xte::lshift(std::uint8_t(1), 5) == 32);
static_assert(xte::lshift(std::uint8_t(1), 6) == 64);
static_assert(xte::lshift(std::uint8_t(1), 7) == 128);
static_assert(xte::lshift(std::uint8_t(1), 8) == 0);

static_assert(xte::lshift(1, xte::width<int>) == 0);
