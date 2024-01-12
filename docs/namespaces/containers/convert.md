# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:convertRange
Defined in header [<xieite/containers/convert_range.hpp>](../../../include/xieite/containers/convert_range.hpp)

&nbsp;

## Description
Converts one range to another. Iterates over the least of the ranges' sizes.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range RangeFrom, std::ranges::range RangeTo, xieite::concepts::Functable<std::ranges::range_value_t<RangeTo>(std::ranges::range_value_t<RangeFrom>)> Converter = decltype([](std::ranges::range_value_t<RangeFrom>& value) {
	return static_cast<std::ranges::range_value_t<RangeTo>>(value);
})>
[[nodiscard]] constexpr void convertRange(const RangeFrom& rangeFrom, RangeTo& rangeTo, const Converter& converter = Converter())
noexcept(xieite::concepts::NoThrowInvocable<Converter, std::ranges::range_value_t<RangeFrom>>);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <xieite/containers/convert_range.hpp>

int main() {
    std::array<int, 5> source { 1, 2, 3, 4, 5 };
    std::vector<std::string> result(5);

    xieite::containers::convertRange(source, result, [](int x) { return std::to_string(x); });

    for (std::string_view item : result) {
        std::cout << item << '\n';
    }
}
```
Output:
```
1
2
3
4
5
```
