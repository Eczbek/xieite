# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:all\<\>\(\)
Defined in fragment [xieite:algorithms.all](../../../src/algorithms/all.cpp)

&nbsp;

## Description
Checks whether a functor invoked with each following argument evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Values, typename Functor>
[[nodiscard]] constexpr auto all(Functor&& functor, Values&&... values)
XIEITE_ARROW((... && std::invoke_r<bool>(functor, XIEITE_FORWARD(values))))
```

&nbsp;

## Example
```cpp
#include <xieite/lift.hpp>

import std;
import xieite;

int main() {
    auto predicate = XIEITE_LIFT_PREFIX(static_cast<bool>);

    std::println("{}", xieite::algorithms::all(predicate, 4, true, '$'));
}
```
Output:
```
true
```
