# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:none\(\)
Defined in header [<xieite/algorithms/none.hpp>](../../../include/xieite/algorithms/none.hpp)

&nbsp;

## Description
Checks whether a functor invoked with none of the following arguments evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Values, typename Functor>
requires((... && xieite::concepts::Functable<Functor, bool(Values)>))
[[nodiscard]] constexpr bool none(Functor&& functor, Values&&... values)
noexcept((... && xieite::concepts::NoThrowInvocable<Functor, Values>));
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/algorithms/none.hpp"
#include "xieite/functors/static_cast.hpp"

int main() {
    auto predicate = xieite::functors::StaticCast<bool>();

    std::println("{}", xieite::algorithms::none(predicate, false, 0, '\0'));
}
```
Output:
```
true
```
