# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:any\<\>\(\)
Defined in header [<xieite/algorithms/any.hpp>](../../../include/xieite/algorithms/any.hpp)

&nbsp;

## Description
Checks whether a functor invoked with at least one following argument evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Values, typename Functor>
requires((... && xieite::concepts::Functor<Functor, bool(Values)>))
[[nodiscard]] constexpr bool any(Functor&& functor, Values&&... values)
noexcept((... && std::is_nothrow_invocable_v<Functor, Values>));
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/algorithms/any.hpp"
#include "xieite/macros/lift.hpp"

int main() {
    auto predicate = XIEITE_LIFT_UNARY(static_cast<bool>);

    std::println("{}", xieite::algorithms::any(predicate, false, 0, '\0'));
}
```
Output:
```
false
```
