#include <xte/trait/is_unsigned.hpp>

static_assert(xte::is_unsigned<unsigned char>);
static_assert(xte::is_unsigned<unsigned short>);
static_assert(xte::is_unsigned<unsigned int>);
static_assert(xte::is_unsigned<unsigned long>);
static_assert(xte::is_unsigned<unsigned long long>);
static_assert(!xte::is_unsigned<signed char>);
static_assert(!xte::is_unsigned<short>);
static_assert(!xte::is_unsigned<int>);
static_assert(!xte::is_unsigned<long>);
static_assert(!xte::is_unsigned<long long>);

static_assert(xte::is_unsigned<const unsigned char>);
static_assert(xte::is_unsigned<const unsigned short>);
static_assert(xte::is_unsigned<const unsigned int>);
static_assert(xte::is_unsigned<const unsigned long>);
static_assert(xte::is_unsigned<const unsigned long long>);
static_assert(!xte::is_unsigned<const signed char>);
static_assert(!xte::is_unsigned<const short>);
static_assert(!xte::is_unsigned<const int>);
static_assert(!xte::is_unsigned<const long>);
static_assert(!xte::is_unsigned<const long long>);

static_assert(xte::is_unsigned<volatile unsigned char>);
static_assert(xte::is_unsigned<volatile unsigned short>);
static_assert(xte::is_unsigned<volatile unsigned int>);
static_assert(xte::is_unsigned<volatile unsigned long>);
static_assert(xte::is_unsigned<volatile unsigned long long>);
static_assert(!xte::is_unsigned<volatile signed char>);
static_assert(!xte::is_unsigned<volatile short>);
static_assert(!xte::is_unsigned<volatile int>);
static_assert(!xte::is_unsigned<volatile long>);
static_assert(!xte::is_unsigned<volatile long long>);

static_assert(xte::is_unsigned<volatile const unsigned char>);
static_assert(xte::is_unsigned<volatile const unsigned short>);
static_assert(xte::is_unsigned<volatile const unsigned int>);
static_assert(xte::is_unsigned<volatile const unsigned long>);
static_assert(xte::is_unsigned<volatile const unsigned long long>);
static_assert(!xte::is_unsigned<volatile const signed char>);
static_assert(!xte::is_unsigned<volatile const short>);
static_assert(!xte::is_unsigned<volatile const int>);
static_assert(!xte::is_unsigned<volatile const long>);
static_assert(!xte::is_unsigned<volatile const long long>);

static_assert(!xte::is_unsigned<char>);
static_assert(!xte::is_unsigned<void>);
static_assert(!xte::is_unsigned<int&>);
static_assert(!xte::is_unsigned<int&&>);
static_assert(!xte::is_unsigned<char***&&>);
static_assert(!xte::is_unsigned<int(decltype([] {})::*)(...) const volatile && noexcept>);
