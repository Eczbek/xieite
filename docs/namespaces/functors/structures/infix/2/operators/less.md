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
friend constexpr Return operator>(const xieite::functors::Infix<Return(Argument)>& infix, ArgumentReference&& argument);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/infix.hpp"

int main() {
    xieite::functors::Infix<int(int)> square = [](int x) -> int {
        return x * x;
    };

    std::println("{}", square> 2);
}
```
Output:
```
4
```
