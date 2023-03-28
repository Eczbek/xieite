# xieite::algorithms::all
Defined in header `<xieite/algorithms/all.hpp>`

<br/>

Checks whether all arguments are true. Expects all arguments to be converible to a boolean value.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr bool all(std::convertible_to<bool> auto&&... values) noexcept;
```

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
