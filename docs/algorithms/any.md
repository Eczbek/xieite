# xieite::algorithms::any
Declared in `<xieite/algorithms/any.hpp>`

<br/>

Checks whether at least one argument can be converted to a `true` boolean.

<br/><br/>

## Declarations
```cpp
template<typename... T>
requires(requires(T... values) {
	{ (values || ...) } -> std::convertible_to<bool>;
})
[[nodiscard]]
constexpr bool any(const T&... values) noexcept;
```
```cpp
template<typename... T>
[[nodiscard]]
constexpr bool any(const T&...) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/algorithms/any.hpp>

int main() {
	std::cout << std::boolalpha << xieite::algorithms::any(false, 0, '\0', "m") << '\n';
}
```
Output:
```
true
```
