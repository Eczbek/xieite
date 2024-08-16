# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[TupleSet<Container, std::tuple<FirstKey, RestKeys...>>](../../../../tuple_set.md)\:\:TupleSet\(\)
Defined in header [<xieite/containers/tuple_set.hpp>](../../../../../../../include/xieite/containers/tuple_set.hpp)

&nbsp;

## Description
Constructs a `xieite::containers::TupleSet`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr TupleSet(std::initializer_list<std::pair<FirstKey, xieite::containers::TupleSet<Container, std::tuple<RestKeys...>>>> list = {}) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <tuple>
#include <unordered_set>
#include "xieite/containers/tuple_set.hpp"

int main() {
    using TupleSet = xieite::containers::TupleSet<std::unordered_set, std::tuple<int, char>>;

    TupleSet set = {
        { 5, 'h' },
        { 7, '4' },
        { -23, 'L' },
        { 418, ' ' }
    };

    std::println("{}", set[std::make_tuple(5, 'h')]);
}
```
Output:
```
true
```
