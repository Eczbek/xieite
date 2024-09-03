# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Enumeration\<\>
Defined in fragment [xieite:concepts.Enumeration](../../../src/concepts/enumeration.cpp)

&nbsp;

## Description
Specifies that a type is an enumeration.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Enumeration = std::is_enum_v<Type>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo {};

enum Bar {};

int main() {
    std::println("{}", xieite::concepts::Enumeration<Foo>);
    std::println("{}", xieite::concepts::Enumeration<Bar>);
}
```
Output:
```
false
true
```
