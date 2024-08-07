# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:StaticCast\<\> \{\}
Defined in header [<xieite/functors/static_cast.hpp>](../../../include/xieite/functors/static_cast.hpp)

&nbsp;

## Description
A functor which simply `static_cast`s one value to another type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target_>
struct StaticCast {
    template<std::convertible_to<Target_> Source_>
    constexpr Target_ operator()(Source_&&) const
    noexcept(xieite::concepts::NoThrowConvertibleTo<Source_, Target_>);
};
```
- [operator\(\)\<\>\(\)](./structures/static_cast/1/operators/call.md)

&nbsp;

## Example
```cpp
#include <algorithm>
#include <print>
#include <vector>
#include "xieite/functors/static_cast.hpp"

int main() {
    std::vector<double> foo = { 1.5, 2.5, 3.5 };
    std::vector<int> bar = std::vector<int>(3);

    std::ranges::transform(foo, bar.begin(), xieite::functors::StaticCast<int>());

    for (int value : bar) {
        std::println("{}", value);
    }
}
```
Output:
```
1
2
3
```
