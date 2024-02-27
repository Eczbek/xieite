# [xieite](../../xieite.md)\:\:[memory](../../memory.md)\:\:Shredder
Defined in header [<xieite/memory/shredder.hpp>](../../../include/xieite/memory/shredder.hpp)

&nbsp;

## Description
Clears used memory upon destruction.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
struct Shredder {
    constexpr Shredder();

    template<typename... Arguments>
    requires(std::constructible_from<Type, Arguments...>)
    constexpr Shredder(Arguments&&...);

    constexpr operator const Type&() const&;

    constexpr operator Type&()&;

    constexpr operator const Type&&() const&&;

    constexpr operator Type&&()&&;
};
```
##### Member functions
- [Shredder](./structures/shredder/1/operators/constructor.md)
- [operator typename](./structures/shredder/1/operators/cast.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/memory/shredder.hpp"

int main() {
    {
        int a = 4;
    }
    int b;
    std::cout << b << '\n';

    {
        xieite::memory::Shredder<int> c = 4;
    }
    int d;
    std::cout << d << '\n';
}
```
Possible output:
```
4
0
```
