# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Volatile\<\>
Defined in fragment [xieite:concepts.Volatile](../../../src/concepts/volatile.cpp)

&nbsp;

## Description
Specifies that a type is volatile, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Volatile = std::is_volatile_v<std::remove_reference_t<Type>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::Volatile<volatile int>);
    std::println("{}", xieite::concepts::Volatile<int>);
    std::println("{}", xieite::concepts::Volatile<volatile int&>);
}
```
Output:
```
true
false
true
```
