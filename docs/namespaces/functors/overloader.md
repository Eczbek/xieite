# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Overloader
Defined in header [<xieite/functors/overloader.hpp>](../../../include/xieite/functors/overloader.hpp)

&nbsp;

## Description
Extends multiple invocable types and overloads `operator()` for each.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Derivable... Derivables>
struct Overloader
: Derivables... {
    constexpr Overloader();

    constexpr Overloader(Derivables&&...);

    using Derivables::operator()...;
};
```
##### Member functions
- [Overloader](./structures/overloader/1/operators/constructor.md)
- [operator()](./structures/overloader/1/operators/call.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/functors/overloader.hpp>

int main() {
    auto foo = [](int) -> void {
        std::cout << "foo\n";
    };
    auto bar = [](double) -> void {
        std::cout << "bar\n";
    };

    xieite::functors::Overloader overloader(foo, bar);

    overloader(999);
    overloader(3.14159);
}
```
Output:
```
foo
bar
```
