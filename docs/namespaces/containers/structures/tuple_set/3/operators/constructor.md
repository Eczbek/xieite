# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[TupleSet<Container, std::tuple<Key>>](../../../../tuple_set.md)\:\:TupleSet\(\)
Defined in fragment [xieite:containers.TupleSet](../../../../../../../src/containers/tuple_set.cpp)

&nbsp;

## Description
Constructs a `xieite::containers::TupleSet`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr TupleSet(std::initializer_list<Key> list = {}) noexcept;
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

    std::println("{}", set[std::make_tuple(5)]);
}
```
Output:
```
true
```
