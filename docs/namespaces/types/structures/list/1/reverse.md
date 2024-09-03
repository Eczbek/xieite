# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Reverse
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Reverses the stored list of types.

&nbsp;

## Synopsis
#### 1)
```cpp
using Reverse = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, short, long>::Reverse;

    std::println("{}", xieite::types::name<List>);
}
```
Possible output:
```
xieite::types::List<long, short, char, int>
```
