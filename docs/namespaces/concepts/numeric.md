# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Numeric\<\>
Defined in fragment [xieite:concepts.Numeric](../../../src/concepts/numeric.cpp)

&nbsp;

## Description
Specifies that a type is a floating point or an integer but not a boolean.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Numeric = xieite::concepts::Arithmetic<Type> && !std::same_as<std::remove_cv_t<Type>, bool>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::Numeric<int>);
    std::println("{}", xieite::concepts::Numeric<double>);
    std::println("{}", xieite::concepts::Numeric<bool>);
}
```
Output:
```
true
true
false
```
