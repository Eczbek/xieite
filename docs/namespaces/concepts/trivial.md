# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Trivial\<\>
Defined in fragment [xieite:concepts.Trivial](../../../src/concepts/trivial.cpp)

&nbsp;

## Description
Specifies that a type is trivial.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Trivial = std::is_trivial_v<Type>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {
    Nope(const Nope&) = delete;
};

int main() {
    std::println("{}", xieite::concepts::Trivial<int*[]>);
    std::println("{}", xieite::concepts::Trivial<Nope>);
}
```
Output:
```
true
false
```
