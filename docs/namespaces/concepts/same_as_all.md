# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SameAsAll\<\>_
Defined in header [<xieite/concepts/same_as_all.hpp>](../../../include/xieite/concepts/same_as_all.hpp)

&nbsp;

## Description
Specifies that a type is the same as several other types. Passing no target types evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source_, typename... Targets_>
concept SameAsAll = (... || std::same_as<Source_, Targets_>);
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
