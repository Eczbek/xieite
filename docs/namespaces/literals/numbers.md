# [xieite](../../xieite.md)\:\:[literals](../../literals.md)\:\:\_numbers
Defined in header [<xieite/literals/numbers.hpp>](../../../include/xieite/literals/numbers.hpp)

&nbsp;

## Description
Literals for converting numeric literals to specific integer or floating point types.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr signed int operator""_i(const unsigned long long int value) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr signed int operator""_i(const long double value) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr unsigned int operator""_u(const unsigned long long int value) noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr unsigned int operator""_u(const long double value) noexcept;
```
#### 5)
```cpp
[[nodiscard]] constexpr signed long int operator""_il(const unsigned long long int value) noexcept;
```
#### 6)
```cpp
[[nodiscard]] constexpr signed long int operator""_il(const long double value) noexcept;
```
#### 7)
```cpp
[[nodiscard]] constexpr unsigned long int operator""_ul(const unsigned long long int value) noexcept;
```
#### 8)
```cpp
[[nodiscard]] constexpr unsigned long int operator""_ul(const long double value) noexcept;
```
#### 9)
```cpp
[[nodiscard]] constexpr signed long long int operator""_ill(const unsigned long long int value) noexcept;
```
#### 10)
```cpp
[[nodiscard]] constexpr signed long long int operator""_ill(const long double value) noexcept;
```
#### 11)
```cpp
[[nodiscard]] constexpr unsigned long long int operator""_ull(const unsigned long long int value) noexcept;
```
#### 12)
```cpp
[[nodiscard]] constexpr unsigned long long int operator""_ull(const long double value) noexcept;
```
#### 13)
```cpp
[[nodiscard]] constexpr signed short int operator""_is(const unsigned long long int value) noexcept;
```
#### 14)
```cpp
[[nodiscard]] constexpr signed short int operator""_is(const long double value) noexcept;
```
#### 15)
```cpp
[[nodiscard]] constexpr unsigned short int operator""_us(const unsigned long long int value) noexcept;
```
#### 16)
```cpp
[[nodiscard]] constexpr unsigned short int operator""_us(const long double value) noexcept;
```
#### 17)
```cpp
[[nodiscard]] constexpr bool operator""_b(const unsigned long long int value) noexcept;
```
#### 18)
```cpp
[[nodiscard]] constexpr bool operator""_b(const long double value) noexcept;
```
#### 19)
```cpp
[[nodiscard]] constexpr char operator""_c(const unsigned long long int value) noexcept;
```
#### 20)
```cpp
[[nodiscard]] constexpr char operator""_c(const long double value) noexcept;
```
#### 21)
```cpp
[[nodiscard]] constexpr signed char operator""_ci(const unsigned long long int value) noexcept;
```
#### 22)
```cpp
[[nodiscard]] constexpr signed char operator""_ci(const long double value) noexcept;
```
#### 23)
```cpp
[[nodiscard]] constexpr unsigned char operator""_cu(const unsigned long long int value) noexcept;
```
#### 24)
```cpp
[[nodiscard]] constexpr unsigned char operator""_cu(const long double value) noexcept;
```
#### 25)
```cpp
[[nodiscard]] constexpr wchar_t operator""_cw(const unsigned long long int value) noexcept;
```
#### 26)
```cpp
[[nodiscard]] constexpr wchar_t operator""_cw(const long double value) noexcept;
```
#### 27)
```cpp
[[nodiscard]] constexpr char8_t operator""_c8(const unsigned long long int value) noexcept;
```
#### 28)
```cpp
[[nodiscard]] constexpr char8_t operator""_c8(const long double value) noexcept;
```
#### 29)
```cpp
[[nodiscard]] constexpr char16_t operator""_c16(const unsigned long long int value) noexcept;
```
#### 30)
```cpp
[[nodiscard]] constexpr char16_t operator""_c16(const long double value) noexcept;
```
#### 31)
```cpp
[[nodiscard]] constexpr char32_t operator""_c32(const unsigned long long int value) noexcept;
```
#### 32)
```cpp
[[nodiscard]] constexpr char32_t operator""_c32(const long double value) noexcept;
```
#### 33)
```cpp
[[nodiscard]] constexpr std::int8_t operator""_i8(const unsigned long long int value) noexcept;
```
#### 34)
```cpp
[[nodiscard]] constexpr std::int8_t operator""_i8(const long double value) noexcept;
```
#### 35)
```cpp
[[nodiscard]] constexpr std::uint8_t operator""_u8(const unsigned long long int value) noexcept;
```
#### 36)
```cpp
[[nodiscard]] constexpr std::uint8_t operator""_u8(const long double value) noexcept;
```
#### 37)
```cpp
[[nodiscard]] constexpr std::int_fast8_t operator""_i8f(const unsigned long long int value) noexcept;
```
#### 38)
```cpp
[[nodiscard]] constexpr std::int_fast8_t operator""_i8f(const long double value) noexcept;
```
#### 39)
```cpp
[[nodiscard]] constexpr std::uint_fast8_t operator""_u8f(const unsigned long long int value) noexcept;
```
#### 40)
```cpp
[[nodiscard]] constexpr std::uint_fast8_t operator""_u8f(const long double value) noexcept;
```
#### 41)
```cpp
[[nodiscard]] constexpr std::int_least8_t operator""_i8l(const unsigned long long int value) noexcept;
```
#### 42)
```cpp
[[nodiscard]] constexpr std::int_least8_t operator""_i8l(const long double value) noexcept;
```
#### 43)
```cpp
[[nodiscard]] constexpr std::uint_least8_t operator""_u8l(const unsigned long long int value) noexcept;
```
#### 44)
```cpp
[[nodiscard]] constexpr std::uint_least8_t operator""_u8l(const long double value) noexcept;
```
#### 45)
```cpp
[[nodiscard]] constexpr std::int16_t operator""_i16(const unsigned long long int value) noexcept;
```
#### 46)
```cpp
[[nodiscard]] constexpr std::int16_t operator""_i16(const long double value) noexcept;
```
#### 47)
```cpp
[[nodiscard]] constexpr std::uint16_t operator""_u16(const unsigned long long int value) noexcept;
```
#### 48)
```cpp
[[nodiscard]] constexpr std::uint16_t operator""_u16(const long double value) noexcept;
```
#### 49)
```cpp
[[nodiscard]] constexpr std::int_fast16_t operator""_i16f(const unsigned long long int value) noexcept;
```
#### 50)
```cpp
[[nodiscard]] constexpr std::int_fast16_t operator""_i16f(const long double value) noexcept;
```
#### 51)
```cpp
[[nodiscard]] constexpr std::uint_fast16_t operator""_u16f(const unsigned long long int value) noexcept;
```
#### 52)
```cpp
[[nodiscard]] constexpr std::uint_fast16_t operator""_u16f(const long double value) noexcept;
```
#### 53)
```cpp
[[nodiscard]] constexpr std::int_least16_t operator""_i16l(const unsigned long long int value) noexcept;
```
#### 54)
```cpp
[[nodiscard]] constexpr std::int_least16_t operator""_i16l(const long double value) noexcept;
```
#### 55)
```cpp
[[nodiscard]] constexpr std::uint_least16_t operator""_u16l(const unsigned long long int value) noexcept;
```
#### 56)
```cpp
[[nodiscard]] constexpr std::uint_least16_t operator""_u16l(const long double value) noexcept;
```
#### 57)
```cpp
[[nodiscard]] constexpr std::int32_t operator""_i32(const unsigned long long int value) noexcept;
```
#### 58)
```cpp
[[nodiscard]] constexpr std::int32_t operator""_i32(const long double value) noexcept;
```
#### 59)
```cpp
[[nodiscard]] constexpr std::uint32_t operator""_u32(const unsigned long long int value) noexcept;
```
#### 60)
```cpp
[[nodiscard]] constexpr std::uint32_t operator""_u32(const long double value) noexcept;
```
#### 61)
```cpp
[[nodiscard]] constexpr std::int_fast32_t operator""_i32f(const unsigned long long int value) noexcept;
```
#### 62)
```cpp
[[nodiscard]] constexpr std::int_fast32_t operator""_i32f(const long double value) noexcept;
```
#### 63)
```cpp
[[nodiscard]] constexpr std::uint_fast32_t operator""_u32f(const unsigned long long int value) noexcept;
```
#### 64)
```cpp
[[nodiscard]] constexpr std::uint_fast32_t operator""_u32f(const long double value) noexcept;
```
#### 65)
```cpp
[[nodiscard]] constexpr std::int_least32_t operator""_i32l(const unsigned long long int value) noexcept;
```
#### 66)
```cpp
[[nodiscard]] constexpr std::int_least32_t operator""_i32l(const long double value) noexcept;
```
#### 67)
```cpp
[[nodiscard]] constexpr std::uint_least32_t operator""_u32l(const unsigned long long int value) noexcept;
```
#### 68)
```cpp
[[nodiscard]] constexpr std::uint_least32_t operator""_u32l(const long double value) noexcept;
```
#### 69)
```cpp
[[nodiscard]] constexpr std::int64_t operator""_i64(const unsigned long long int value) noexcept;
```
#### 70)
```cpp
[[nodiscard]] constexpr std::int64_t operator""_i64(const long double value) noexcept;
```
#### 71)
```cpp
[[nodiscard]] constexpr std::uint64_t operator""_u64(const unsigned long long int value) noexcept;
```
#### 72)
```cpp
[[nodiscard]] constexpr std::uint64_t operator""_u64(const long double value) noexcept;
```
#### 73)
```cpp
[[nodiscard]] constexpr std::int_fast64_t operator""_i64f(const unsigned long long int value) noexcept;
```
#### 74)
```cpp
[[nodiscard]] constexpr std::int_fast64_t operator""_i64f(const long double value) noexcept;
```
#### 75)
```cpp
[[nodiscard]] constexpr std::uint_fast64_t operator""_u64f(const unsigned long long int value) noexcept;
```
#### 76)
```cpp
[[nodiscard]] constexpr std::uint_fast64_t operator""_u64f(const long double value) noexcept;
```
#### 77)
```cpp
[[nodiscard]] constexpr std::int_least64_t operator""_i64l(const unsigned long long int value) noexcept;
```
#### 78)
```cpp
[[nodiscard]] constexpr std::int_least64_t operator""_i64l(const long double value) noexcept;
```
#### 79)
```cpp
[[nodiscard]] constexpr std::uint_least64_t operator""_u64l(const unsigned long long int value) noexcept;
```
#### 80)
```cpp
[[nodiscard]] constexpr std::uint_least64_t operator""_u64l(const long double value) noexcept;
```
#### 81)
```cpp
[[nodiscard]] constexpr xieite::math::Signed128 operator""_i128(const unsigned long long int value) noexcept;
```
#### 82)
```cpp
[[nodiscard]] constexpr xieite::math::Signed128 operator""_i128(const long double value) noexcept;
```
#### 83)
```cpp
[[nodiscard]] constexpr xieite::math::Unsigned128 operator""_u128(const unsigned long long int value) noexcept;
```
#### 84)
```cpp
[[nodiscard]] constexpr xieite::math::Unsigned128 operator""_u128(const long double value) noexcept;
```
#### 85)
```cpp
[[nodiscard]] constexpr std::intmax_t operator""_imax(const unsigned long long int value) noexcept;
```
#### 86)
```cpp
[[nodiscard]] constexpr std::intmax_t operator""_imax(const long double value) noexcept;
```
#### 87)
```cpp
[[nodiscard]] constexpr std::uintmax_t operator""_umax(const unsigned long long int value) noexcept;
```
#### 88)
```cpp
[[nodiscard]] constexpr std::uintmax_t operator""_umax(const long double value) noexcept;
```
#### 89)
```cpp
[[nodiscard]] constexpr std::max_align_t operator""_amax(const unsigned long long int value) noexcept;
```
#### 90)
```cpp
[[nodiscard]] constexpr std::max_align_t operator""_amax(const long double value) noexcept;
```
#### 91)
```cpp
[[nodiscard]] constexpr std::intptr_t operator""_iptr(const unsigned long long int value) noexcept;
```
#### 92)
```cpp
[[nodiscard]] constexpr std::intptr_t operator""_iptr(const long double value) noexcept;
```
#### 93)
```cpp
[[nodiscard]] constexpr std::uintptr_t operator""_uptr(const unsigned long long int value) noexcept;
```
#### 94)
```cpp
[[nodiscard]] constexpr std::uintptr_t operator""_uptr(const long double value) noexcept;
```
#### 95)
```cpp
[[nodiscard]] constexpr std::ptrdiff_t operator""_dptr(const unsigned long long int value) noexcept;
```
#### 96)
```cpp
[[nodiscard]] constexpr std::ptrdiff_t operator""_dptr(const long double value) noexcept;
```
#### 97)
```cpp
[[nodiscard]] constexpr xieite::math::SignedSize operator""_iz(const unsigned long long int value) noexcept;
```
#### 98)
```cpp
[[nodiscard]] constexpr xieite::math::SignedSize operator""_iz(const long double value) noexcept;
```
#### 99)
```cpp
[[nodiscard]] constexpr std::size_t operator""_uz(const unsigned long long int value) noexcept;
```
#### 100)
```cpp
[[nodiscard]] constexpr std::size_t operator""_uz(const long double value) noexcept;
```
#### 101)
```cpp
[[nodiscard]] constexpr float operator""_f(const unsigned long long int value) noexcept;
```
#### 102)
```cpp
[[nodiscard]] constexpr float operator""_f(const long double value) noexcept;
```
#### 103)
```cpp
[[nodiscard]] constexpr std::float16_t operator""_f16(const unsigned long long int value) noexcept;
```
#### 104)
```cpp
[[nodiscard]] constexpr std::float16_t operator""_f16(const long double value) noexcept;
```
#### 105)
```cpp
[[nodiscard]] constexpr std::bfloat16_t operator""_f16b(const unsigned long long int value) noexcept;
```
#### 106)
```cpp
[[nodiscard]] constexpr std::bfloat16_t operator""_f16b(const long double value) noexcept;
```
#### 107)
```cpp
[[nodiscard]] constexpr std::float32_t operator""_f32(const unsigned long long int value) noexcept;
```
#### 108)
```cpp
[[nodiscard]] constexpr std::float32_t operator""_f32(const long double value) noexcept;
```
#### 109)
```cpp
[[nodiscard]] constexpr std::float64_t operator""_f64(const unsigned long long int value) noexcept;
```
#### 110)
```cpp
[[nodiscard]] constexpr std::float64_t operator""_f64(const long double value) noexcept;
```
#### 111)
```cpp
[[nodiscard]] constexpr std::float128_t operator""_f128(const unsigned long long int value) noexcept;
```
#### 112)
```cpp
[[nodiscard]] constexpr std::float128_t operator""_f128(const long double value) noexcept;
```
#### 113)
```cpp
[[nodiscard]] constexpr double operator""_d(const unsigned long long int value) noexcept;
```
#### 114)
```cpp
[[nodiscard]] constexpr double operator""_d(const long double value) noexcept;
```
#### 115)
```cpp
[[nodiscard]] constexpr long double operator""_dl(const unsigned long long int value) noexcept;
```
#### 116)
```cpp
[[nodiscard]] constexpr long double operator""_dl(const long double value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/literals/numbers.hpp"

int main() {
    using namespace xieite::literals::numbers;

    std::println("{}", 23_i);
    std::println("{}", -1_u64);
    std::println("{}", 65_c);
}
```
Output:
```
23
18446744073709551615
A
```
