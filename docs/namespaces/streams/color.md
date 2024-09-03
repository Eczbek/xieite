# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:Color\<\> \{\}
Defined in fragment [xieite:streams.Color](../../../src/streams/color.cpp)

&nbsp;

## Description
A simple class for storing an RGB(A) value.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t channels = 3>
struct Color {
    std::array<std::uint8_t, channels> data;

    template<std::same_as<std::uint8_t>... Arguments>
    requires(sizeof...(Arguments) == channels)
    constexpr Color(Arguments...) noexcept;

    constexpr Color(xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels> = 0) noexcept;

    friend constexpr bool operator==(const xieite::streams::Color<channels>&, const xieite::streams::Color<channels>&) noexcept = default;

    template<typename Self>
    constexpr auto&& operator[](this Self&&, std::size_t) noexcept;

    constexpr xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels> value() const noexcept;
};
```
- data
- [Color\(\)](./structures/color/1/operators/constructor.md)
- [operator\[\]\(\)](./structures/color/1/operators/array_subscript.md)
- [value\(\)](./structures/color/1/value.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto color = xieite::streams::Color<3>(255, 127, 0);

    std::println("{} {} {}", color[0], color[1], color[2]);
}
```
Output:
```
255 127 0
```
