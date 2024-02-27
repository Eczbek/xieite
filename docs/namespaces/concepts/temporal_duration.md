# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:TemporalDuration
Defined in header [<xieite/concepts/temporal_duration.hpp>](../../../include/xieite/concepts/temporal_duration.hpp)

&nbsp;

## Description
Specifies that a type is a `std::chrono::duration`. To be deprecated once `std::specialization_of` is standardized.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept TemporalDuration = xieite::traits::IsTemporalDuration<std::remove_cv_t<Type>>::value;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/temporal_duration.hpp"

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::TemporalDuration<std::chrono::hours>);
    std::println("{}", xieite::concepts::TemporalDuration<Nope>);
}
```
Output:
```
true
false
```
