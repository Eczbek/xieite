# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleFromAny\<\>
Defined in fragment [xieite:concepts.NoThrowConvertibleFromAny](../../../src/concepts/no_throw_convertible_from_any.cpp)

&nbsp;

## Description
Specifies that a type can be converted from at least one of several other types without throwing exceptions. Passing no target types evaluates from `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target, typename... Sources>
concept NoThrowConvertibleFromAny = (... || xieite::concepts::NoThrowConvertibleFrom<Target, Sources>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {
    operator int() {
        throw std::runtime_error("nope");
    }
};

int main() {
    std::println("{}", xieite::concepts::NoThrowConvertibleFromAny<int, double, char, unsigned long long int>);
    std::println("{}", xieite::concepts::NoThrowConvertibleFromAny<int, void*, Nope, decltype([] {})>);
}
```
Output:
```
true
false
```
