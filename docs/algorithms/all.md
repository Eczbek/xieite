# `xieite::algorithms::all`
Defined in header [`<xieite/algorithms/all.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/algorithms/all.hpp)

<br/>

Checks whether all passed arguments are true. Expects all arguments to be converible to a boolean value.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr bool all(xieite::concepts::NoThrowConvertibleTo<bool> auto&&... values) noexcept;
```
### Parameters
- `values` - `auto` right-value references, satisfying `xieite::concepts::NoThrowConvertibleTo` of `bool`
### Return value
- A `bool` to represent whether or not all elements are true

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/algorithms/all.hpp>

int main() {
	std::cout << std::boolalpha
		<< xieite::algorithms::all(4, true, '$') << '\n';
}
```
Output:
```
true
```
