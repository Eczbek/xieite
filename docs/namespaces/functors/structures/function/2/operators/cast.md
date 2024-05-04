# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Function<Return_(Arguments_...)>](../../../../function.md)\:\:operator typename\(\)
Defined in header [<xieite/functors/function.hpp>](../../../../../../../include/xieite/functors/function.hpp)

&nbsp;

## Description
The boolean cast returns `true` if a functor is assigned, `false` otherwise.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] explicit constexpr operator bool() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/function.hpp"

int main() {
    using Function = xieite::functors::Function<void()>;

    Function foo;

    Function bar = [] {};

    std::println("{}", static_cast<bool>(foo));
    std::println("{}", static_cast<bool>(bar));
}
```
Output:
```
false
true
```
