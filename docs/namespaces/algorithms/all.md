# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:all\<\>\(\)
Defined in header [<xieite/algorithms/all.hpp>](../../../include/xieite/algorithms/all.hpp)

&nbsp;

## Description
Checks whether a functor invoked with each following argument evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Values, typename Functor>
requires((... && xieite::concepts::Functor<Functor, bool(Values)>))
[[nodiscard]] constexpr bool all(Functor&& functor, Values&&... values)
noexcept((... && xieite::concepts::NoThrowInvocable<Functor, Values>));
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/algorithms/all.hpp"
#include "xieite/macros/lift.hpp"

int main() {
    auto predicate = XIEITE_LIFT_ONE(static_cast<bool>);

    std::println("{}", xieite::algorithms::all(predicate, 4, true, '$'));
}
```
Output:
```
true
```
