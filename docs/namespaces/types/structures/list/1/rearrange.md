# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Rearrange\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Rearranges the types within a list by their indices

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t... indices>
using Rearrange = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using Foo = xieite::types::List<int, char, short, long>;

    using Bar = Foo::Rearrange<3, 0, 2>;

    std::println("{}", xieite::types::name<Bar>);
}
```
Possible output:
```
xieite::types::List<long, int, short>
```
