# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:forwardTuple\<\>\(\)
Defined in header [<xieite/containers/forward_tuple.hpp>](../../../include/xieite/containers/forward_tuple.hpp)

&nbsp;

## Description
Forwards every item of a tuple.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::SpecializationOf<std::tuple> Tuple>
[[nodiscard]] constexpr auto forwardTuple(Tuple&& tuple) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <tuple>
#include "xieite/containers/forward_tuple.hpp"
#include "xieite/types/name.hpp"

int main() {
    auto foo = xieite::containers::forwardTuple(std::make_tuple(1, 2.5, 'a'));

    std::println("{}", xieite::types::name<decltype(foo)>);
}
```
Output:
```
std::tuple<int&&, double&&, char&&>
```
