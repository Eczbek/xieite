# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:has\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Checks if the list contains a particular type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, auto comparator = /* std::same_as */>
static constexpr bool has = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, int, char, int, char, char, int>;

    std::println("{}", List::has<int>);
    std::println("{}", List::has<float>);
}
```
Possible output:
```
true
false
```
