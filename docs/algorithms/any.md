# xieite::algorithms::any
Declared in `<xieite/algorithms/any.hpp>`

<br/>

Checks whether at least one argument is `true`.

<br/><br/>

## Declarations
```cpp
template<std::convertible_to<bool>... T>
[[nodiscard]]
constexpr bool any(const T&... values) noexcept;
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
