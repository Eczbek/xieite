# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:any\<\>\(\)
Defined in header [<xieite/algorithms/any.hpp>](../../../include/xieite/algorithms/any.hpp)

&nbsp;

## Description
Checks whether a functor invoked with at least one following argument evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Values_, typename Functor_>
requires((... && xieite::concepts::Functable<Functor_, bool(Values_)>))
[[nodiscard]] constexpr bool any(Functor_&& functor, Values_&&... values)
noexcept((... && xieite::concepts::NoThrowInvocable<Functor_, Values_>));
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
