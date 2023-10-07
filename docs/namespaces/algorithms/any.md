# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:any
Defined in header [<xieite/algorithms/any.hpp>](../../../include/xieite/algorithms/any.hpp)

&nbsp;

## Description
Checks whether at least one passed argument is true. Expects all arguments to be converible to a boolean value.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::RangeOf<bool> Range>
[[nodiscard]] constexpr bool any(const Range& range)
noexcept(noexcept(xieite::concepts::NoThrowConvertibleTo<std::ranges::range_value_t<Range>, bool>));
```
#### 2)
```cpp
template<std::convertible_to<bool>... Values>
[[nodiscard]] constexpr bool any(const Values&... values)
noexcept(noexcept((... && xieite::concepts::NoThrowConvertibleTo<Values, bool>)));
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/algorithms/any.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::algorithms::any(false, 0, '\0') << '\n';
}
```
Output:
```
false
```
