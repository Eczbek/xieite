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
requires((... && xieite::concepts::Invocable<Functor, bool(Values)>))
[[nodiscard]] constexpr bool all(Functor&& functor, Values&&... values)
noexcept((... && xieite::concepts::NoThrowInvocable<Functor, bool(Values)>));
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
