# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[TupleSet<Container_, std::tuple<FirstKey_, RestKeys_...>>](../../../tuple_set.md)\:\:insert\(\)
Defined in header [<xieite/containers/tuple_set.hpp>](../../../../../../include/xieite/containers/tuple_set.hpp)

&nbsp;

## Description
Adds a tuple to the set.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_>
constexpr void insert(KeysReference_&& keys);
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
        { 5, 'h' }
    };

    set.insert(std::make_tuple(-23, 'L'));

    std::println("{}", set[std::make_tuple(-23, 'L')]);
}
```
Output:
```
true
```
