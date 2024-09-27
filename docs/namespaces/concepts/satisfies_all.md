# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SatisfiesAll\<\>
Defined in fragment [xieite:concepts.SatisfiesAll](../../../src/concepts/satisfies_all.cpp)

&nbsp;

## Description
Specifies that a type satisfies all of several lambdas.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, auto validator>
concept SatisfiesAll = (... && xieite::concepts::SatisfiedBy<validator, Type>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::SatisfiesAll<int, []<std::integral> {}, []<std::same_as<int>> {}>);
    std::println("{}", xieite::concepts::SatisfiesAll<double, []<std::integral> {}, []<std::same_as<void*>> {}>);
}
```
Output:
```
true
false
```
