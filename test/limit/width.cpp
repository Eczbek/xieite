#include <limits>
#include <xte/limit/width.hpp>

static_assert(xte::width<unsigned char> == (std::numeric_limits<unsigned char>::digits + std::numeric_limits<unsigned char>::is_signed));
static_assert(xte::width<signed char> == (std::numeric_limits<signed char>::digits + std::numeric_limits<signed char>::is_signed));
static_assert(xte::width<unsigned short> == (std::numeric_limits<unsigned short>::digits + std::numeric_limits<unsigned short>::is_signed));
static_assert(xte::width<short> == (std::numeric_limits<short>::digits + std::numeric_limits<short>::is_signed));
static_assert(xte::width<unsigned int> == (std::numeric_limits<unsigned int>::digits + std::numeric_limits<unsigned int>::is_signed));
static_assert(xte::width<int> == (std::numeric_limits<int>::digits + std::numeric_limits<int>::is_signed));
static_assert(xte::width<unsigned long> == (std::numeric_limits<unsigned long>::digits + std::numeric_limits<unsigned long>::is_signed));
static_assert(xte::width<long> == (std::numeric_limits<long>::digits + std::numeric_limits<long>::is_signed));
static_assert(xte::width<unsigned long long> == (std::numeric_limits<unsigned long long>::digits + std::numeric_limits<unsigned long long>::is_signed));
static_assert(xte::width<long long> == (std::numeric_limits<long long>::digits + std::numeric_limits<long long>::is_signed));
