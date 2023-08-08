# [xieite](../xieite.md)\:\:[logic](../logic.md)\:\:orValue
Defined in header [<xieite/logic/orValue.hpp>](../../include/xieite/logic/orValue.hpp)

&nbsp;

## Description
Creates a short-circuit to return the first argument if it is true, or otherwise return the second argument

&nbsp;

## Synopses

&nbsp;

```cpp
template<std::convertible_to<bool> Value>
[[nodiscard]]
constexpr Value& orValue(Value& value1, Value& value2)
noexcept(noexcept(std::is_nothrow_convertible_v<Value, bool>));
```
#### Template parameters
- `Value` - A type satisfying `std::convertible_to` of `bool`
#### Function parameters
- `value1` - A `Value` reference
- `value2` - A `Value` reference
#### Return type
- `Value` reference to either `value1` or `value2`

&nbsp;

```cpp
template<std::convertible_to<bool> Value>
[[nodiscard]]
constexpr const Value& orValue(const Value& value1, const Value& value2)
noexcept(noexcept(std::is_nothrow_convertible_v<Value, bool>));
```
#### Template parameters
- `Value` - A type satisfying `std::convertible_to` of `bool`
#### Function parameters
- `value1` - A constant `Value` reference
- `value2` - A constant `Value` reference
#### Return type
- constant `Value` reference to either `value1` or `value2`

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
