# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Constant\<\>
Defined in fragment [xieite:concepts.Constant](../../../src/concepts/constant.cpp)

&nbsp;

## Description
Specifies that a type is constant, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Constant = std::is_const_v<std::remove_reference_t<Type>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::Constant<const int>);
    std::println("{}", xieite::concepts::Constant<int>);
    std::println("{}", xieite::concepts::Constant<const int&>);
}
```
Output:
```
true
false
true
```
