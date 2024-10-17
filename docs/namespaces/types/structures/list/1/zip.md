# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Zip\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Zips `Types...` with other types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... OtherTypes>
requires(sizeof...(Types) == sizeof...(OtherTypes))
using Zip = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using Foo = xieite::types::List<int, char, long>;

    using Bar = Foo::Zip<float, short, bool>;

    std::println("{}", xieite::types::name<Bar>());
}
```
Possible output:
```
xieite::types::List<xieite::types::List<int, float>, xieite::types::List<char, short>, xieite::types::List<long, bool>>
```
