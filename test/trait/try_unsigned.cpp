#include <xte/trait/is_same.hpp>
#include <xte/trait/try_unsigned.hpp>

static_assert(xte::is_same<unsigned int, xte::try_unsigned<int>>);
static_assert(xte::is_same<unsigned int, xte::try_unsigned<unsigned int>>);
static_assert(xte::is_same<double, xte::try_unsigned<double>>);
