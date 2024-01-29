# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:all
Defined in header [<xieite/algorithms/all.hpp>](../../../include/xieite/algorithms/all.hpp)

&nbsp;

## Description
Checks whether all passed arguments are true. Expects all arguments to be converible to a boolean value.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::convertible_to<bool>... Values>
[[nodiscard]] constexpr bool all(Values&&... values)
noexcept((... && xieite::concepts::NoThrowConvertibleTo<Values, bool>));
```
#### 2)
```cpp
template<xieite::concepts::RangeOf<bool> Range>
[[nodiscard]] constexpr bool all(Range&& range)
noexcept(xieite::concepts::NoThrowConvertibleTo<std::ranges::range_reference_t<Range>, bool>);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/algorithms/all.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::algorithms::all(4, true, '$') << '\n';
}
```
Output:
```
true
```
