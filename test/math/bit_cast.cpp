#include <xte/math/bit_cast.hpp>

struct A {
	unsigned char x = 1;
	unsigned char y = 2;
};
static_assert(xte::bit_cast<unsigned char>(A()) == 1);
static_assert(xte::bit_cast<A>(static_cast<unsigned char>(5)).x == 5);
static_assert(xte::bit_cast<A>(static_cast<unsigned char>(5)).y == 0);
