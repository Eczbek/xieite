# [xieite](../../../../xieite.md)\:\:[math](../../../../math.md)\:\:[literals](../literals.md)\:\: \(integers\)
Defined in header [<xieite/math/literals/integers.hpp>](../../../../../include/xieite/math/literals/integers.hpp)

&nbsp;

## Description
A colletion of literals for integers of specific sizes.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr int operator""_i(unsigned long long int value) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr bool operator""_b(unsigned long long int value) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr std::int8_t operator""_i8(unsigned long long int value) noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr std::int16_t operator""_i16(unsigned long long int value) noexcept;
```
#### 5)
```cpp
[[nodiscard]] constexpr std::int32_t operator""_i32(unsigned long long int value) noexcept;
```
#### 6)
```cpp
[[nodiscard]] constexpr std::int64_t operator""_i64(unsigned long long int value) noexcept;
```
#### 7)
```cpp
[[nodiscard]] constexpr std::intmax_t operator""_imax(unsigned long long int value) noexcept;
```
#### 8)
```cpp
[[nodiscard]] constexpr std::intptr_t operator""_iptr(unsigned long long int value) noexcept;
```
#### 9)
```cpp
[[nodiscard]] constexpr std::uint8_t operator""_u8(unsigned long long int value) noexcept;
```
#### 10)
```cpp
[[nodiscard]] constexpr std::uint16_t operator""_u16(unsigned long long int value) noexcept;
```
#### 11)
```cpp
[[nodiscard]] constexpr std::uint32_t operator""_u32(unsigned long long int value) noexcept;
```
#### 12)
```cpp
[[nodiscard]] constexpr std::uint64_t operator""_u64(unsigned long long int value) noexcept;
```
#### 13)
```cpp
[[nodiscard]] constexpr std::uintmax_t operator""_umax(unsigned long long int value) noexcept;
```
#### 14)
```cpp
[[nodiscard]] constexpr std::uintptr_t operator""_uptr(unsigned long long int value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/literals/integers.hpp>

int main() {
    using namespace xieite::math::literals;

    std::cout << -1_u64 << '\n';
}
```
Output:
```
18446744073709551615
```
