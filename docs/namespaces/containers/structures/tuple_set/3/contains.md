# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[TupleSet<Container, std::tuple<Key>>](../../../tuple_set.md)\:\:contains\(\)
Defined in fragment [xieite:containers.TupleSet](../../../../../../src/containers/tuple_set.cpp)

&nbsp;

## Description
Checks if the set contains a tuple.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<std::tuple<Key>> KeyReference>
[[nodiscard]] constexpr bool contains(KeyReference&& key) const;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using TupleSet = xieite::containers::TupleSet<std::unordered_set, std::tuple<int>>;

    TupleSet set = {
        { 5 },
        { 7 },
        { -23 },
        { 418 }
    };

    std::println("{}", set.contains(std::make_tuple(-23)));
    std::println("{}", set.contains(std::make_tuple(999)));
}
```
Output:
```
true
false
```
