# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SatisfiedBy\<\>
Defined in fragment [xieite:concepts.SatisfiedBy](../../../src/concepts/satisfied_by.cpp)

&nbsp;

## Description
Specifies that a lambda is satisfied by some types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto validator, typename... Types>
concept SatisfiedBy = requires { validator.template operator()<Types...>(); };
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::SatisfiedBy<[]<std::integral> {}, int>);
    std::println("{}", xieite::concepts::SatisfiedBy<[]<std::integral> {}, double>);
}
```
Output:
```
true
false
```
