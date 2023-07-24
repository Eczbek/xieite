# [xieite](../xieite.md)::[algorithms](../algorithms.md)::any
Defined in header [<xieite/algorithms/any.hpp>](../../include/xieite/algorithms/any.hpp)

<br/>

Checks whether at least one passed argument is true. Expects all arguments to be converible to a boolean value

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::convertible_to<bool>... Booleanables>
[[nodiscard]]
constexpr bool any(const Booleanables&... values)
noexcept(noexcept((std::is_nothrow_convertible_v<Booleanables, bool> && ...)));
```
### Template parameters
- `Booleanables...` - Types satisfying `std::convertible_to` of `bool`
### Parameters
- `values...` - `Booleanables...` constant references
### Return value
- A `bool` to represent whether or not all elements are true

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/algorithms/any.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< xieite::algorithms::any(false, 0, '\0') << '\n';
}
```
Output:
```
false
```
