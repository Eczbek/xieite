# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConvertibleFromAny\<\>
Defined in fragment [xieite:concepts.ConvertibleFromAny](../../../src/concepts/convertible_from_any.cpp)

&nbsp;

## Description
Specifies that a type can be converted from at least one of several other types. Passing no target types evaluates from `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target, typename... Sources>
concept ConvertibleFromAny = (... || xieite::concepts::ConvertibleFrom<Target, Sources>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::ConvertibleFromAny<int, double, char, unsigned long long int>);
    std::println("{}", xieite::concepts::ConvertibleFromAny<int, void*, Nope, decltype([] {})>);
}
```
Output:
```
true
false
```
