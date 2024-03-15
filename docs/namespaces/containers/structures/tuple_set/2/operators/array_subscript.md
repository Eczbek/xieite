# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[TupleSet<Container, std::tuple<FirstKey, RestKeys...>>](../../../../tuple_set.md)\:\:operator\[\]\(\)
Defined in header [<xieite/containers/tuple_set.hpp>](../../../../../../../include/xieite/containers/tuple_set.hpp)

&nbsp;

## Description
Checks if the set contains a tuple.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
[[nodiscard]] constexpr bool operator[](KeysReference&& keys) const;
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

    std::println("{}", set[std::make_tuple(-23, 'L')]);
    std::println("{}", set[std::make_tuple(999, 'a')]);
}
```
Output:
```
true
false
```
