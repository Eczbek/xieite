# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[Color<channels>](../../../color.md)\:\:value\(\)
Defined in fragment [xieite:streams.Color](../../../../../../src/streams/color.cpp)

&nbsp;

## Description
Shifts and adds color values together to create a single value.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels> value() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto color = xieite::streams::Color<3>(255, 127, 0);

    std::println("{}", xieite::math::stringify(color.value(), 16));
}
```
Output:
```
FF7F00
```
