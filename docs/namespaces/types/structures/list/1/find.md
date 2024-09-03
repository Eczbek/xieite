# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:find\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Finds the index of a type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename, typename> typename Comparator = std::is_same>
requires(xieite::types::List<Types...>::has<Type, Comparator>)
static constexpr std::size_t find = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, float, double, void, short, long, bool>;

    std::println("{}", List::find<double>);
}
```
Possible output:
```
3
```
