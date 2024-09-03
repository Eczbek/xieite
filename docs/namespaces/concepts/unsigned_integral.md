# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:UnsignedIntegral\<\>
Defined in fragment [xieite:concepts.UnsignedIntegral](../../../src/concepts/unsigned_integral.cpp)

&nbsp;

## Description
Specifies that a type is an unsigned integral and not a boolean.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept UnsignedIntegral = std::unsigned_integral<Type> && !std::same_as<std::remove_cv_t<Type>, bool>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::UnsignedIntegral<unsigned short int>);
    std::println("{}", xieite::concepts::UnsignedIntegral<bool>);
}
```
Output:
```
true
false
```
