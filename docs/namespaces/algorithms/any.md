# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:any\(\)
Defined in header [<xieite/algorithms/any.hpp>](../../../include/xieite/algorithms/any.hpp)

&nbsp;

## Description
Checks whether at least one passed argument is true. Expects at least one argument to be converible to a boolean value. Passing no arguments evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<bool>... Values>
[[nodiscard]] constexpr bool any(const Values&... values)
noexcept((... || xieite::concepts::NoThrowConvertibleTo<Values, bool>));
```
#### 2)
```cpp
template<xieite::concepts::RangeOf<bool> Range>
[[nodiscard]] constexpr bool any(const Range& range)
noexcept(xieite::concepts::NoThrowConvertibleTo<std::ranges::range_reference_t<Range>, bool>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/algorithms/any.hpp"

int main() {
    std::println("{}", xieite::algorithms::any(false, 0, '\0'));
}
```
Output:
```
false
```
