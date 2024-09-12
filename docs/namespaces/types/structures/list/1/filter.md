# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Filter\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Filters types according to whether or not they satisfy a lambda.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto selector>
using Filter = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, float, short, double, long>;

    std::println("{}", xieite::types::name<List::Filter<[]<std::integral> {}>>);
}
```
Possible output:
```
xieite::types::List<int, short, long>
```
