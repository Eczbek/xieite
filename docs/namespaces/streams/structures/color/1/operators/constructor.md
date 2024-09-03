# [xieite](../../../../../../xieite.md)\:\:[streams](../../../../../../streams.md)\:\:[Color<channels>](../../../../color.md)\:\:Color\(\)
Defined in fragment [xieite:streams.Color](../../../../../../../src/streams/color.cpp)

&nbsp;

## Description
Constructs a `xieite::streams::Color<channels>`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::same_as<std::uint8_t>... Arguments>
requires(sizeof...(Arguments) == channels)
constexpr Color(Arguments... arguments) noexcept;
```
#### 2)
```cpp
constexpr Color(xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels> value = 0) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto color = xieite::streams::Color<3>(0xFF7F00);

    std::println("{} {} {}", color[0], color[1], color[2]);
}
```
Output:
```
false
```
