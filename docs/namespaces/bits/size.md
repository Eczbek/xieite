# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:size\<\>
Defined in fragment [xieite:bits.size](../../../src/bits/size.cpp)

&nbsp;

## Description
Defines the number of bits in a type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
inline constexpr std::size_t size = sizeof(Type) * std::numeric_limits<unsigned char>::digits;
```
#### 2)
```cpp
template<std::integral Integral>
inline constexpr std::size_t size<Integral> = std::numeric_limits<Integral>::digits + std::numeric_limits<Integral>::is_signed;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::bits::size<std::uint16_t>);
}
```
Possible output:
```
16
```
