#include <xte/compare.hpp>
#include <xte/limits.hpp>
#include <cfloat>
#include <climits>
#include <cmath>

// TODO: compare



static_assert(xte::equal(65536, 65536.0));
static_assert(xte::equal(65536.0, 65536));
static_assert(!xte::equal(65536, 65535.0));

static_assert(xte::equal(0, 0.0));
static_assert(!xte::equal(1, 1.5));

static_assert(!xte::equal(18446744073709550592ull, static_cast<double>(ULLONG_MAX)));
static_assert(!xte::equal(ULLONG_MAX, static_cast<double>(ULLONG_MAX)));

static_assert(!xte::equal(9007199254740995LL, 9007199254740996.0)); // 2^53+4 (exactly representable)
static_assert(xte::equal(9007199254740996LL, 9007199254740996.0));



static_assert(!xte::less(0, NAN));
static_assert(!xte::less(NAN, 0));
static_assert(!xte::less(NAN, NAN));

static_assert(xte::less(-1, 1));
static_assert(xte::less(-1, 1u));
static_assert(!xte::less(1, -1));
static_assert(!xte::less(1u, -1));
static_assert(xte::less(1u, -1u));
static_assert(!xte::less(-1u, 1u));
static_assert(!xte::less(0, 0));
static_assert(xte::less(0, 1));
static_assert(!xte::less(0, 0));
static_assert(xte::less(-5, 5));
static_assert(xte::less(-5, 5u));
static_assert(xte::less(-1, 0u));
static_assert(!xte::less(0u, -1));

static_assert(xte::less(1, INFINITY));
static_assert(xte::less(-1, INFINITY));
static_assert(!xte::less(INFINITY, 1));
static_assert(!xte::less(INFINITY, -1));
static_assert(xte::less(-INFINITY, 1));
static_assert(xte::less(-INFINITY, -1));
static_assert(!xte::less(1, -INFINITY));
static_assert(!xte::less(-1, -INFINITY));
static_assert(xte::less(-INFINITY, INFINITY));
static_assert(!xte::less(INFINITY, -INFINITY));
static_assert(!xte::less(INFINITY, INFINITY));
static_assert(!xte::less(-INFINITY, -INFINITY));

static_assert(xte::less(INT_MIN, INT_MAX + 1u));
static_assert(xte::less(-1, UINT_MAX));

static_assert(xte::less(1, 1.5));
static_assert(!xte::less(-1, -1.5));
static_assert(xte::less(-1.5, -1));
static_assert(!xte::less(1.5, 1));

static_assert(xte::less(1.0, 1.5));
static_assert(!xte::less(-1.0, -1.5));
static_assert(xte::less(-1.5, -1.0));
static_assert(!xte::less(1.5, 1.0));

static_assert(xte::less(ULLONG_MAX, std::nextafter(ULLONG_MAX, INFINITY)));
static_assert(!xte::less(LLONG_MIN, std::nextafter(LLONG_MIN, -INFINITY)));

static_assert(xte::less(ULLONG_MAX, static_cast<double>(ULLONG_MAX)));

static_assert(!xte::less(xte::highest<double>, 0));
static_assert(!xte::less(xte::highest<double>, 1));
static_assert(xte::less(0, 1.0));

struct A {
	int x;

	friend constexpr bool operator<(A lhs, A rhs) {
		return lhs.x < rhs.x;
	}
};
static_assert(xte::less(A(0), A(5)));

struct B {
	int x;

	friend constexpr bool operator>(B lhs, B rhs) {
		return lhs.x > rhs.x;
	}
};
static_assert(xte::less(B(0), B(5)));



// TODO: less_equal, greater, greater_equal
