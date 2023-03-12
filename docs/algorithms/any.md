# xieite::algorithms::any
Defined in header `<xieite/algorithms/any.hpp>`

<br/>

Checks whether at least one argument is true. Expects all arguments to be converible to a boolean value.

<br/><br/>

## Declarations
```cpp
template<std::convertible_to<bool>... TT>
[[nodiscard]]
constexpr bool any(TT&&... values) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::boolalpha, std::cout
#include <xieite/algorithms/any.hpp>

int main() {
	std::cout << std::boolalpha << xieite::algorithms::any(false, 0, '\0') << '\n';
}
```
Output:
```
false
```
