# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:DissatisfiedByAny\<\>
Defined in fragment [xieite:concepts.DissatisfiedByAny](../../../src/concepts/dissatisfied_by_any.cpp)

&nbsp;

## Description
Specifies that a lambda is dissatisfied by any of several types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto validator, typename... Types>
concept DissatisfiedByAny = (... || xieite::concepts::SatisfiedBy<validator, Types>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::DissatisfiedByAny<[]<std::integral> {}, int, long>);
    std::println("{}", xieite::concepts::DissatisfiedByAny<[]<std::integral> {}, double, char>);
}
```
Output:
```
false
true
```
