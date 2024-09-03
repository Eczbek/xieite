# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Prepend\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Prepends types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... OtherTypes>
using Prepend = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, short, long>::Prepend<float, double>;

    std::println("{}", xieite::types::name<List>);
}
```
Possible output:
```
xieite::types::List<float, double, int, char, short, long>
```
