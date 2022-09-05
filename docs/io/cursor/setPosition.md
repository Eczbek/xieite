# gcufl::io::cursor::setPosition
```cpp
void setPosition(const gcufl::io::Position position) noexcept;
```
Sets the terminal cursor position.
## Example
```cpp
#include <gcufl/io.hpp>
#include <iostream>

int main() {
	gcufl::io::cursor::setPosition({ 3, 4 });
	gcufl::io::Position position = gcufl::io::cursor::getPosition();
	
	std::cout << position.row << ' ' << position.column << '\n';
}
```
Possible output:
```
3 4
```
