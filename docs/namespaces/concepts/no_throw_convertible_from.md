# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleFrom\<\>
Defined in fragment [xieite:concepts.NoThrowConvertibleFrom](../../../src/concepts/no_throw_convertible_from.cpp)

&nbsp;

## Description
Specifies that a type can be converted from another type without throwing exceptions.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target, typename Source>
concept NoThrowConvertibleFrom = xieite::concepts::NoThrowConvertibleTo<Source, Target>;
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
    std::println("{}", xieite::concepts::NoThrowConvertibleFrom<int, double>);
    std::println("{}", xieite::concepts::NoThrowConvertibleFrom<int, Nope>);
}
```
Output:
```
true
false
```
