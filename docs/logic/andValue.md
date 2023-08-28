# [xieite](../xieite.md)\:\:[logic](../logic.md)\:\:andValue
Defined in header [<xieite/logic/andValue.hpp>](../../include/xieite/logic/andValue.hpp)

&nbsp;

## Description
Creates a short-circuit to return the first argument if it is false, or otherwise return the second argument.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::convertible_to<bool> Value>
constexpr Value& andValue(Value& value1, Value& value2)
noexcept(noexcept(std::xieite::concepts::NoThrowConvertibleTo<Value, bool>));
```
#### 2)
```cpp
template<std::convertible_to<bool> Value>
constexpr const Value& andValue(const Value& value1, const Value& value2)
noexcept(noexcept(std::xieite::concepts::NoThrowConvertibleTo<Value, bool>));
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/logic/andValue.hpp>

int main() {
    int x = 0;
    int y = 5;
    int z = 9;

    std::cout
        << xieite::logic::andValue(x, y) << '\n'
        << xieite::logic::andValue(y, z) << '\n';
}
```
Output:
```
0
9
```
