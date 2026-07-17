#include <xte/trait/is_same.hpp>
#include <xte/trait/try_signed.hpp>

static_assert(xte::is_same<int, xte::try_signed<unsigned int>>);
static_assert(xte::is_same<int, xte::try_signed<int>>);
static_assert(xte::is_same<double, xte::try_signed<double>>);
