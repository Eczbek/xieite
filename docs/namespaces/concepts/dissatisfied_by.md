# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:DissatisfiedBy\<\>
Defined in fragment [xieite:concepts.DissatisfiedBy](../../../src/concepts/dissatisfied_by.cpp)

&nbsp;

## Description
Specifies that a lambda is dissatisfied by some types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto validator, typename... Types>
concept DissatisfiedBy = requires { validator.template operator()<Types...>(); };
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::DissatisfiedBy<[]<std::integral> {}, int>);
    std::println("{}", xieite::concepts::DissatisfiedBy<[]<std::integral> {}, double>);
}
```
Output:
```
false
true
```
