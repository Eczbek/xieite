#include <xte/math/equal.hpp>
#include <climits>

static_assert(xte::equal(65536, 65536.0));
static_assert(xte::equal(65536.0, 65536));
static_assert(!xte::equal(65536, 65535.0));

static_assert(xte::equal(0, 0.0));
static_assert(!xte::equal(1, 1.5));

static_assert(!xte::equal(18446744073709550592ull, static_cast<double>(ULLONG_MAX)));
static_assert(!xte::equal(ULLONG_MAX, static_cast<double>(ULLONG_MAX)));

static_assert(!xte::equal(9007199254740995LL, 9007199254740996.0)); // 2^53+4 (exactly representable)
static_assert(xte::equal(9007199254740996LL, 9007199254740996.0));
