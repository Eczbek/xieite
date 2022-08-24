# gcufl::io::cursor::getPosition
```cpp
gcufl::io::Position getPosition() noexcept;
```
Gets the terminal cursor position.
## Example
```cpp
#include <iostream>
#include <gcufl/io.hpp>

int main() {
	gcufl::io::Position position = gcufl::io::cursor::getPosition();

	std::cout << position.row << ' ' << position.column << '\n';
}
```
Possible output:
```
0 0
```
