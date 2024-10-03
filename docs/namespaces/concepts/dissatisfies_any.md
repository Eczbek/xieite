# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:DissatisfiesAny\<\>
Defined in fragment [xieite:concepts.DissatisfiesAny](../../../src/concepts/dissatisfies_any.cpp)

&nbsp;

## Description
Specifies that a type dissatisfies any of several lambdas.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, auto validator>
concept DissatisfiesAny = (... || xieite::concepts::SatisfiedBy<validator, Type>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::DissatisfiesAny<int, []<std::integral> {}, []<std::same_as<int>> {}>);
    std::println("{}", xieite::concepts::DissatisfiesAny<double, []<std::floating_point> {}, []<std::same_as<void*>> {}>);
}
```
Output:
```
false
true
```
