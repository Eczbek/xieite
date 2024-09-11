# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:get\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Gets the index of a type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, auto comparator = /* lambda */>
requires(xieite::types::List<Types...>::has<Type, Comparator>)
static constexpr std::size_t get = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, float, double, void, short, long, bool>;

    std::println("{}", List::get<double>);
}
```
Possible output:
```
3
```
