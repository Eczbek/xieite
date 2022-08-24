# gcufl::io::cursor::setPos
```cpp
void setPos(const gcufl::io::Position position) noexcept;
```
Sets the terminal cursor position.
## Example
```cpp
#include <iostream>
#include <gcufl/io.hpp>

int main() {
	gcufl::io::cursor::setPos({ 3, 4 });

	gcufl::io::Position position = gcufl::io::cursor::getPos();
	std::cout << position.row << ' ' << position.column << '\n';
}
```
Possible output:
```
3 4
```
