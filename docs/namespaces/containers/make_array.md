# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:makeArray\(\)
Defined in header [<xieite/containers/make_array.hpp>](../../../include/xieite/containers/make_array.hpp)

&nbsp;

## Description
Attempts to create `std::array`s from other ranges.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Value, std::size_t size, xieite::concepts::RangeOf<Value> Range, xieite::concepts::Functable<Value(std::ranges::range_reference_t<Range>)> Functor = xieite::functors::StaticCast<Value>>
[[nodiscard]] constexpr std::array<Value, size> makeArray(Range&& range, Functor&& converter = Functor())
noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_const_reference_t<Range>>);
```

&nbsp;

## Example
```cpp
#include <print>
#include <vector>
#include "xieite/containers/make_array.hpp"

int main() {
    std::vector<int> source { 1, 2, 3, 4, 5 };

    auto result = xieite::containers::makeArray<int, 5>(source);

    for (int item : result) {
        std::println("{}", item);
    }
}
```
Output:
```
14
```
