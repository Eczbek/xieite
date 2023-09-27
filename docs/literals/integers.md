# [xieite](../xieite.md)\:\:[units](../units.md)\:\:lengths
Defined in header [<xieite/units/lengths.hpp>](../../include/xieite/units/lengths.hpp)

&nbsp;

## Description
A colletion of literals for integers of specific sizes.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr std::int8_t operator""_i8(const unsigned long long int value) noexcept;
```
#### 2)
```cpp
constexpr std::int16_t operator""_i16(const unsigned long long int value) noexcept;
```
#### 3)
```cpp
constexpr std::int32_t operator""_i32(const unsigned long long int value) noexcept;
```
#### 4)
```cpp
constexpr std::int64_t operator""_i64(const unsigned long long int value) noexcept;
```
#### 5)
```cpp
constexpr std::intmax_t operator""_imax(const unsigned long long int value) noexcept;
```
#### 6)
```cpp
constexpr std::intptr_t operator""_iptr(const unsigned long long int value) noexcept;
```
#### 7)
```cpp
constexpr std::uint8_t operator""_u8(const unsigned long long int value) noexcept;
```
#### 8)
```cpp
constexpr std::uint16_t operator""_u16(const unsigned long long int value) noexcept;
```
#### 9)
```cpp
constexpr std::uint32_t operator""_u32(const unsigned long long int value) noexcept;
```
#### 10)
```cpp
constexpr std::uint64_t operator""_u64(const unsigned long long int value) noexcept;
```
#### 11)
```cpp
constexpr std::uintmax_t operator""_umax(const unsigned long long int value) noexcept;
```
#### 12)
```cpp
constexpr std::uintptr_t operator""_uptr(const unsigned long long int value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/literals/integers.hpp>

int main() {
    std::cout << -1_u64 << '\n';
}
```
Output:
```
18446744073709551615
```
