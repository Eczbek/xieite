# [xieite](../xieite.md)::[algorithms](../algorithms.md)::andValue
Defined in header [<xieite/algorithms/andValue.hpp>](../../include/xieite/algorithms/andValue.hpp)

<br/>

Creates a short-circuit to return the first argument if it is false, or otherwise return the second argument

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<std::convertible_to<bool> Value>
[[nodiscard]]
constexpr Value& andValue(Value& value1, Value& value2)
noexcept(noexcept(std::is_nothrow_convertible_v<Value, bool>));
```
### Template parameters
- `Value` - A type satisfying `std::convertible_to` of `bool`
### Parameters
- `value1` - A `Value` reference
- `value2` - A `Value` reference
### Return value
- A `Value` reference to either `value1` or `value2`

<br/><br/>

```cpp
template<std::convertible_to<bool> Value>
[[nodiscard]]
constexpr const Value& andValue(const Value& value1, const Value& value2)
noexcept(noexcept(std::is_nothrow_convertible_v<Value, bool>));
```
### Template parameters
- `Value` - A type satisfying `std::convertible_to` of `bool`
### Parameters
- `value1` - A constant `Value` reference
- `value2` - A constant `Value` reference
### Return value
- A constant `Value` reference to either `value1` or `value2`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/algorithms/andValue.hpp>

int main() {
	int x = 0;
	int y = 5;
	int z = 9;

	std::cout
		<< xieite::algorithms::andValue(x, y) << '\n'
		<< xieite::algorithms::andValue(y, z) << '\n';
}
```
Output:
```
0
9
```
