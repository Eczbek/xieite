#include <xte/trait/is_signed_int.hpp>

static_assert(!xte::is_signed_int<unsigned char>);
static_assert(!xte::is_signed_int<unsigned short>);
static_assert(!xte::is_signed_int<unsigned int>);
static_assert(!xte::is_signed_int<unsigned long>);
static_assert(!xte::is_signed_int<unsigned long long>);
static_assert(xte::is_signed_int<signed char>);
static_assert(xte::is_signed_int<short>);
static_assert(xte::is_signed_int<int>);
static_assert(xte::is_signed_int<long>);
static_assert(xte::is_signed_int<long long>);

static_assert(!xte::is_signed_int<const unsigned char>);
static_assert(!xte::is_signed_int<const unsigned short>);
static_assert(!xte::is_signed_int<const unsigned int>);
static_assert(!xte::is_signed_int<const unsigned long>);
static_assert(!xte::is_signed_int<const unsigned long long>);
static_assert(xte::is_signed_int<const signed char>);
static_assert(xte::is_signed_int<const short>);
static_assert(xte::is_signed_int<const int>);
static_assert(xte::is_signed_int<const long>);
static_assert(xte::is_signed_int<const long long>);

static_assert(!xte::is_signed_int<volatile unsigned char>);
static_assert(!xte::is_signed_int<volatile unsigned short>);
static_assert(!xte::is_signed_int<volatile unsigned int>);
static_assert(!xte::is_signed_int<volatile unsigned long>);
static_assert(!xte::is_signed_int<volatile unsigned long long>);
static_assert(xte::is_signed_int<volatile signed char>);
static_assert(xte::is_signed_int<volatile short>);
static_assert(xte::is_signed_int<volatile int>);
static_assert(xte::is_signed_int<volatile long>);
static_assert(xte::is_signed_int<volatile long long>);

static_assert(!xte::is_signed_int<volatile const unsigned char>);
static_assert(!xte::is_signed_int<volatile const unsigned short>);
static_assert(!xte::is_signed_int<volatile const unsigned int>);
static_assert(!xte::is_signed_int<volatile const unsigned long>);
static_assert(!xte::is_signed_int<volatile const unsigned long long>);
static_assert(xte::is_signed_int<volatile const signed char>);
static_assert(xte::is_signed_int<volatile const short>);
static_assert(xte::is_signed_int<volatile const int>);
static_assert(xte::is_signed_int<volatile const long>);
static_assert(xte::is_signed_int<volatile const long long>);

static_assert(!xte::is_signed_int<bool>);
static_assert(!xte::is_signed_int<void>);
static_assert(!xte::is_signed_int<int&>);
static_assert(!xte::is_signed_int<int&&>);
static_assert(!xte::is_signed_int<char***&&>);
static_assert(!xte::is_signed_int<int(decltype([]{})::*)(...) const volatile&& noexcept>);
