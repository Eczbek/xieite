# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:makeArray\(\)
Defined in header [<xieite/containers/make_array.hpp>](../../../include/xieite/containers/make_array.hpp)

&nbsp;

## Description
Attempts to create `std::array`s from other ranges.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Value_, std::size_t size_, xieite::concepts::RangeOf<Value_> Range_, xieite::concepts::Functable<Value_(std::ranges::range_reference_t<Range_>)> Functor_ = xieite::functors::StaticCast<Value_>>
[[nodiscard]] constexpr std::array<Value_, size_> makeArray(Range_&& range, Functor_&& converter = Functor_())
noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_const_reference_t<Range_>>);
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
