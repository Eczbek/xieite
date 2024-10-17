# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:ReplaceRange\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Replaces a range with a list of values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t start, std::size_t end, typename Range>
using ReplaceRange = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, short, long>::Replace<2, 1, xieite::types::List<float, double>>;

    std::println("{}", xieite::types::name<List>());
}
```
Possible output:
```
xieite::types::List<int, char, float, double, long>
```
