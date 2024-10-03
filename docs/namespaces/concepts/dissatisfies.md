# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Dissatisfies\<\>
Defined in fragment [xieite:concepts.Dissatisfies](../../../src/concepts/dissatisfies.cpp)

&nbsp;

## Description
Specifies that a type satisfies a lambda.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, auto validator>
concept Dissatisfies = xieite::concepts::SatisfiedBy<validator, Type>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::Dissatisfies<int, []<std::integral> {}>);
    std::println("{}", xieite::concepts::Dissatisfies<double, []<std::integral> {}>);
}
```
Output:
```
false
true
```
