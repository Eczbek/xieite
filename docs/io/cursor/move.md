# gcufl::io::cursor::move
```cpp
void move(const char direction, const int count = 1) noexcept;
```
Moves the terminal cursor in some direction.
## Example
```cpp
#include <gcufl/io.hpp>
#include <iostream>

int main() {
	gcufl::io::Position position1 = gcufl::io::cursor::getPos();
	gcufl::io::cursor::move(gcufl::io::direction::Down, 3);
	gcufl::io::Position position2 = gcufl::io::cursor::getPos();

	std::cout << position1.row << ' ' << position1.column << '\n'
		<< position2.row << ' ' << position2.column << '\n';
}
```
Possible output:
```
0 0
3 0
```
