# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Infix<Return(Argument)>](../../../../infix.md)\:\:operator<\(\)
Defined in header [<xieite/functors/infix.hpp>](../../../../../../../include/xieite/functors/infix.hpp)

&nbsp;

## Description
Calls the underlying functor with one argument.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<Argument> ArgumentReference>
friend constexpr Return operator<(ArgumentReference&& argument, const xieite::functors::Infix<Return(Argument)>& infix);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/infix.hpp"

int main() {
    xieite::functors::Infix<int(int)> half = [](int x) -> int {
        return x / 2;
    };

    std::println("{}", 14 <half);
}
```
Output:
```
7
```
