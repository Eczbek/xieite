# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:RightValueReference\<\>
Defined in fragment [xieite:concepts.RightValueReference](../../../src/concepts/right_value_reference.cpp)

&nbsp;

## Description
Specifies that a type is an rvalue reference.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept RightValueReference = std::is_rvalue_reference_v<Type>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::RightValueReference<int>);
    std::println("{}", xieite::concepts::RightValueReference<int&>);
    std::println("{}", xieite::concepts::RightValueReference<int&&>);
}
```
Output:
```
false
false
true
```
