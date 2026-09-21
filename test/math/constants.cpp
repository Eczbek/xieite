#include <xte/math/constants.hpp>

static_assert(xte::factorial<unsigned long long>[0] == 1);
static_assert(xte::factorial<unsigned long long>[1] == 1);
static_assert(xte::factorial<unsigned long long>[2] == 2);
static_assert(xte::factorial<unsigned long long>[3] == 6);
static_assert(xte::factorial<unsigned long long>[4] == 24);
static_assert(xte::factorial<unsigned long long>[5] == 120);
static_assert(xte::factorial<unsigned long long>[6] == 720);
static_assert(xte::factorial<unsigned long long>[7] == 5040);
static_assert(xte::factorial<unsigned long long>[8] == 40320);
static_assert(xte::factorial<unsigned long long>[9] == 362880);
static_assert(xte::factorial<unsigned long long>[10] == 3628800);
static_assert(xte::factorial<unsigned long long>[11] == 39916800);
static_assert(xte::factorial<unsigned long long>[12] == 479001600);
static_assert(xte::factorial<unsigned long long>[13] == 6227020800);
static_assert(xte::factorial<unsigned long long>[14] == 87178291200);
static_assert(xte::factorial<unsigned long long>[15] == 1307674368000);

static_assert(xte::fibonacci<unsigned long long>[0] == 0);
static_assert(xte::fibonacci<unsigned long long>[1] == 1);
static_assert(xte::fibonacci<unsigned long long>[2] == 1);
static_assert(xte::fibonacci<unsigned long long>[3] == 2);
static_assert(xte::fibonacci<unsigned long long>[4] == 3);
static_assert(xte::fibonacci<unsigned long long>[5] == 5);
static_assert(xte::fibonacci<unsigned long long>[6] == 8);
static_assert(xte::fibonacci<unsigned long long>[7] == 13);
static_assert(xte::fibonacci<unsigned long long>[8] == 21);
static_assert(xte::fibonacci<unsigned long long>[9] == 34);
static_assert(xte::fibonacci<unsigned long long>[10] == 55);
static_assert(xte::fibonacci<unsigned long long>[11] == 89);
static_assert(xte::fibonacci<unsigned long long>[12] == 144);
static_assert(xte::fibonacci<unsigned long long>[13] == 233);
static_assert(xte::fibonacci<unsigned long long>[14] == 377);
static_assert(xte::fibonacci<unsigned long long>[15] == 610);
