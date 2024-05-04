# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Clock\<\>
Defined in header [<xieite/concepts/clock.hpp>](../../../include/xieite/concepts/clock.hpp)

&nbsp;

## Description
Specifies that a type satisfied `std::chrono::is_clock_v`. To be deprecated once `std::specialization_of` is standardized.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
concept Clock = std::chrono::is_clock_v<Type_>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/clock.hpp"

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::Clock<std::chrono::steady_clock>);
    std::println("{}", xieite::concepts::Clock<Nope>);
}
```
Output:
```
true
false
```
