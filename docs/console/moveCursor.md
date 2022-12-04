# xieite::console::move
Declared in `<xieite/console/moveCursor.hpp>`

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
#include <xieite/console/directions.hpp>
#include <xieite/console/moveCursor.hpp>

int main() {
	xieite::console::move(xieite::console::directions::right, 8);
	std::cout << "Hello, world!\n";
}
```
Output:
```
        Hello, world!
```
