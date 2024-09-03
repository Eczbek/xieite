# [xieite](../../../../../../xieite.md)\:\:[streams](../../../../../../streams.md)\:\:[Color<channels>](../../../../color.md)\:\:operator\[\]\(\)
Defined in fragment [xieite:streams.Color](../../../../../../../src/streams/color.cpp)

&nbsp;

## Description
Accesses a color channel by index.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self>
[[nodiscard]] constexpr decltype(auto) operator[](this Self&&, std::size_t index) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto color = xieite::streams::Color<3>(0xFF7F00);

    std::println("{}", color[1]);
}
```
Output:
```
false
```
