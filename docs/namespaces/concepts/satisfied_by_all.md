# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SatisfiedByAll\<\>
Defined in fragment [xieite:concepts.SatisfiedByAll](../../../src/concepts/satisfied_by_all.cpp)

&nbsp;

## Description
Specifies that a lambda is satisfied by all of several types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto validator, typename... Types>
concept SatisfiedByAll = (... && xieite::concepts::SatisfiedBy<validator, Types>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::SatisfiedByAll<[]<std::integral> {}, int, long>);
    std::println("{}", xieite::concepts::SatisfiedByAll<[]<std::integral> {}, double, char>);
}
```
Output:
```
true
false
```
