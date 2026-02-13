#include <xte/math/is_single_bit.hpp>

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
