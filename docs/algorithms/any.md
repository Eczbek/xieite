# gcufl::algorithms::any
Declared in `<gcufl/algorithms/any.hpp>`
```cpp
template<typename... T>
requires(requires(T... values) {
	{ (values || ...) } -> std::convertible_to<bool>;
}) constexpr bool any(const T&... values) noexcept;

template<typename... T>
constexpr bool any(const T&...) noexcept;
```
Checks whether at least one argument can be converted to a `true` boolean.
## Example
```cpp
#include <gcufl/algorithms/any.hpp>
#include <iostream>

int main() {
	std::cout << std::boolalpha << gcufl::algorithms::any(false, 0, '\0', "m") << '\n';
}
```
Output:
```
true
```
