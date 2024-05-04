# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConvertibleToAll\<\>
Defined in header [<xieite/concepts/convertible_to_all.hpp>](../../../include/xieite/concepts/convertible_to_all.hpp)

&nbsp;

## Description
Specifies that a type can be converted to several other types. Passing no target types evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source_, typename... Targets_>
concept ConvertibleToAll = (... && std::convertible_to<Source_, Targets_>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/convertible_to_all.hpp"

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::ConvertibleToAll<int, double, char, unsigned long long int>);
    std::println("{}", xieite::concepts::ConvertibleToAll<int, void*, Nope, decltype([] {})>);
}
```
Output:
```
true
false
```
