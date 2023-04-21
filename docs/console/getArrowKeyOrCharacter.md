# [`xieite`](../../README.md)`::`[`console`](../../docs/console.md)`::getArrowKeyOrCharacter`
Defined in header [`<xieite/console/getArrowKeyOrCharacter.hpp>`](../../include/xieite/console/getArrowKeyOrCharacter.hpp)

<br/>

Waits for a character or an arrow key input and immediately returns it.

<br/><br/>

## Synopsis

<br/>

```cpp
inline std::variant<char, xieite::console::Position> getArrowKeyOrCharacter(bool echo = false) noexcept;
```
### Parameters
- `echo` - A `bool` copy to specify if echoing should be enabled while waiting for input
### Return value
- A `std::variant` of `char` and `xieite::console::Position`, a single character or an arrow key's direction represented as one of four cardinal directions or `{ 0, 0 }` if the input is not a valid arrow key code

<br/><br/>

## Example
```cpp
#include <iostream>
#include <variant>
#include <xieite/console/Position.hpp>
#include <xieite/console/getArrowKeyOrCharacter.hpp>

int main() {
	std::cin.putback('e');

	std::variant<char, xieite::console::Position> input = xieite::console::getArrowKeyOrCharacter();

	if (std::holds_alternative<char>(input)) {
		std::cout << std::get<char>(input) << '\n';
	} else {
		xieite::console::Position position = std::get<xieite::console::Position>(input);
		std::cout << '(' << position.row << ", " << position.column << ")\n";
	}
}
```
Output:
```
e
```

<br/><br/>

## See also
- [`xieite::console::Position`](../../docs/console/Position.md)
