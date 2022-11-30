# xieite::console::cursor::move
Declared in `<xieite/console/cursor/move.hpp>`

<br/>

Moves the cursor.

<br/><br/>

## Declaration
```cpp
void move(const char direction, const int distance = 1) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/cursor/directions.hpp>
#include <xieite/console/cursor/move.hpp>

int main() {
	xieite::console::cursor::move(xieite::console::cursor::directions::right, 8);
	std::cout << "Hello, world!\n";
}
```
Output:
```
        Hello, world!
```
