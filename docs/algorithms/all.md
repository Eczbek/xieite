# xieite::algorithms::all
Declared in `<xieite/algorithms/all.hpp>`
```cpp
template<typename... T>
requires(requires(T... values) {
	{ (values && ...) } -> std::convertible_to<bool>;
})
[[nodiscard]]
constexpr bool all(const T&... values) noexcept;

template<typename... T>
[[nodiscard]]
constexpr bool all(const T&...) noexcept;
```
Checks whether all arguments can be converted to a `true` boolean.
## Example
```cpp
#include <iostream>
#include <xieite/algorithms/all.hpp>

int main() {
	std::cout << std::boolalpha << xieite::algorithms::all("h", 4, true, '$') << '\n';
}
```
Output:
```
true
```
