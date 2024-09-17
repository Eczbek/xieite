# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:True\<\>
Defined in fragment [xieite:concepts.True](../../../src/concepts/true.cpp)

&nbsp;

## Description
Specifies that a type trait has a truthy value. Requires that `Trait` is, indeed, a type trait.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Trait>
concept True = static_cast<Trait::value>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::True<std::is_integral<int>>);
    std::println("{}", xieite::concepts::True<std::is_integral<false>>);
}
```
Output:
```
true
false
```
