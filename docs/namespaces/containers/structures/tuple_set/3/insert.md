# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[TupleSet<Container, std::tuple<Key>>](../../../tuple_set.md)\:\:insert\(\)
Defined in fragment [xieite:containers.TupleSet](../../../../../../src/containers/tuple_set.cpp)

&nbsp;

## Description
Adds a tuple to the set.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<std::tuple<Key>> KeyReference>
constexpr auto insert(KeyReference&& key)
XIEITE_ARROW(/* ... */)
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
