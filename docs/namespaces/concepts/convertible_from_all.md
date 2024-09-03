# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConvertibleFromAll\<\>
Defined in fragment [xieite:concepts.ConvertibleFromAll](../../../src/concepts/convertible_from_all.cpp)

&nbsp;

## Description
Specifies that a type can be converted from all of several other types. Passing no target types evaluates from `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target, typename... Sources>
concept ConvertibleFromAll = (... && xieite::concepts::ConvertibleFrom<Target, Sources>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::ConvertibleFromAll<int, double, char, unsigned long long int>);
    std::println("{}", xieite::concepts::ConvertibleFromAll<int, void*, Nope, decltype([] {})>);
}
```
Output:
```
true
false
```
