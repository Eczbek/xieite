# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:DissatisfiesAll\<\>
Defined in fragment [xieite:concepts.DissatisfiesAll](../../../src/concepts/dissatisfies_all.cpp)

&nbsp;

## Description
Specifies that a type dissatisfies all of several lambdas.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, auto validator>
concept DissatisfiesAll = (... && xieite::concepts::SatisfiedBy<validator, Type>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::DissatisfiesAll<int, []<std::floating_point> {}, []<std::same_as<void*>> {}>);
    std::println("{}", xieite::concepts::DissatisfiesAll<double, []<std::integral> {}, []<std::same_as<double>> {}>);
}
```
Output:
```
true
false
```
