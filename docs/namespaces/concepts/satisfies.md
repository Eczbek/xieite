# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Satisfies\<\>
Defined in fragment [xieite:concepts.Satisfies](../../../src/concepts/satisfies.cpp)

&nbsp;

## Description
Specifies that a type satisfies a lambda.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto validator, typename... Types>
concept Satisfies = requires { validator.template operator()<Types...>(); };
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::Satisfies<[]<std::integral> {}, int>);
    std::println("{}", xieite::concepts::Satisfies<[]<std::integral> {}, double>);
}
```
Output:
```
true
false
```
