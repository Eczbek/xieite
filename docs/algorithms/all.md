# [xieite](../xieite.md)\:\:[algorithms](../algorithms.md)\:\:all
Defined in header [<xieite/algorithms/all.hpp>](../../include/xieite/algorithms/all.hpp)

&nbsp;

## Description
Checks whether all passed arguments are true. Expects all arguments to be converible to a boolean value.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::RangeOf<bool> Range>
constexpr bool all(const Range& range)
noexcept(noexcept(xieite::concepts::NoThrowConvertibleTo<std::ranges::range_value_t<Range>, bool>));
```
#### 2)
```cpp
template<std::convertible_to<bool>... Values>
constexpr bool all(const Values&... values)
noexcept(noexcept((... && xieite::concepts::NoThrowConvertibleTo<Values, bool>)));
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
