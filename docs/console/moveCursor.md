# xieite::console::move
Defined in header `<xieite/console/moveCursor.hpp>`

<br/>

Moves the cursor relatively. Use with `xieite::console::cursor`.

<br/><br/>

## Declarations
```cpp
constexpr std::string moveCursor(char control, int value) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/cursor.hpp>
#include <xieite/console/moveCursor.hpp>

int main() {
	std::cout
		<< xieite::console::moveCursor(xieite::console::cursor::right, 8)
		<< "Hello, world!\n";
}
```
Output:
```
        Hello, world!
```
