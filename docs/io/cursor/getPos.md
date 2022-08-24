# gcufl::io::cursor::getPos
```cpp
gcufl::io::Position getPos() noexcept;
```
Gets the terminal cursor position.
## Example
```cpp
#include <iostream>
#include <gcufl/io.hpp>

int main() {
	gcufl::io::Position position = gcufl::io::cursor::getPos();

	std::cout << position.row << ' ' << position.column << '\n';
}
```
Possible output:
```
0 0
```
