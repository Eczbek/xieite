# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:At\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Accesses a type by index.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t index>
requires(index < sizeof...(Types))
using At = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using Type = xieite::types::List<int, char, short, long>::At<2>;

    std::println("{}", xieite::types::name<Type>());
}
```
Possible output:
```
short
```
