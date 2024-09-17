# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:False\<\>
Defined in fragment [xieite:concepts.False](../../../src/concepts/false.cpp)

&nbsp;

## Description
Specifies that a type trait has a falsy value. Requires that `Trait` is, indeed, a type trait.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Trait>
concept False = !static_cast<Trait::value>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::False<std::is_floating_point<int>>);
    std::println("{}", xieite::concepts::False<std::is_floating_point<false>>);
}
```
Output:
```
true
false
```
