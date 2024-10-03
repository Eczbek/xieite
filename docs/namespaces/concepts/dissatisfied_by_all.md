# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:DissatisfiedByAll\<\>
Defined in fragment [xieite:concepts.DissatisfiedByAll](../../../src/concepts/dissatisfied_by_all.cpp)

&nbsp;

## Description
Specifies that a lambda is dissatisfied by all of several types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto validator, typename... Types>
concept DissatisfiedByAll = (... && xieite::concepts::SatisfiedBy<validator, Types>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::DissatisfiedByAll<[]<std::integral> {}, double, long>);
    std::println("{}", xieite::concepts::DissatisfiedByAll<[]<std::integral> {}, double, void*>);
}
```
Output:
```
false
true
```
