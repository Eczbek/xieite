# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:PrependRange\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Prepends a list of types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Range>
using PrependRange = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, short, long>::PrependRange<xieite::types::List<float, double>>;

    std::println("{}", xieite::types::name<List>);
}
```
Possible output:
```
xieite::types::List<float, double, int, char, short, long>
```
