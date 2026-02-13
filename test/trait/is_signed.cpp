#include <xte/trait/is_signed.hpp>

static_assert(!xte::is_signed<unsigned char>);
static_assert(!xte::is_signed<unsigned short>);
static_assert(!xte::is_signed<unsigned int>);
static_assert(!xte::is_signed<unsigned long>);
static_assert(!xte::is_signed<unsigned long long>);
static_assert(xte::is_signed<signed char>);
static_assert(xte::is_signed<short>);
static_assert(xte::is_signed<int>);
static_assert(xte::is_signed<long>);
static_assert(xte::is_signed<long long>);

static_assert(!xte::is_signed<const unsigned char>);
static_assert(!xte::is_signed<const unsigned short>);
static_assert(!xte::is_signed<const unsigned int>);
static_assert(!xte::is_signed<const unsigned long>);
static_assert(!xte::is_signed<const unsigned long long>);
static_assert(xte::is_signed<const signed char>);
static_assert(xte::is_signed<const short>);
static_assert(xte::is_signed<const int>);
static_assert(xte::is_signed<const long>);
static_assert(xte::is_signed<const long long>);

static_assert(!xte::is_signed<volatile unsigned char>);
static_assert(!xte::is_signed<volatile unsigned short>);
static_assert(!xte::is_signed<volatile unsigned int>);
static_assert(!xte::is_signed<volatile unsigned long>);
static_assert(!xte::is_signed<volatile unsigned long long>);
static_assert(xte::is_signed<volatile signed char>);
static_assert(xte::is_signed<volatile short>);
static_assert(xte::is_signed<volatile int>);
static_assert(xte::is_signed<volatile long>);
static_assert(xte::is_signed<volatile long long>);

static_assert(!xte::is_signed<volatile const unsigned char>);
static_assert(!xte::is_signed<volatile const unsigned short>);
static_assert(!xte::is_signed<volatile const unsigned int>);
static_assert(!xte::is_signed<volatile const unsigned long>);
static_assert(!xte::is_signed<volatile const unsigned long long>);
static_assert(xte::is_signed<volatile const signed char>);
static_assert(xte::is_signed<volatile const short>);
static_assert(xte::is_signed<volatile const int>);
static_assert(xte::is_signed<volatile const long>);
static_assert(xte::is_signed<volatile const long long>);

static_assert(!xte::is_signed<char>);
static_assert(!xte::is_signed<void>);
static_assert(!xte::is_signed<int&>);
static_assert(!xte::is_signed<int&&>);
static_assert(!xte::is_signed<char***&&>);
static_assert(!xte::is_signed<int(decltype([] {})::*)(...) const volatile && noexcept>);
