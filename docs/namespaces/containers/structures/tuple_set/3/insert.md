# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[TupleSet<Container, std::tuple<Key>>](../../../tuple_set.md)\:\:insert\(\)
Defined in header [<xieite/containers/tuple_set.hpp>](../../../../../../include/xieite/containers/tuple_set.hpp)

&nbsp;

## Description
Adds a tuple to the set.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<std::tuple<Key>> KeyReference>
constexpr void insert(KeyReference&& key);
```

&nbsp;

## Example
```cpp
#include <print>
#include <tuple>
#include <unordered_set>
#include "xieite/containers/tuple_set.hpp"

int main() {
    using TupleSet = xieite::containers::TupleSet<std::unordered_set, std::tuple<int>>;

    TupleSet set = {
        { 5 }
    };

    set.insert(std::make_tuple(-23));

    std::println("{}", set[std::make_tuple(-23)]);
}
```
Output:
```
true
```
