# [xieite](../../xieite.md)\:\:[literals](../../literals.md)\:\:numbers
Defined in header [<xieite/literals/numbers.hpp>](../../../include/xieite/literals/numbers.hpp)

&nbsp;

## Description
A namespace of literals for converting numeric literals to specific integer or floating point types.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr signed int operator""_i(unsigned long long int value) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr signed int operator""_i(long double value) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr unsigned int operator""_u(unsigned long long int value) noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr unsigned int operator""_u(long double value) noexcept;
```
#### 5)
```cpp
[[nodiscard]] constexpr signed long int operator""_il(unsigned long long int value) noexcept;
```
#### 6)
```cpp
[[nodiscard]] constexpr signed long int operator""_il(long double value) noexcept;
```
#### 7)
```cpp
[[nodiscard]] constexpr unsigned long int operator""_ul(unsigned long long int value) noexcept;
```
#### 8)
```cpp
[[nodiscard]] constexpr unsigned long int operator""_ul(long double value) noexcept;
```
#### 9)
```cpp
[[nodiscard]] constexpr signed long long int operator""_ill(unsigned long long int value) noexcept;
```
#### 10)
```cpp
[[nodiscard]] constexpr signed long long int operator""_ill(long double value) noexcept;
```
#### 11)
```cpp
[[nodiscard]] constexpr unsigned long long int operator""_ull(unsigned long long int value) noexcept;
```
#### 12)
```cpp
[[nodiscard]] constexpr unsigned long long int operator""_ull(long double value) noexcept;
```
#### 13)
```cpp
[[nodiscard]] constexpr signed short int operator""_is(unsigned long long int value) noexcept;
```
#### 14)
```cpp
[[nodiscard]] constexpr signed short int operator""_is(long double value) noexcept;
```
#### 15)
```cpp
[[nodiscard]] constexpr unsigned short int operator""_us(unsigned long long int value) noexcept;
```
#### 16)
```cpp
[[nodiscard]] constexpr unsigned short int operator""_us(long double value) noexcept;
```
#### 17)
```cpp
[[nodiscard]] constexpr bool operator""_b(unsigned long long int value) noexcept;
```
#### 18)
```cpp
[[nodiscard]] constexpr bool operator""_b(long double value) noexcept;
```
#### 19)
```cpp
[[nodiscard]] constexpr char operator""_c(unsigned long long int value) noexcept;
```
#### 20)
```cpp
[[nodiscard]] constexpr char operator""_c(long double value) noexcept;
```
#### 21)
```cpp
[[nodiscard]] constexpr signed char operator""_ci(unsigned long long int value) noexcept;
```
#### 22)
```cpp
[[nodiscard]] constexpr signed char operator""_ci(long double value) noexcept;
```
#### 23)
```cpp
[[nodiscard]] constexpr unsigned char operator""_cu(unsigned long long int value) noexcept;
```
#### 24)
```cpp
[[nodiscard]] constexpr unsigned char operator""_cu(long double value) noexcept;
```
#### 25)
```cpp
[[nodiscard]] constexpr wchar_t operator""_cw(unsigned long long int value) noexcept;
```
#### 26)
```cpp
[[nodiscard]] constexpr wchar_t operator""_cw(long double value) noexcept;
```
#### 27)
```cpp
[[nodiscard]] constexpr char8_t operator""_c8(unsigned long long int value) noexcept;
```
#### 28)
```cpp
[[nodiscard]] constexpr char8_t operator""_c8(long double value) noexcept;
```
#### 29)
```cpp
[[nodiscard]] constexpr char16_t operator""_c16(unsigned long long int value) noexcept;
```
#### 30)
```cpp
[[nodiscard]] constexpr char16_t operator""_c16(long double value) noexcept;
```
#### 31)
```cpp
[[nodiscard]] constexpr char32_t operator""_c32(unsigned long long int value) noexcept;
```
#### 32)
```cpp
[[nodiscard]] constexpr char32_t operator""_c32(long double value) noexcept;
```
#### 33)
```cpp
[[nodiscard]] constexpr std::int8_t operator""_i8(unsigned long long int value) noexcept;
```
#### 34)
```cpp
[[nodiscard]] constexpr std::int8_t operator""_i8(long double value) noexcept;
```
#### 35)
```cpp
[[nodiscard]] constexpr std::uint8_t operator""_u8(unsigned long long int value) noexcept;
```
#### 36)
```cpp
[[nodiscard]] constexpr std::uint8_t operator""_u8(long double value) noexcept;
```
#### 37)
```cpp
[[nodiscard]] constexpr std::int_fast8_t operator""_i8f(unsigned long long int value) noexcept;
```
#### 38)
```cpp
[[nodiscard]] constexpr std::int_fast8_t operator""_i8f(long double value) noexcept;
```
#### 39)
```cpp
[[nodiscard]] constexpr std::uint_fast8_t operator""_u8f(unsigned long long int value) noexcept;
```
#### 40)
```cpp
[[nodiscard]] constexpr std::uint_fast8_t operator""_u8f(long double value) noexcept;
```
#### 41)
```cpp
[[nodiscard]] constexpr std::int_least8_t operator""_i8l(unsigned long long int value) noexcept;
```
#### 42)
```cpp
[[nodiscard]] constexpr std::int_least8_t operator""_i8l(long double value) noexcept;
```
#### 43)
```cpp
[[nodiscard]] constexpr std::uint_least8_t operator""_u8l(unsigned long long int value) noexcept;
```
#### 44)
```cpp
[[nodiscard]] constexpr std::uint_least8_t operator""_u8l(long double value) noexcept;
```
#### 45)
```cpp
[[nodiscard]] constexpr std::int16_t operator""_i16(unsigned long long int value) noexcept;
```
#### 46)
```cpp
[[nodiscard]] constexpr std::int16_t operator""_i16(long double value) noexcept;
```
#### 47)
```cpp
[[nodiscard]] constexpr std::uint16_t operator""_u16(unsigned long long int value) noexcept;
```
#### 48)
```cpp
[[nodiscard]] constexpr std::uint16_t operator""_u16(long double value) noexcept;
```
#### 49)
```cpp
[[nodiscard]] constexpr std::int_fast16_t operator""_i16f(unsigned long long int value) noexcept;
```
#### 50)
```cpp
[[nodiscard]] constexpr std::int_fast16_t operator""_i16f(long double value) noexcept;
```
#### 51)
```cpp
[[nodiscard]] constexpr std::uint_fast16_t operator""_u16f(unsigned long long int value) noexcept;
```
#### 52)
```cpp
[[nodiscard]] constexpr std::uint_fast16_t operator""_u16f(long double value) noexcept;
```
#### 53)
```cpp
[[nodiscard]] constexpr std::int_least16_t operator""_i16l(unsigned long long int value) noexcept;
```
#### 54)
```cpp
[[nodiscard]] constexpr std::int_least16_t operator""_i16l(long double value) noexcept;
```
#### 55)
```cpp
[[nodiscard]] constexpr std::uint_least16_t operator""_u16l(unsigned long long int value) noexcept;
```
#### 56)
```cpp
[[nodiscard]] constexpr std::uint_least16_t operator""_u16l(long double value) noexcept;
```
#### 57)
```cpp
[[nodiscard]] constexpr std::int32_t operator""_i32(unsigned long long int value) noexcept;
```
#### 58)
```cpp
[[nodiscard]] constexpr std::int32_t operator""_i32(long double value) noexcept;
```
#### 59)
```cpp
[[nodiscard]] constexpr std::uint32_t operator""_u32(unsigned long long int value) noexcept;
```
#### 60)
```cpp
[[nodiscard]] constexpr std::uint32_t operator""_u32(long double value) noexcept;
```
#### 61)
```cpp
[[nodiscard]] constexpr std::int_fast32_t operator""_i32f(unsigned long long int value) noexcept;
```
#### 62)
```cpp
[[nodiscard]] constexpr std::int_fast32_t operator""_i32f(long double value) noexcept;
```
#### 63)
```cpp
[[nodiscard]] constexpr std::uint_fast32_t operator""_u32f(unsigned long long int value) noexcept;
```
#### 64)
```cpp
[[nodiscard]] constexpr std::uint_fast32_t operator""_u32f(long double value) noexcept;
```
#### 65)
```cpp
[[nodiscard]] constexpr std::int_least32_t operator""_i32l(unsigned long long int value) noexcept;
```
#### 66)
```cpp
[[nodiscard]] constexpr std::int_least32_t operator""_i32l(long double value) noexcept;
```
#### 67)
```cpp
[[nodiscard]] constexpr std::uint_least32_t operator""_u32l(unsigned long long int value) noexcept;
```
#### 68)
```cpp
[[nodiscard]] constexpr std::uint_least32_t operator""_u32l(long double value) noexcept;
```
#### 69)
```cpp
[[nodiscard]] constexpr std::int64_t operator""_i64(unsigned long long int value) noexcept;
```
#### 70)
```cpp
[[nodiscard]] constexpr std::int64_t operator""_i64(long double value) noexcept;
```
#### 71)
```cpp
[[nodiscard]] constexpr std::uint64_t operator""_u64(unsigned long long int value) noexcept;
```
#### 72)
```cpp
[[nodiscard]] constexpr std::uint64_t operator""_u64(long double value) noexcept;
```
#### 73)
```cpp
[[nodiscard]] constexpr std::int_fast64_t operator""_i64f(unsigned long long int value) noexcept;
```
#### 74)
```cpp
[[nodiscard]] constexpr std::int_fast64_t operator""_i64f(long double value) noexcept;
```
#### 75)
```cpp
[[nodiscard]] constexpr std::uint_fast64_t operator""_u64f(unsigned long long int value) noexcept;
```
#### 76)
```cpp
[[nodiscard]] constexpr std::uint_fast64_t operator""_u64f(long double value) noexcept;
```
#### 77)
```cpp
[[nodiscard]] constexpr std::int_least64_t operator""_i64l(unsigned long long int value) noexcept;
```
#### 78)
```cpp
[[nodiscard]] constexpr std::int_least64_t operator""_i64l(long double value) noexcept;
```
#### 79)
```cpp
[[nodiscard]] constexpr std::uint_least64_t operator""_u64l(unsigned long long int value) noexcept;
```
#### 80)
```cpp
[[nodiscard]] constexpr std::uint_least64_t operator""_u64l(long double value) noexcept;
```
#### 81)
```cpp
[[nodiscard]] constexpr xieite::math::Signed128 operator""_i128(unsigned long long int value) noexcept;
```
#### 82)
```cpp
[[nodiscard]] constexpr xieite::math::Signed128 operator""_i128(long double value) noexcept;
```
#### 83)
```cpp
[[nodiscard]] constexpr xieite::math::Unsigned128 operator""_u128(unsigned long long int value) noexcept;
```
#### 84)
```cpp
[[nodiscard]] constexpr xieite::math::Unsigned128 operator""_u128(long double value) noexcept;
```
#### 85)
```cpp
[[nodiscard]] constexpr std::intmax_t operator""_imax(unsigned long long int value) noexcept;
```
#### 86)
```cpp
[[nodiscard]] constexpr std::intmax_t operator""_imax(long double value) noexcept;
```
#### 87)
```cpp
[[nodiscard]] constexpr std::uintmax_t operator""_umax(unsigned long long int value) noexcept;
```
#### 88)
```cpp
[[nodiscard]] constexpr std::uintmax_t operator""_umax(long double value) noexcept;
```
#### 89)
```cpp
[[nodiscard]] constexpr std::max_align_t operator""_amax(unsigned long long int value) noexcept;
```
#### 90)
```cpp
[[nodiscard]] constexpr std::max_align_t operator""_amax(long double value) noexcept;
```
#### 91)
```cpp
[[nodiscard]] constexpr std::intptr_t operator""_iptr(unsigned long long int value) noexcept;
```
#### 92)
```cpp
[[nodiscard]] constexpr std::intptr_t operator""_iptr(long double value) noexcept;
```
#### 93)
```cpp
[[nodiscard]] constexpr std::uintptr_t operator""_uptr(unsigned long long int value) noexcept;
```
#### 94)
```cpp
[[nodiscard]] constexpr std::uintptr_t operator""_uptr(long double value) noexcept;
```
#### 95)
```cpp
[[nodiscard]] constexpr std::ptrdiff_t operator""_dptr(unsigned long long int value) noexcept;
```
#### 96)
```cpp
[[nodiscard]] constexpr std::ptrdiff_t operator""_dptr(long double value) noexcept;
```
#### 97)
```cpp
[[nodiscard]] constexpr xieite::math::SignedSize operator""_iz(unsigned long long int value) noexcept;
```
#### 98)
```cpp
[[nodiscard]] constexpr xieite::math::SignedSize operator""_iz(long double value) noexcept;
```
#### 99)
```cpp
[[nodiscard]] constexpr std::size_t operator""_uz(unsigned long long int value) noexcept;
```
#### 100)
```cpp
[[nodiscard]] constexpr std::size_t operator""_uz(long double value) noexcept;
```
#### 101)
```cpp
[[nodiscard]] constexpr float operator""_f(unsigned long long int value) noexcept;
```
#### 102)
```cpp
[[nodiscard]] constexpr float operator""_f(long double value) noexcept;
```
#### 103)
```cpp
[[nodiscard]] constexpr std::float16_t operator""_f16(unsigned long long int value) noexcept;
```
#### 104)
```cpp
[[nodiscard]] constexpr std::float16_t operator""_f16(long double value) noexcept;
```
#### 105)
```cpp
[[nodiscard]] constexpr std::bfloat16_t operator""_f16b(unsigned long long int value) noexcept;
```
#### 106)
```cpp
[[nodiscard]] constexpr std::bfloat16_t operator""_f16b(long double value) noexcept;
```
#### 107)
```cpp
[[nodiscard]] constexpr std::float32_t operator""_f32(unsigned long long int value) noexcept;
```
#### 108)
```cpp
[[nodiscard]] constexpr std::float32_t operator""_f32(long double value) noexcept;
```
#### 109)
```cpp
[[nodiscard]] constexpr std::float64_t operator""_f64(unsigned long long int value) noexcept;
```
#### 110)
```cpp
[[nodiscard]] constexpr std::float64_t operator""_f64(long double value) noexcept;
```
#### 111)
```cpp
[[nodiscard]] constexpr std::float128_t operator""_f128(unsigned long long int value) noexcept;
```
#### 112)
```cpp
[[nodiscard]] constexpr std::float128_t operator""_f128(long double value) noexcept;
```
#### 113)
```cpp
[[nodiscard]] constexpr double operator""_d(unsigned long long int value) noexcept;
```
#### 114)
```cpp
[[nodiscard]] constexpr double operator""_d(long double value) noexcept;
```
#### 115)
```cpp
[[nodiscard]] constexpr long double operator""_dl(unsigned long long int value) noexcept;
```
#### 116)
```cpp
[[nodiscard]] constexpr long double operator""_dl(long double value) noexcept;
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
