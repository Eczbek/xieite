# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:spliceTuple\(\)
Defined in header [<xieite/containers/splice_tuple.hpp>](../../../include/xieite/containers/splice_tuple.hpp)

&nbsp;

## Description
Can be used to insert, replace, and remove elements from a tuple.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t start_, std::size_t count_ = 0, xieite::concepts::SpecializationOf<std::tuple> Tuple1_, xieite::concepts::SpecializationOf<std::tuple> Tuple2_ = std::tuple<>>
requires((start_ <= std::tuple_size_v<std::remove_cvref_t<Tuple1_>>) && (count_ <= (std::tuple_size_v<std::remove_cvref_t<Tuple1_>> - start_)))
[[nodiscard]] constexpr auto spliceTuple(Tuple1_&& tuple1, Tuple2_&& tuple2 = Tuple2_()) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <tuple>
#include "xieite/containers/splice_tuple.hpp"

int main() {
    auto foo = std::make_tuple(1, 2, 3);

    auto bar = std::make_tuple(6.28318, 'h');

    std::apply([](auto... values) {
        (..., std::println("{}", values));
    }, xieite::containers::spliceTuple<1, 1>(foo, bar));
}
```
Output:
```
1
6.28318
h
3
```
