# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:any\<\>\(\)
Defined in fragment [xieite:algorithms.any](../../../src/algorithms/any.cpp)

&nbsp;

## Description
Checks whether a functor invoked with at least one following argument evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Values, typename Functor>
[[nodiscard]] constexpr auto any(Functor&& functor, Values&&... values)
XIEITE_ARROW((... || std::invoke_r<bool>(functor, XIEITE_FORWARD(values))))
```

&nbsp;

## Example
```cpp
#include <xieite/lift.hpp>

import std;
import xieite;

int main() {
    auto predicate = XIEITE_LIFT_PREFIX(static_cast<bool>);

    std::println("{}", xieite::algorithms::any(predicate, false, 0, '\0'));
}
```
Output:
```
false
```
