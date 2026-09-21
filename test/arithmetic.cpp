#include <xte/aliases.hpp>
#include <xte/arithmetic.hpp>
#include <xte/detect/feature.hpp>
#include <xte/literal/numbers.hpp>
#include <xte/limits.hpp>

using namespace xte::literal::numbers;

static_assert(xte::add(0) == 0);
static_assert(xte::add(1) == 1);
static_assert(xte::add(2) == 2);
static_assert(xte::add(3) == 3);
static_assert(xte::add(1, 2, 3) == 6);
static_assert(xte::add(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 55);
static_assert(xte::add(-1u, 1u) == 0u);
#if XTE_HAS_INT_8
static_assert(xte::add(255_u8, 1_u8) == 0_u8);
#endif

static_assert(xte::sub(0) == 0);
static_assert(xte::sub(1) == 1);
static_assert(xte::sub(2) == 2);
static_assert(xte::sub(3) == 3);
static_assert(xte::sub(3, 2, 1) == 0);
static_assert(xte::sub(10, 9, 8, 7, 6, 5, 4, 3, 2, 1) == -35);
static_assert(xte::sub(0u, 1u) == -1u);
#if XTE_HAS_INT_8
static_assert(xte::sub(0_u8, 1_u8) == 255_u8);
#endif

static_assert(xte::mul(0) == 0);
static_assert(xte::mul(1) == 1);
static_assert(xte::mul(2) == 2);
static_assert(xte::mul(3) == 3);
static_assert(xte::mul(1, 2, 3) == 6);
static_assert(xte::mul(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 3628800);
static_assert(xte::mul(-1u, 2u) == (-1u << 1));
#if XTE_HAS_INT_8
static_assert(xte::mul(255_u8, 2_u8) == 254_u8);
#endif

static_assert(xte::div(0) == 0);
static_assert(xte::div(1) == 1);
static_assert(xte::div(2) == 2);
static_assert(xte::div(3) == 3);
static_assert(xte::div(1, 2) == 0);
static_assert(xte::div(64, 4, 2) == 8);
static_assert(xte::div(xte::highest<int>, -1) == (xte::lowest<int> + 1));
static_assert(xte::div(xte::lowest<int>, -1, -1) == xte::lowest<int>);
#if XTE_HAS_INT_8
static_assert(xte::div(255_u8, 2_u8) == 127_u8);
#endif

static_assert(xte::rem(-3, 3) == (-3 % 3));
static_assert(xte::rem(-2, 3) == (-2 % 3));
static_assert(xte::rem(-1, 3) == (-1 % 3));
static_assert(xte::rem(0, 3) == (0 % 3));
static_assert(xte::rem(1, 3) == (1 % 3));
static_assert(xte::rem(2, 3) == (2 % 3));
static_assert(xte::rem(3, 3) == (3 % 3));
static_assert(xte::rem(-7, 2) == (-7 % 2));
static_assert(xte::rem(7, -2) == (7 % -2));

static_assert(xte::mod(3, 8) == 3);
static_assert(xte::mod(-3, 8) == 5);
static_assert(xte::mod(3, -8) == -5);
static_assert(xte::mod(-3, -8) == -3);
static_assert(xte::mod(-21, 4) == 3);

static_assert(xte::pow(1, -2) == 1);
static_assert(xte::pow(1, -1) == 1);
static_assert(xte::pow(1, 0) == 1);
static_assert(xte::pow(1, 1) == 1);
static_assert(xte::pow(1, 2) == 1);
static_assert(xte::pow(-2, 1) == -2);
static_assert(xte::pow(-1, 1) == -1);
static_assert(xte::pow(0, 1) == 0);
static_assert(xte::pow(2, 1) == 2);
static_assert(xte::pow(-1, -2) == 1);
static_assert(xte::pow(-1, -1) == -1);
static_assert(xte::pow(-1, 0) == 1);
static_assert(xte::pow(-1, 1) == -1);
static_assert(xte::pow(-1, 2) == 1);
static_assert(xte::pow(-2, -2) == 0);
static_assert(xte::pow(2, -2) == 0);
static_assert(xte::pow(-2, -1) == 0);
static_assert(xte::pow(2, -1) == 0);
static_assert(xte::pow(-2, 0) == 1);
static_assert(xte::pow(0, 0) == 1);
static_assert(xte::pow(1, 0) == 1);
static_assert(xte::pow(2, 0) == 1);
static_assert(xte::pow(0, 2) == 0);
static_assert(xte::pow(10, 3) == 1000);
static_assert(xte::pow(2, 4) == 16);

static_assert(xte::add_checked(0));
static_assert(*xte::add_checked(0) == 0);
static_assert(xte::add_checked(1, 2));
static_assert(*xte::add_checked(1, 2) == 3);
static_assert(xte::add_checked(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
static_assert(*xte::add_checked(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 55);
static_assert(!xte::add_checked(-1u, 1u));

static_assert(xte::sub_checked(0));
static_assert(*xte::sub_checked(0) == 0);
static_assert(xte::sub_checked(2, 1));
static_assert(*xte::sub_checked(2, 1) == 1);
static_assert(xte::sub_checked(10, 9, 8, 7, 6, 5, 4, 3, 2, 1));
static_assert(*xte::sub_checked(10, 9, 8, 7, 6, 5, 4, 3, 2, 1) == -35);
static_assert(!xte::sub_checked(0u, 1u));

static_assert(xte::mul_checked(0));
static_assert(*xte::mul_checked(0) == 0);
static_assert(xte::mul_checked(2, 2));
static_assert(*xte::mul_checked(2, 2) == 4);
static_assert(xte::mul_checked(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
static_assert(*xte::mul_checked(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 3628800);
static_assert(!xte::mul_checked(-1u, 2u));

static_assert(xte::div_checked(0));
static_assert(*xte::div_checked(0) == 0);
static_assert(xte::div_checked(1, 2));
static_assert(*xte::div_checked(1, 2) == 0);
static_assert(xte::div_checked(64, 4, 2));
static_assert(*xte::div_checked(64, 4, 2) == 8);
static_assert(!xte::div_checked(3, 0));
static_assert(!xte::div_checked(xte::lowest<int>, -1));
static_assert(*xte::div_checked(xte::lowest<int>, -1, -1) == xte::lowest<int>);

// TODO: rem_checked, mod_checked

static_assert(!xte::pow_checked(50000, 2));
