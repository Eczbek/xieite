# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:spliceTuple\(\)
Defined in header [<xieite/containers/splice_tuple.hpp>](../../../include/xieite/containers/splice_tuple.hpp)

&nbsp;

## Description
Can be used to insert, replace, and remove elements from a tuple.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t start, std::size_t count = 0, typename... Types1, typename... Types2>
requires((start <= sizeof...(Types1)) && (count <= (sizeof...(Types1) - start)))
[[nodiscard]] constexpr auto spliceTuple(const std::tuple<Types1...>& tuple1, const std::tuple<Types2...>& tuple2 = std::tuple<>()) noexcept;
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
