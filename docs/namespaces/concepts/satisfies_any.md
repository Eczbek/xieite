# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SatisfiesAny\<\>
Defined in fragment [xieite:concepts.SatisfiesAny](../../../src/concepts/satisfies_any.cpp)

&nbsp;

## Description
Specifies that a type satisfies any of several lambdas.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, auto... validators>
concept SatisfiesAny = (... || xieite::concepts::Satisfies<Type, validator>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::SatisfiesAny<int, []<std::integral> {}, []<std::same_as<long>> {}>);
    std::println("{}", xieite::concepts::SatisfiesAny<double, []<std::integral> {}, []<std::same_as<void*>> {}>);
}
```
Output:
```
true
false
```
