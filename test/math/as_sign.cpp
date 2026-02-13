#include <xte/math/as_sign.hpp>

static_assert(xte::as_sign<unsigned>(static_cast<signed char>(-1)) == static_cast<unsigned char>(-1));
static_assert(xte::as_sign<int>(static_cast<unsigned char>(-1)) == -1);
