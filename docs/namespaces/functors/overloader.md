# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Overloader\<\> \{\}
Defined in header [<xieite/functors/overloader.hpp>](../../../include/xieite/functors/overloader.hpp)

&nbsp;

## Description
Extends multiple invocable types and overloads its `operator()` for each.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Derivable... Derivables_>
struct Overloader
: Derivables_... {
    constexpr Overloader() noexcept;

    template<typename... DerivableReferences_>
    requires((... && std::convertible_to<DerivableReferences_, Derivables_>))
    explicit constexpr Overloader(DerivableReferences_&&...) noexcept;

    using Derivables_::operator()...;
};
```
- [Overloader\(\)](./structures/overloader/1/operators/constructor.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/overloader.hpp"

int main() {
    auto foo = [](int) {
        std::println("foo");
    };
    auto bar = [](double) {
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
