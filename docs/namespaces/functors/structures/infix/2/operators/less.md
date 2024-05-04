# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Infix<Return_(Argument_)>](../../../../infix.md)\:\:operator<\(\)
Defined in header [<xieite/functors/infix.hpp>](../../../../../../../include/xieite/functors/infix.hpp)

&nbsp;

## Description
Calls the underlying functor with one argument.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<Argument_> ArgumentReference_>
friend constexpr Return_ operator>(const xieite::functors::Infix<Return_(Argument_)>& infix, ArgumentReference_&& argument);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/infix.hpp"

int main() {
    xieite::functors::Infix<int(int)> square = [](int x) {
        return x * x;
    };

    std::println("{}", square> 2);
}
```
Output:
```
4
```
