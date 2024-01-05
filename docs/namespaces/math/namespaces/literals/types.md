# [xieite](../../../../xieite.md)\:\:[math](../../../../math.md)\:\:[literals](../../literals.md)\:\: \(types\)
Defined in header [<xieite/math/literals/types.hpp>](../../../../../include/xieite/math/literals/types.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::int8_t operator""_i8(const unsigned long long int value) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr std::int8_t operator""_i8(const long double value) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr std::uint8_t operator""_u8(const unsigned long long int value) noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr std::uint8_t operator""_u8(const long double value) noexcept;
```
#### 5)
```cpp
[[nodiscard]] constexpr std::int_fast8_t operator""_i8f(const unsigned long long int value) noexcept;
```
#### 6)
```cpp
[[nodiscard]] constexpr std::int_fast8_t operator""_i8f(const long double value) noexcept;
```
#### 7)
```cpp
[[nodiscard]] constexpr std::uint_fast8_t operator""_u8f(const unsigned long long int value) noexcept;
```
#### 8)
```cpp
[[nodiscard]] constexpr std::uint_fast8_t operator""_u8f(const long double value) noexcept;
```
#### 9)
```cpp
[[nodiscard]] constexpr std::int_least8_t operator""_i8l(const unsigned long long int value) noexcept;
```
#### 10)
```cpp
[[nodiscard]] constexpr std::int_least8_t operator""_i8l(const long double value) noexcept;
```
#### 11)
```cpp
[[nodiscard]] constexpr std::uint_least8_t operator""_u8l(const unsigned long long int value) noexcept;
```
#### 12)
```cpp
[[nodiscard]] constexpr std::uint_least8_t operator""_u8l(const long double value) noexcept;
```
#### 13)
```cpp
[[nodiscard]] constexpr std::int16_t operator""_i16(const unsigned long long int value) noexcept;
```
#### 14)
```cpp
[[nodiscard]] constexpr std::int16_t operator""_i16(const long double value) noexcept;
```
#### 15)
```cpp
[[nodiscard]] constexpr std::uint16_t operator""_u16(const unsigned long long int value) noexcept;
```
#### 16)
```cpp
[[nodiscard]] constexpr std::uint16_t operator""_u16(const long double value) noexcept;
```
#### 17)
```cpp
[[nodiscard]] constexpr std::int_fast16_t operator""_i16f(const unsigned long long int value) noexcept;
```
#### 18)
```cpp
[[nodiscard]] constexpr std::int_fast16_t operator""_i16f(const long double value) noexcept;
```
#### 19)
```cpp
[[nodiscard]] constexpr std::uint_fast16_t operator""_u16f(const unsigned long long int value) noexcept;
```
#### 20)
```cpp
[[nodiscard]] constexpr std::uint_fast16_t operator""_u16f(const long double value) noexcept;
```
#### 21)
```cpp
[[nodiscard]] constexpr std::int_least16_t operator""_i16l(const unsigned long long int value) noexcept;
```
#### 22)
```cpp
[[nodiscard]] constexpr std::int_least16_t operator""_i16l(const long double value) noexcept;
```
#### 23)
```cpp
[[nodiscard]] constexpr std::uint_least16_t operator""_u16l(const unsigned long long int value) noexcept;
```
#### 24)
```cpp
[[nodiscard]] constexpr std::uint_least16_t operator""_u16l(const long double value) noexcept;
```
#### 25)
```cpp
[[nodiscard]] constexpr std::int32_t operator""_i32(const unsigned long long int value) noexcept;
```
#### 26)
```cpp
[[nodiscard]] constexpr std::int32_t operator""_i32(const long double value) noexcept;
```
#### 27)
```cpp
[[nodiscard]] constexpr std::uint32_t operator""_u32(const unsigned long long int value) noexcept;
```
#### 28)
```cpp
[[nodiscard]] constexpr std::uint32_t operator""_u32(const long double value) noexcept;
```
#### 29)
```cpp
[[nodiscard]] constexpr std::int_fast32_t operator""_i32f(const unsigned long long int value) noexcept;
```
#### 30)
```cpp
[[nodiscard]] constexpr std::int_fast32_t operator""_i32f(const long double value) noexcept;
```
#### 31)
```cpp
[[nodiscard]] constexpr std::uint_fast32_t operator""_u32f(const unsigned long long int value) noexcept;
```
#### 32)
```cpp
[[nodiscard]] constexpr std::uint_fast32_t operator""_u32f(const long double value) noexcept;
```
#### 33)
```cpp
[[nodiscard]] constexpr std::int_least32_t operator""_i32l(const unsigned long long int value) noexcept;
```
#### 34)
```cpp
[[nodiscard]] constexpr std::int_least32_t operator""_i32l(const long double value) noexcept;
```
#### 35)
```cpp
[[nodiscard]] constexpr std::uint_least32_t operator""_u32l(const unsigned long long int value) noexcept;
```
#### 36)
```cpp
[[nodiscard]] constexpr std::uint_least32_t operator""_u32l(const long double value) noexcept;
```
#### 37)
```cpp
[[nodiscard]] constexpr std::int64_t operator""_i64(const unsigned long long int value) noexcept;
```
#### 38)
```cpp
[[nodiscard]] constexpr std::int64_t operator""_i64(const long double value) noexcept;
```
#### 39)
```cpp
[[nodiscard]] constexpr std::uint64_t operator""_u64(const unsigned long long int value) noexcept;
```
#### 40)
```cpp
[[nodiscard]] constexpr std::uint64_t operator""_u64(const long double value) noexcept;
```
#### 41)
```cpp
[[nodiscard]] constexpr std::int_fast64_t operator""_i64f(const unsigned long long int value) noexcept;
```
#### 42)
```cpp
[[nodiscard]] constexpr std::int_fast64_t operator""_i64f(const long double value) noexcept;
```
#### 43)
```cpp
[[nodiscard]] constexpr std::uint_fast64_t operator""_u64f(const unsigned long long int value) noexcept;
```
#### 44)
```cpp
[[nodiscard]] constexpr std::uint_fast64_t operator""_u64f(const long double value) noexcept;
```
#### 45)
```cpp
[[nodiscard]] constexpr std::int_least64_t operator""_i64l(const unsigned long long int value) noexcept;
```
#### 46)
```cpp
[[nodiscard]] constexpr std::int_least64_t operator""_i64l(const long double value) noexcept;
```
#### 47)
```cpp
[[nodiscard]] constexpr std::uint_least64_t operator""_u64l(const unsigned long long int value) noexcept;
```
#### 48)
```cpp
[[nodiscard]] constexpr std::uint_least64_t operator""_u64l(const long double value) noexcept;
```
#### 49)
```cpp
[[nodiscard]] constexpr std::intmax_t operator""_imax(const unsigned long long int value) noexcept;
```
#### 50)
```cpp
[[nodiscard]] constexpr std::intmax_t operator""_imax(const long double value) noexcept;
```
#### 51)
```cpp
[[nodiscard]] constexpr std::uintmax_t operator""_umax(const unsigned long long int value) noexcept;
```
#### 52)
```cpp
[[nodiscard]] constexpr std::uintmax_t operator""_umax(const long double value) noexcept;
```
#### 53)
```cpp
[[nodiscard]] constexpr std::max_align_t operator""_amax(const unsigned long long int value) noexcept;
```
#### 54)
```cpp
[[nodiscard]] constexpr std::max_align_t operator""_amax(const long double value) noexcept;
```
#### 55)
```cpp
[[nodiscard]] constexpr std::intptr_t operator""_iptr(const unsigned long long int value) noexcept;
```
#### 56)
```cpp
[[nodiscard]] constexpr std::intptr_t operator""_iptr(const long double value) noexcept;
```
#### 57)
```cpp
[[nodiscard]] constexpr std::uintptr_t operator""_uptr(const unsigned long long int value) noexcept;
```
#### 58)
```cpp
[[nodiscard]] constexpr std::uintptr_t operator""_uptr(const long double value) noexcept;
```
#### 59)
```cpp
[[nodiscard]] constexpr std::ptrdiff_t operator""_dptr(const unsigned long long int value) noexcept;
```
#### 60)
```cpp
[[nodiscard]] constexpr std::ptrdiff_t operator""_dptr(const long double value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/literals/types.hpp>

int main() {
    using namespace xieite::math::literals;

    std::cout << -4263088327.4491_u32 << '\n';
}
```
Output:
```
31878969
```
