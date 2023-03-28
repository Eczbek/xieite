# xieite::console::move
Defined in header `<xieite/console/moveCursor.hpp>`

<br/>

Moves the cursor relatively. Use with `xieite::console::cursorControls`.

<br/><br/>

## Declarations
```cpp
constexpr std::string moveCursor(char control, int value) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/cursorControls.hpp>
#include <xieite/console/moveCursor.hpp>

int main() {
	std::cout
		<< xieite::console::moveCursor(xieite::console::cursorControls::right, 8)
		<< "Hello, world!\n";
}
```
Output:
```
        Hello, world!
```
