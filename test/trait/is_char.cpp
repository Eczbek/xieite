#include <xte/trait/is_char.hpp>

static_assert(xte::is_char<char>);
static_assert(xte::is_char<wchar_t>);
static_assert(xte::is_char<char8_t>);
static_assert(xte::is_char<char16_t>);
static_assert(xte::is_char<char32_t>);

static_assert(!xte::is_char<unsigned char>);
static_assert(!xte::is_char<signed char>);
