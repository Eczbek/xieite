# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Overloader\<\> \{\}
Defined in header [<xieite/functors/overloader.hpp>](../../../include/xieite/functors/overloader.hpp)

&nbsp;

## Description
Extends multiple invocable types and overloads its `operator()` for each.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Derivable... Derivables>
struct Overloader
: Derivables... {
    constexpr Overloader() noexcept;

    template<typename... DerivableReferences>
    requires((... && std::convertible_to<DerivableReferences, Derivables>))
    explicit constexpr Overloader(DerivableReferences&&...) noexcept;

    using Derivables::operator()...;
};
```
- [Overloader\(\)](./structures/overloader/1/operators/constructor.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/overloader.hpp"

int main() {
    auto foo = [](int) -> void {
        std::println("foo");
    };
    auto bar = [](double) -> void {
        std::println("bar");
    };

    auto overloader = xieite::functors::Overloader(foo, bar);

    overloader(999);
    overloader(3.14159);
}
```
Output:
```
foo
bar
```
