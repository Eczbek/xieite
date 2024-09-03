# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Pointer\<\>
Defined in fragment [xieite:concepts.Pointer](../../../src/concepts/pointer.cpp)

&nbsp;

## Description
Specifies that a type is a pointer, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Pointer = std::is_pointer_v<std::remove_reference_t<Type>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::Pointer<int>);
    std::println("{}", xieite::concepts::Pointer<int*>);
    std::println("{}", xieite::concepts::Pointer<int*&>);
}
```
Output:
```
false
true
true
```
