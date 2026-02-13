#include <xte/trait/is_int.hpp>

static_assert(xte::is_int<unsigned char>);
static_assert(xte::is_int<unsigned short>);
static_assert(xte::is_int<unsigned int>);
static_assert(xte::is_int<unsigned long>);
static_assert(xte::is_int<unsigned long long>);
static_assert(xte::is_int<signed char>);
static_assert(xte::is_int<short>);
static_assert(xte::is_int<int>);
static_assert(xte::is_int<long>);
static_assert(xte::is_int<long long>);

static_assert(xte::is_int<const unsigned char>);
static_assert(xte::is_int<const unsigned short>);
static_assert(xte::is_int<const unsigned int>);
static_assert(xte::is_int<const unsigned long>);
static_assert(xte::is_int<const unsigned long long>);
static_assert(xte::is_int<const signed char>);
static_assert(xte::is_int<const short>);
static_assert(xte::is_int<const int>);
static_assert(xte::is_int<const long>);
static_assert(xte::is_int<const long long>);

static_assert(xte::is_int<volatile unsigned char>);
static_assert(xte::is_int<volatile unsigned short>);
static_assert(xte::is_int<volatile unsigned int>);
static_assert(xte::is_int<volatile unsigned long>);
static_assert(xte::is_int<volatile unsigned long long>);
static_assert(xte::is_int<volatile signed char>);
static_assert(xte::is_int<volatile short>);
static_assert(xte::is_int<volatile int>);
static_assert(xte::is_int<volatile long>);
static_assert(xte::is_int<volatile long long>);

static_assert(xte::is_int<volatile const unsigned char>);
static_assert(xte::is_int<volatile const unsigned short>);
static_assert(xte::is_int<volatile const unsigned int>);
static_assert(xte::is_int<volatile const unsigned long>);
static_assert(xte::is_int<volatile const unsigned long long>);
static_assert(xte::is_int<volatile const signed char>);
static_assert(xte::is_int<volatile const short>);
static_assert(xte::is_int<volatile const int>);
static_assert(xte::is_int<volatile const long>);
static_assert(xte::is_int<volatile const long long>);

static_assert(!xte::is_int<char>);
static_assert(!xte::is_int<void>);
static_assert(!xte::is_int<int&>);
static_assert(!xte::is_int<int&&>);
static_assert(!xte::is_int<char***&&>);
static_assert(!xte::is_int<int(decltype([] {})::*)(...) const volatile && noexcept>);
