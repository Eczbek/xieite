#include <xte/chars.hpp>

static_assert(xte::is_whitespace(' '));
static_assert(xte::is_whitespace('\n'));
static_assert(xte::is_whitespace('\t'));
static_assert(xte::is_whitespace('\r'));
static_assert(xte::is_whitespace('\v'));
static_assert(xte::is_whitespace('\f'));
static_assert(!xte::is_whitespace('a'));
static_assert(!xte::is_whitespace('0'));
static_assert(!xte::is_whitespace('\0'));

static_assert(xte::is_decimal('0'));
static_assert(xte::is_decimal('1'));
static_assert(xte::is_decimal('2'));
static_assert(xte::is_decimal('3'));
static_assert(xte::is_decimal('4'));
static_assert(xte::is_decimal('5'));
static_assert(xte::is_decimal('6'));
static_assert(xte::is_decimal('7'));
static_assert(xte::is_decimal('8'));
static_assert(xte::is_decimal('9'));
static_assert(!xte::is_decimal('a'));
static_assert(!xte::is_decimal(' '));
static_assert(!xte::is_decimal('\0'));
