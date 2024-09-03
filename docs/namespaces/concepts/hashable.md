# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Hashable\<\>
Defined in fragment [xieite:concepts.Hashable](../../../src/concepts/hashable.cpp)

&nbsp;

## Description
Specifies that a type is hashable.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, typename Hasher = std::hash<Type>>
concept Hashable = xieite::concepts::Invocable<Hasher, std::size_t(Type)>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::Hashable<int>);
    std::println("{}", xieite::concepts::Hashable<Nope>);
}
```
Output:
```
true
false
```
