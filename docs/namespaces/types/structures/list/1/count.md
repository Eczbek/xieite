# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:count\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Counts the instances of a type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename, typename> typename Comparator = std::is_same>
static constexpr std::size_t count = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, int, char, int, char, char, int>;

    std::println("{}", List::count<int>);
}
```
Possible output:
```
4
```
