# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleFromAll\<\>
Defined in fragment [xieite:concepts.NoThrowConvertibleFromAll](../../../src/concepts/no_throw_convertible_from_all.cpp)

&nbsp;

## Description
Specifies that a type can be converted from all of several other types without throwing exceptions. Passing no target types evaluates from `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target, typename... Sources>
concept NoThrowConvertibleFromAll = (... && xieite::concepts::NoThrowConvertibleFrom<Target, Sources>);
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
    std::println("{}", xieite::concepts::NoThrowConvertibleFromAll<int, double, char, unsigned long long int>);
    std::println("{}", xieite::concepts::NoThrowConvertibleFromAll<int, void*, Nope, decltype([] {})>);
}
```
Output:
```
true
false
```
