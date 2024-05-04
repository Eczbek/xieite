# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Infix<Return_(LeftArgument_, RightArgument_)>](../../../../infix.md)\:\:operator<\(\)
Defined in header [<xieite/functors/infix.hpp>](../../../../../../../include/xieite/functors/infix.hpp)

&nbsp;

## Description
Returns an intermediate state which must be used immediately.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<LeftArgument_> LeftArgumentReference_>
[[nodiscard]] friend constexpr xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>::Intermediate<LeftArgumentReference_> operator<(LeftArgumentReference_&& leftArgument, const xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>& infix) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/infix.hpp"

int main() {
    xieite::types::Infix<int(int, int)> add = [](int x, int y) {
        return x + y;
    };

    std::println("{}", 5 <add> 7);
}
```
Output:
```
12
```
