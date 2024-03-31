# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:any\(\)
Defined in header [<xieite/algorithms/any.hpp>](../../../include/xieite/algorithms/any.hpp)

&nbsp;

## Description
Checks whether a functor invoked with at least one following argument evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Values, typename Functor>
requires((... && xieite::concepts::Functable<Functor, bool(Values)>))
[[nodiscard]] constexpr bool any(Functor&& functor, Values&&... values)
noexcept((... && xieite::concepts::NoThrowInvocable<Functor, Values>));
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/algorithms/any.hpp"
#include "xieite/functors/static_cast.hpp"

int main() {
    auto predicate = xieite::functors::StaticCast<bool>();

    std::println("{}", xieite::algorithms::any(predicate, false, 0, '\0'));
}
```
Output:
```
false
```
