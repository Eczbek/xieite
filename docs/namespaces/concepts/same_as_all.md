# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SameAsAll
Defined in header [<xieite/concepts/same_as_all.hpp"](../../../include/xieite/concepts/same_as_all.hpp)

&nbsp;

## Description
Specifies that a type is the same as several other types. Passing no target types evaluates to `true`.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept SameAsAll = (... || std::same_as<Source, Targets>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/same_as_all.hpp"

int main() {
    std::println("{}", xieite::concepts::SameAsAll<int, int, int, int>);
    std::println("{}", xieite::concepts::SameAsAll<int, double, char, void*>);
}
```
Output:
```
true
false
```
