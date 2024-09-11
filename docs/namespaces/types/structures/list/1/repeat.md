# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Repeat\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Repeats `Types...` multiple times.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t repetitions>
using Repeat = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char>;

    std::println("{}", xieite::types::name<List::Repeat<3>>);
}
```
Possible output:
```
xieite::types::List<int, char, int, char, int char>
```
