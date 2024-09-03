# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Slice\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Selects a "slice" from the stored list of types. Allows indices out of bounds and in any order.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t start, std::size_t end = sizeof...(Types)>
using Slice = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, short, long>::Slice<1, 3>;

    std::println("{}", xieite::types::name<List>);
}
```
Possible output:
```
xieite::types::List<char, short>
```
