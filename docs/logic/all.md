# [xieite](../xieite.md)::[logic](../logic.md)::all
Defined in header [<xieite/logic/all.hpp>](../../include/xieite/logic/all.hpp)

<br/>

Checks whether all passed arguments are true. Expects all arguments to be converible to a boolean value

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::convertible_to<bool>... Values>
[[nodiscard]]
constexpr bool all(const Values&... values)
noexcept(noexcept((std::is_nothrow_convertible_v<Values, bool> && ...)));
```
### Template parameters
- `Values...` - Types satisfying `std::convertible_to` of `bool`
### Parameters
- `values...` - `Values...` constant references
### Return value
- A `bool` to represent whether or not all elements are true

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/logic/all.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< xieite::logic::all(4, true, '$') << '\n';
}
```
Output:
```
true
```
