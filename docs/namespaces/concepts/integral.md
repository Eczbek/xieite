# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Integral\<\>
Defined in fragment [xieite:concepts.Integral](../../../src/concepts/integral.cpp)

&nbsp;

## Description
Specifies that a type is an integer and not a boolean.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Integral = std::integral<Type> && !std::same_as<std::remove_cv_t<Type>, bool>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::Integral<int>);
    std::println("{}", xieite::concepts::Integral<bool>);
}
```
Output:
```
true
false
```
