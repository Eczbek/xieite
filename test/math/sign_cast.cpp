#include <xte/math/sign_cast.hpp>

static_assert(xte::sign_cast<unsigned>(static_cast<signed char>(-1)) == static_cast<unsigned char>(-1));
static_assert(xte::sign_cast<int>(static_cast<unsigned char>(-1)) == -1);
