# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConvertibleToAll\<\>
Defined in fragment [xieite:concepts.ConvertibleToAll](../../../src/concepts/convertible_to_all.cpp)

&nbsp;

## Description
Specifies that a type can be converted to all of several other types. Passing no target types evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
concept ConvertibleToAll = (... && std::convertible_to<Source, Targets>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::ConvertibleToAll<int, double, char, unsigned long long int>);
    std::println("{}", xieite::concepts::ConvertibleToAll<int, void*, Nope, decltype([] {})>);
}
```
Output:
```
true
false
```
