# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:SwapRanges\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Swaps two ranges of types by indices.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t start1, std::size_t end1, std::size_t start2, std::size_t end2>
using SwapRanges = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, short, long>::SwapRanges<0, 2, 2, 4>;

    std::println("{}", xieite::types::name<List>);
}
```
Possible output:
```
xieite::types::List<short, long, int, char>
```
