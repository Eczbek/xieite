# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Satisfies\<\>
Defined in fragment [xieite:concepts.Satisfies](../../../src/concepts/satisfies.cpp)

&nbsp;

## Description
Specifies that a type satisfies a lambda.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, auto validator>
concept Satisfies = xieite::concepts::SatisfiedBy<validator, Type>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::Satisfies<int, []<std::integral> {}>);
    std::println("{}", xieite::concepts::Satisfies<double, []<std::integral> {}>);
}
```
Output:
```
true
false
```
