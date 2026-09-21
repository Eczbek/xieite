#include <xte/aliases.hpp>
#include <xte/limits.hpp>
#include <xte/math/bitwise.hpp>

static_assert(xte::rshift(0, 0) == 0);
static_assert(xte::rshift(1, 0) == 1);
static_assert(xte::rshift(1, 1) == 0);
static_assert(xte::rshift(1, 2) == 0);
static_assert(xte::rshift(255, 1) == 127);
static_assert(xte::rshift(255, 2) == 63);
static_assert(xte::rshift(255, 3) == 31);
static_assert(xte::rshift(255, 4) == 15);
static_assert(xte::rshift(255, 5) == 7);
static_assert(xte::rshift(255, 6) == 3);
static_assert(xte::rshift(255, 7) == 1);
static_assert(xte::rshift(255, 8) == 0);
static_assert(xte::rshift(xte::lowest<int>, xte::width<int>) == 0);
static_assert(xte::rshift(1, -1) == 2);
static_assert(xte::rshift(1, -2) == 4);
static_assert(xte::rshift(1, -3) == 8);
static_assert(xte::rshift(1, -static_cast<int>(xte::width<int>)) == 0);

static_assert(xte::lshift(static_cast<xte::u8>(0), 0) == 0);
static_assert(xte::lshift(static_cast<xte::u8>(1), 0) == 1);
static_assert(xte::lshift(static_cast<xte::u8>(1), 1) == 2);
static_assert(xte::lshift(static_cast<xte::u8>(1), 2) == 4);
static_assert(xte::lshift(static_cast<xte::u8>(1), 3) == 8);
static_assert(xte::lshift(static_cast<xte::u8>(1), 4) == 16);
static_assert(xte::lshift(static_cast<xte::u8>(1), 5) == 32);
static_assert(xte::lshift(static_cast<xte::u8>(1), 6) == 64);
static_assert(xte::lshift(static_cast<xte::u8>(1), 7) == 128);
static_assert(xte::lshift(static_cast<xte::u8>(1), 8) == 0);
static_assert(xte::lshift(1, xte::width<int>) == 0);
static_assert(xte::lshift(255, -1) == 127);
static_assert(xte::lshift(255, -2) == 63);
static_assert(xte::lshift(255, -3) == 31);
static_assert(xte::lshift(255, -static_cast<int>(xte::width<int>)) == 0);

static_assert(xte::is_single_bit(1));
static_assert(xte::is_single_bit(2));
static_assert(xte::is_single_bit(4));
static_assert(xte::is_single_bit(8));
static_assert(xte::is_single_bit(16));
static_assert(xte::is_single_bit(32));
static_assert(xte::is_single_bit(64));
static_assert(xte::is_single_bit(128));
static_assert(xte::is_single_bit(256));
static_assert(!xte::is_single_bit(0));
static_assert(!xte::is_single_bit(3));
static_assert(!xte::is_single_bit(7));
static_assert(!xte::is_single_bit(15));
static_assert(!xte::is_single_bit(31));
static_assert(!xte::is_single_bit(63));
static_assert(!xte::is_single_bit(127));
static_assert(!xte::is_single_bit(255));

static_assert(xte::leading_zeros(0) == xte::width<int>);
static_assert(xte::leading_zeros(1) == (xte::width<int> - 1));
static_assert(xte::leading_zeros(2) == (xte::width<int> - 2));
static_assert(xte::leading_zeros(4) == (xte::width<int> - 3));
static_assert(xte::leading_zeros(8) == (xte::width<int> - 4));
static_assert(xte::leading_zeros(16) == (xte::width<int> - 5));
static_assert(xte::leading_zeros(xte::highest<int>) == 1);
static_assert(xte::leading_zeros(xte::lowest<int>) == 0);
static_assert(xte::leading_zeros(xte::highest<unsigned int>) == 0);

static_assert(xte::trailing_zeros(0b0) == xte::width<int>);
static_assert(xte::trailing_zeros(0b1) == 0);
static_assert(xte::trailing_zeros(0b10) == 1);
static_assert(xte::trailing_zeros(0b100) == 2);
static_assert(xte::trailing_zeros(xte::lowest<int>) == ~-xte::width<int>);

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
static_assert(xte::bit_floor(-1) == xte::lowest<int>);
static_assert(xte::bit_floor(-2) == xte::lowest<int>);
static_assert(xte::bit_floor(-3) == xte::lowest<int>);
static_assert(xte::bit_floor(-4) == xte::lowest<int>);

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

static_assert(xte::bit_at(0b1010, 0) == 0);
static_assert(xte::bit_at(0b1010, 1) == 1);
static_assert(xte::bit_at(0b1010, 2) == 0);
static_assert(xte::bit_at(0b1010, 3) == 1);
