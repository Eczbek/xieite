#include <xte/math/highest.hpp>
#include <xte/math/leading_zeros.hpp>
#include <xte/math/lowest.hpp>
#include <xte/math/width.hpp>

static_assert(xte::leading_zeros(0) == xte::width<int>);
static_assert(xte::leading_zeros(1) == (xte::width<int> - 1));
static_assert(xte::leading_zeros(2) == (xte::width<int> - 2));
static_assert(xte::leading_zeros(4) == (xte::width<int> - 3));
static_assert(xte::leading_zeros(8) == (xte::width<int> - 4));
static_assert(xte::leading_zeros(16) == (xte::width<int> - 5));

static_assert(xte::leading_zeros(xte::highest<int>) == 1);
static_assert(xte::leading_zeros(xte::lowest<int>) == 0);

static_assert(xte::leading_zeros(xte::highest<unsigned int>) == 0);
