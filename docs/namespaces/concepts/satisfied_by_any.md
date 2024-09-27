# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SatisfiedByAny\<\>
Defined in fragment [xieite:concepts.SatisfiedByAny](../../../src/concepts/satisfied_by_any.cpp)

&nbsp;

## Description
Specifies that a lambda is satisfied by any of several types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto validator, typename... Types>
concept SatisfiedByAny = (... || xieite::concepts::SatisfiedBy<validator, Types>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::SatisfiedByAny<[]<std::integral> {}, int, long>);
    std::println("{}", xieite::concepts::SatisfiedByAny<[]<std::integral> {}, double, char>);
}
```
Output:
```
true
true
```
