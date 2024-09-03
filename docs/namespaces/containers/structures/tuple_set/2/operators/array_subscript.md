# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[TupleSet<Container, std::tuple<FirstKey, RestKeys...>>](../../../../tuple_set.md)\:\:operator\[\]\<\>\(\)
Defined in fragment [xieite:containers.TupleSet](../../../../../../../src/containers/tuple_set.cpp)

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
import std;
import xieite;

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
