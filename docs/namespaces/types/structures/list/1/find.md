# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:find\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Finds the first index of a type that satisfies a lambda.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto selector>
requires(xieite::types::List<Types...>::any<selector>)
static constexpr std::size_t find = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, char, float, double, void, short, long, bool>;

    std::println("{}", List::find<[]<std::same_as<double>> {}>);
}
```
Possible output:
```
3
```
