# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[TupleSet<Container, std::tuple<FirstKey, RestKeys...>>](../../../tuple_set.md)\:\:insert\(\)
Defined in header [<xieite/containers/tuple_set.hpp>](../../../../../../include/xieite/containers/tuple_set.hpp)

&nbsp;

Adds a tuple to the set.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
constexpr void insert(KeysReference&& keys);
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
