# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:LeftValueReference\<\>
Defined in fragment [xieite:concepts.LeftValueReference](../../../src/concepts/left_value_reference.cpp)

&nbsp;

## Description
Specifies that a type is an lvalue reference.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept LeftValueReference = std::is_lvalue_reference_v<Type>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::LeftValueReference<int>);
    std::println("{}", xieite::concepts::LeftValueReference<int&>);
    std::println("{}", xieite::concepts::LeftValueReference<int&&>);
}
```
Output:
```
false
true
false
```
