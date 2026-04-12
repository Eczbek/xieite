#include <xte/math/pow.hpp>

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
