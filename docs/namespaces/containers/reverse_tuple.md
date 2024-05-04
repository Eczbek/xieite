# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:reverseTuple\<\>\(\)
Defined in header [<xieite/containers/reverse_tuple.hpp>](../../../include/xieite/containers/reverse_tuple.hpp)

&nbsp;

## Description
Reverses the order of elements in a `std::tuple`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Types_>
[[nodiscard]] constexpr typename xieite::types::List<Types_...>::Reverse::Apply<std::tuple> reverseTuple(const std::tuple<Types_...>& tuple)
noexcept(([]<std::size_t... i_>(std::index_sequence<i_...>) -> bool {
    return (... && xieite::concepts::NoThrowConvertibleTo<typename xieite::types::List<Types_...>::At<i_>, typename xieite::types::List<Types_...>::Reverse::At<i_>>);
})(std::make_index_sequence<sizeof...(Types_)>()));
```

&nbsp;

## Example
```cpp
#include <print>
#include <tuple>
#include "xieite/containers/reverse_tuple.hpp"

int main() {
    auto tuple = std::make_tuple<int, char, float>(5, 'h', 3.14159);

    auto result = xieite::containers::reverseTuple(tuple);

    std::apply([](auto... values) {
        (..., std::println("{}", values));
    }, result);
}
```
Output:
```
3.14159
h
5
```
