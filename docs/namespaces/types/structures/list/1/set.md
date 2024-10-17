# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Set\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Sets a type by index.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t index, typename OtherType>
using Set = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, short, long>::Set<2, float>;

    std::println("{}", xieite::types::name<List>());
}
```
Possible output:
```
xieite::types::List<int, char, float, long>
```
