# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SameAsAll\<\>
Defined in fragment [xieite:concepts.SameAsAll](../../../src/concepts/same_as_all.cpp)

&nbsp;

## Description
Specifies that a type is the same as several other types. Passing no target types evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
concept SameAsAll = (... || std::same_as<Source, Targets>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::SameAsAll<int, int, int, int>);
    std::println("{}", xieite::concepts::SameAsAll<int, double, char, void*>);
}
```
Output:
```
true
false
```
