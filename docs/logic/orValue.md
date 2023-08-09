# [xieite](../xieite.md)\:\:[logic](../logic.md)\:\:orValue
Defined in header [<xieite/logic/orValue.hpp>](../../include/xieite/logic/orValue.hpp)

&nbsp;

## Description
Creates a short-circuit to return the first argument if it is true, or otherwise return the second argument.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::convertible_to<bool> Value>
constexpr Value& orValue(Value& value1, Value& value2)
noexcept(noexcept(std::is_nothrow_convertible_v<Value, bool>));
```
#### 2)
```cpp
template<std::convertible_to<bool> Value>
constexpr const Value& orValue(const Value& value1, const Value& value2)
noexcept(noexcept(std::is_nothrow_convertible_v<Value, bool>));
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/logic/orValue.hpp>

int main() {
    int x = 0;
    int y = 5;
    int z = 9;

    std::cout
        << xieite::logic::orValue(x, y) << '\n'
        << xieite::logic::orValue(y, z) << '\n';
}
```
Output:
```
5
5
```
