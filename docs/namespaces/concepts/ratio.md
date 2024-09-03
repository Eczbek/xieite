# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Ratio\<\>
Defined in fragment [xieite:concepts.Ratio](../../../src/concepts/ratio.cpp)

&nbsp;

## Description
Specifies that a type is a specialization of `std::ratio`. To be deprecated once `std::specialization_of` is standardized.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Ratio = xieite::traits::IsRatio<std::remove_cv_t<Type>>::value;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::Ratio<std::centi>);
    std::println("{}", xieite::concepts::Ratio<Nope>);
}
```
Output:
```
true
false
```
