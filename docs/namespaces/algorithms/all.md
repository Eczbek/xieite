# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:all\<\>\(\)
Defined in header [<xieite/algorithms/all.hpp>](../../../include/xieite/algorithms/all.hpp)

&nbsp;

## Description
Checks whether a functor invoked with each following argument evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Values_, typename Functor_>
requires((... && xieite::concepts::Functable<Functor_, bool(Values_)>))
[[nodiscard]] constexpr bool all(Functor_&& functor, Values_&&... values)
noexcept((... && xieite::concepts::NoThrowInvocable<Functor_, Values_>));
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/algorithms/all.hpp"
#include "xieite/functors/static_cast.hpp"

int main() {
    auto predicate = xieite::functors::StaticCast<bool>();

    std::println("{}", xieite::algorithms::all(predicate, 4, true, '$'));
}
```
Output:
```
true
```
