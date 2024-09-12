# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:any\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Checks if a lambda is satisfied for any type in the list.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto selector>
static constexpr bool any = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, int, char, int, char, char, int>;

    std::println("{}", List::any<[]<std::integral> {}>);
    std::println("{}", List::any<[]<std::floating_point> {}>);
}
```
Possible output:
```
true
false
```
