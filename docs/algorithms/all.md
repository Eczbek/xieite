# [xieite](../xieite.md)::[algorithms](../algorithms.md)::all
Defined in header [<xieite/algorithms/all.hpp>](../../include/xieite/algorithms/all.hpp)

<br/>

Checks whether all passed arguments are true. Expects all arguments to be converible to a boolean value

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::convertible_to<bool>... Booleanables>
[[nodiscard]]
constexpr bool all(const Booleanables&... values)
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
#include <xieite/algorithms/all.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< xieite::algorithms::all(4, true, '$') << '\n';
}
```
Output:
```
true
```
