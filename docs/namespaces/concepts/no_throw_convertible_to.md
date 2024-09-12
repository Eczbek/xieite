# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleTo\<\>
Defined in fragment [xieite:concepts.NoThrowConvertibleTo](../../../src/concepts/no_throw_convertible_to.cpp)

&nbsp;

## Description
Specifies that a type can be converted to another without throwing exceptions.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename Target>
concept NoThrowConvertibleTo = std::is_nothrow_convertible_v<Source, Target> && requires { static_cast<Target>(std::declval<Source>()); };
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
    std::println("{}", xieite::concepts::NoThrowConvertibleTo<double, int>);
    std::println("{}", xieite::concepts::NoThrowConvertibleTo<Nope, int>);
}
```
Output:
```
true
false
```
