# [xieite](../../xieite.md)\:\:[literals](../../literals.md)\:\:numbers
Defined in fragment [xieite:literals.numbers](../../../src/literals/numbers.cpp)

&nbsp;

## Description
A namespace of literals for converting numeric literals to specific integer or floating point types.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr auto operator""_i(unsigned long long int value) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr auto operator""_i(long double value) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr auto operator""_u(unsigned long long int value) noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr auto operator""_u(long double value) noexcept;
```
#### 5)
```cpp
[[nodiscard]] constexpr auto operator""_il(unsigned long long int value) noexcept;
```
#### 6)
```cpp
[[nodiscard]] constexpr auto operator""_il(long double value) noexcept;
```
#### 7)
```cpp
[[nodiscard]] constexpr auto operator""_ul(unsigned long long int value) noexcept;
```
#### 8)
```cpp
[[nodiscard]] constexpr auto operator""_ul(long double value) noexcept;
```
#### 9)
```cpp
[[nodiscard]] constexpr auto operator""_ill(unsigned long long int value) noexcept;
```
#### 10)
```cpp
[[nodiscard]] constexpr auto operator""_ill(long double value) noexcept;
```
#### 11)
```cpp
[[nodiscard]] constexpr auto operator""_ull(unsigned long long int value) noexcept;
```
#### 12)
```cpp
[[nodiscard]] constexpr auto operator""_ull(long double value) noexcept;
```
#### 13)
```cpp
[[nodiscard]] constexpr auto operator""_is(unsigned long long int value) noexcept;
```
#### 14)
```cpp
[[nodiscard]] constexpr auto operator""_is(long double value) noexcept;
```
#### 15)
```cpp
[[nodiscard]] constexpr auto operator""_us(unsigned long long int value) noexcept;
```
#### 16)
```cpp
[[nodiscard]] constexpr auto operator""_us(long double value) noexcept;
```
#### 17)
```cpp
[[nodiscard]] constexpr auto operator""_b(unsigned long long int value) noexcept;
```
#### 18)
```cpp
[[nodiscard]] constexpr auto operator""_b(long double value) noexcept;
```
#### 19)
```cpp
[[nodiscard]] constexpr auto operator""_c(unsigned long long int value) noexcept;
```
#### 20)
```cpp
[[nodiscard]] constexpr auto operator""_c(long double value) noexcept;
```
#### 21)
```cpp
[[nodiscard]] constexpr auto operator""_ic(unsigned long long int value) noexcept;
```
#### 22)
```cpp
[[nodiscard]] constexpr auto operator""_ic(long double value) noexcept;
```
#### 23)
```cpp
[[nodiscard]] constexpr auto operator""_uc(unsigned long long int value) noexcept;
```
#### 24)
```cpp
[[nodiscard]] constexpr auto operator""_uc(long double value) noexcept;
```
#### 25)
```cpp
[[nodiscard]] constexpr auto operator""_cw(unsigned long long int value) noexcept;
```
#### 26)
```cpp
[[nodiscard]] constexpr auto operator""_cw(long double value) noexcept;
```
#### 27)
```cpp
[[nodiscard]] constexpr auto operator""_c8(unsigned long long int value) noexcept;
```
#### 28)
```cpp
[[nodiscard]] constexpr auto operator""_c8(long double value) noexcept;
```
#### 29)
```cpp
[[nodiscard]] constexpr auto operator""_c16(unsigned long long int value) noexcept;
```
#### 30)
```cpp
[[nodiscard]] constexpr auto operator""_c16(long double value) noexcept;
```
#### 31)
```cpp
[[nodiscard]] constexpr auto operator""_c32(unsigned long long int value) noexcept;
```
#### 32)
```cpp
[[nodiscard]] constexpr auto operator""_c32(long double value) noexcept;
```
#### 33)
```cpp
#if XIEITE_FEATURE_UNSIGNED_8
[[nodiscard]] constexpr auto operator""_u8(unsigned long long int value) noexcept;
#endif
```
#### 34)
```cpp
#if XIEITE_FEATURE_UNSIGNED_8
[[nodiscard]] constexpr auto operator""_u8(long double value) noexcept;
#endif
```
#### 35)
```cpp
#if XIEITE_FEATURE_SIGNED_8
[[nodiscard]] constexpr auto operator""_i8(unsigned long long int value) noexcept;
#endif
```
#### 36)
```cpp
#if XIEITE_FEATURE_SIGNED_8
[[nodiscard]] constexpr auto operator""_i8(long double value) noexcept;
#endif
```
#### 37)
```cpp
[[nodiscard]] constexpr auto operator""_u8f(unsigned long long int value) noexcept;
```
#### 38)
```cpp
[[nodiscard]] constexpr auto operator""_u8f(long double value) noexcept;
```
#### 39)
```cpp
[[nodiscard]] constexpr auto operator""_i8f(unsigned long long int value) noexcept;
```
#### 40)
```cpp
[[nodiscard]] constexpr auto operator""_i8f(long double value) noexcept;
```
#### 41)
```cpp
[[nodiscard]] constexpr auto operator""_u8l(unsigned long long int value) noexcept;
```
#### 42)
```cpp
[[nodiscard]] constexpr auto operator""_u8l(long double value) noexcept;
```
#### 43)
```cpp
[[nodiscard]] constexpr auto operator""_i8l(unsigned long long int value) noexcept;
```
#### 44)
```cpp
[[nodiscard]] constexpr auto operator""_i8l(long double value) noexcept;
```
#### 45)
```cpp
#if XIEITE_FEATURE_UNSIGNED_16
[[nodiscard]] constexpr auto operator""_u16(unsigned long long int value) noexcept;
#endif
```
#### 46)
```cpp
#if XIEITE_FEATURE_UNSIGNED_16
[[nodiscard]] constexpr auto operator""_u16(long double value) noexcept;
#endif
```
#### 47)
```cpp
#if XIEITE_FEATURE_SIGNED_16
[[nodiscard]] constexpr auto operator""_i16(unsigned long long int value) noexcept;
#endif
```
#### 48)
```cpp
#if XIEITE_FEATURE_SIGNED_16
[[nodiscard]] constexpr auto operator""_i16(long double value) noexcept;
#endif
```
#### 49)
```cpp
[[nodiscard]] constexpr auto operator""_u16f(unsigned long long int value) noexcept;
```
#### 50)
```cpp
[[nodiscard]] constexpr auto operator""_u16f(long double value) noexcept;
```
#### 51)
```cpp
[[nodiscard]] constexpr auto operator""_i16f(unsigned long long int value) noexcept;
```
#### 52)
```cpp
[[nodiscard]] constexpr auto operator""_i16f(long double value) noexcept;
```
#### 53)
```cpp
[[nodiscard]] constexpr auto operator""_u16l(unsigned long long int value) noexcept;
```
#### 54)
```cpp
[[nodiscard]] constexpr auto operator""_u16l(long double value) noexcept;
```
#### 55)
```cpp
[[nodiscard]] constexpr auto operator""_i16l(unsigned long long int value) noexcept;
```
#### 56)
```cpp
[[nodiscard]] constexpr auto operator""_i16l(long double value) noexcept;
```
#### 57)
```cpp
#if XIEITE_FEATURE_UNSIGNED_32
[[nodiscard]] constexpr auto operator""_u32(unsigned long long int value) noexcept;
#endif
```
#### 58)
```cpp
#if XIEITE_FEATURE_UNSIGNED_32
[[nodiscard]] constexpr auto operator""_u32(long double value) noexcept;
#endif
```
#### 59)
```cpp
#if XIEITE_FEATURE_SIGNED_32
[[nodiscard]] constexpr auto operator""_i32(unsigned long long int value) noexcept;
#endif
```
#### 60)
```cpp
#if XIEITE_FEATURE_SIGNED_32
[[nodiscard]] constexpr auto operator""_i32(long double value) noexcept;
#endif
```
#### 61)
```cpp
[[nodiscard]] constexpr auto operator""_u32f(unsigned long long int value) noexcept;
```
#### 62)
```cpp
[[nodiscard]] constexpr auto operator""_u32f(long double value) noexcept;
```
#### 63)
```cpp
[[nodiscard]] constexpr auto operator""_i32f(unsigned long long int value) noexcept;
```
#### 64)
```cpp
[[nodiscard]] constexpr auto operator""_i32f(long double value) noexcept;
```
#### 65)
```cpp
[[nodiscard]] constexpr auto operator""_u32l(unsigned long long int value) noexcept;
```
#### 66)
```cpp
[[nodiscard]] constexpr auto operator""_u32l(long double value) noexcept;
```
#### 67)
```cpp
[[nodiscard]] constexpr auto operator""_i32l(unsigned long long int value) noexcept;
```
#### 68)
```cpp
[[nodiscard]] constexpr auto operator""_i32l(long double value) noexcept;
```
#### 69)
```cpp
#if XIEITE_FEATURE_UNSIGNED_64
[[nodiscard]] constexpr auto operator""_u64(unsigned long long int value) noexcept;
#endif
```
#### 70)
```cpp
#if XIEITE_FEATURE_UNSIGNED_64
[[nodiscard]] constexpr auto operator""_u64(long double value) noexcept;
#endif
```
#### 71)
```cpp
#if XIEITE_FEATURE_SIGNED_64
[[nodiscard]] constexpr auto operator""_i64(unsigned long long int value) noexcept;
#endif
```
#### 72)
```cpp
#if XIEITE_FEATURE_SIGNED_64
[[nodiscard]] constexpr auto operator""_i64(long double value) noexcept;
#endif
```
#### 73)
```cpp
[[nodiscard]] constexpr auto operator""_u64f(unsigned long long int value) noexcept;
```
#### 74)
```cpp
[[nodiscard]] constexpr auto operator""_u64f(long double value) noexcept;
```
#### 75)
```cpp
[[nodiscard]] constexpr auto operator""_i64f(unsigned long long int value) noexcept;
```
#### 76)
```cpp
[[nodiscard]] constexpr auto operator""_i64f(long double value) noexcept;
```
#### 77)
```cpp
[[nodiscard]] constexpr auto operator""_u64l(unsigned long long int value) noexcept;
```
#### 78)
```cpp
[[nodiscard]] constexpr auto operator""_u64l(long double value) noexcept;
```
#### 79)
```cpp
[[nodiscard]] constexpr auto operator""_i64l(unsigned long long int value) noexcept;
```
#### 80)
```cpp
[[nodiscard]] constexpr auto operator""_i64l(long double value) noexcept;
```
#### 81)
```cpp
#if XIEITE_FEATURE_UNSIGNED_128
[[nodiscard]] constexpr auto operator""_u128(unsigned long long int value) noexcept;
#endif
```
#### 82)
```cpp
#if XIEITE_FEATURE_UNSIGNED_128
[[nodiscard]] constexpr auto operator""_u128(long double value) noexcept;
#endif
```
#### 83)
```cpp
#if XIEITE_FEATURE_SIGNED_128
[[nodiscard]] constexpr auto operator""_i128(unsigned long long int value) noexcept;
#endif
```
#### 84)
```cpp
#if XIEITE_FEATURE_SIGNED_128
[[nodiscard]] constexpr auto operator""_i128(long double value) noexcept;
#endif
```
#### 85)
```cpp
[[nodiscard]] constexpr auto operator""_um(unsigned long long int value) noexcept;
```
#### 86)
```cpp
[[nodiscard]] constexpr auto operator""_um(long double value) noexcept;
```
#### 87)
```cpp
[[nodiscard]] constexpr auto operator""_im(unsigned long long int value) noexcept;
```
#### 88)
```cpp
[[nodiscard]] constexpr auto operator""_im(long double value) noexcept;
```
#### 89)
```cpp
[[nodiscard]] constexpr auto operator""_up(unsigned long long int value) noexcept;
```
#### 90)
```cpp
[[nodiscard]] constexpr auto operator""_up(long double value) noexcept;
```
#### 91)
```cpp
[[nodiscard]] constexpr auto operator""_ip(unsigned long long int value) noexcept;
```
#### 92)
```cpp
[[nodiscard]] constexpr auto operator""_ip(long double value) noexcept;
```
#### 93)
```cpp
[[nodiscard]] constexpr auto operator""_pd(unsigned long long int value) noexcept;
```
#### 94)
```cpp
[[nodiscard]] constexpr auto operator""_pd(long double value) noexcept;
```
#### 95)
```cpp
[[nodiscard]] constexpr auto operator""_uz(unsigned long long int value) noexcept;
```
#### 96)
```cpp
[[nodiscard]] constexpr auto operator""_uz(long double value) noexcept;
```
#### 97)
```cpp
[[nodiscard]] constexpr auto operator""_iz(unsigned long long int value) noexcept;
```
#### 98)
```cpp
[[nodiscard]] constexpr auto operator""_iz(long double value) noexcept;
```
#### 99)
```cpp
[[nodiscard]] constexpr auto operator""_f(unsigned long long int value) noexcept;
```
#### 100)
```cpp
[[nodiscard]] constexpr auto operator""_f(long double value) noexcept;
```
#### 101)
```cpp
[[nodiscard]] constexpr auto operator""_d(unsigned long long int value) noexcept;
```
#### 102)
```cpp
[[nodiscard]] constexpr auto operator""_d(long double value) noexcept;
```
#### 103)
```cpp
[[nodiscard]] constexpr auto operator""_dl(unsigned long long int value) noexcept;
```
#### 104)
```cpp
[[nodiscard]] constexpr auto operator""_dl(long double value) noexcept;
```
#### 105)
```cpp
#if XIEITE_FEATURE_FLOAT_16
[[nodiscard]] constexpr auto operator""_f16(unsigned long long int value) noexcept;
#endif
```
#### 106)
```cpp
#if XIEITE_FEATURE_FLOAT_16
[[nodiscard]] constexpr auto operator""_f16(long double value) noexcept;
#endif
```
#### 107)
```cpp
#if XIEITE_FEATURE_FLOAT_32
[[nodiscard]] constexpr auto operator""_f32(unsigned long long int value) noexcept;
#endif
```
#### 108)
```cpp
#if XIEITE_FEATURE_FLOAT_32
[[nodiscard]] constexpr auto operator""_f32(long double value) noexcept;
#endif
```
#### 109)
```cpp
#if XIEITE_FEATURE_FLOAT_64
[[nodiscard]] constexpr auto operator""_f64(unsigned long long int value) noexcept;
#endif
```
#### 110)
```cpp
#if XIEITE_FEATURE_FLOAT_64
[[nodiscard]] constexpr auto operator""_f64(long double value) noexcept;
#endif
```
#### 111)
```cpp
#if XIEITE_FEATURE_FLOAT_128
[[nodiscard]] constexpr auto operator""_f128(unsigned long long int value) noexcept;
#endif
```
#### 112)
```cpp
#if XIEITE_FEATURE_FLOAT_128
[[nodiscard]] constexpr auto operator""_f128(long double value) noexcept;
#endif
```
#### 113)
```cpp
#if XIEITE_FEATURE_FLOAT_BRAIN
[[nodiscard]] constexpr auto operator""_f16b(unsigned long long int value) noexcept;
#endif
```
#### 114)
```cpp
#if XIEITE_FEATURE_FLOAT_BRAIN
[[nodiscard]] constexpr auto operator""_f16b(long double value) noexcept;
#endif
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using namespace xieite::literals::numbers;

    std::println("{}", 23_i);
    std::println("{}", -1_i64);
    std::println("{}", 65_c);
}
```
Output:
```
23
18446744073709551615
A
```
