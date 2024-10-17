# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Insert\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Inserts a list of values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t index, typename Range>
using InsertRange = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, short, long>::InsertRange<2, xieite::types::List<float, double>>;

    std::println("{}", xieite::types::name<List>());
}
```
Possible output:
```
xieite::types::List<int, char, float, double, short, long>
```
