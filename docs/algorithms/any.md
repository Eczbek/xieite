# `xieite::algorithms::any`
Defined in header [`<xieite/algorithms/any.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/algorithms/any.hpp)

<br/>

Checks whether at least one passed argument is true. Expects all arguments to be converible to a boolean value.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr bool any(xieite::concepts::NoThrowConvertibleTo<bool> auto&&... values) noexcept;
```
### Parameters
- `values` - `auto` right-value references, satisfying `xieite::concepts::NoThrowConvertibleTo` of `bool`
### Return value
- A `bool` to represent whether or not all elements are true

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/algorithms/any.hpp>

int main() {
	std::cout << std::boolalpha
		<< xieite::algorithms::any(false, 0, '\0') << '\n';
}
```
Output:
```
false
```
