# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Hasher\<\>
Defined in fragment [xieite:concepts.Hasher](../../../src/concepts/hasher.cpp)

&nbsp;

## Description
Specifies that a type is a functor for hashing values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, typename Argument>
concept Hasher = xieite::concepts::Invocable<Type, std::size_t(Argument)>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

template<typename>
struct Nope {};

int main() {
    std::println("{}", xieite::concepts::Hasher<std::hash, int>);
    std::println("{}", xieite::concepts::Hasher<Nope, int>);
}
```
Output:
```
true
false
```
