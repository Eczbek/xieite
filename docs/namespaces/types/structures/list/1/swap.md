# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Swap\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Swaps two types by indices.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t index1, std::size_t index2>
using Swap = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, short, long>::Swap<1, 3>;

    std::println("{}", xieite::types::name<List>());
}
```
Possible output:
```
xieite::types::List<int, long, short, char>
```
