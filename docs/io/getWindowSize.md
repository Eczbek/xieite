# gcufl::io::getWindowSize
```cpp
gcufl::io::Position getWindowSize() noexcept;
```
Gets the terminal window size.
## Example
```cpp
#include <iostream>
#include <gcufl/io.hpp>

int main() {
	gcufl::io::Position size = gcufl::io::getWindowSize();

	std::cout << size.row << ' ' << size.column << '\n';
}
```
Possible output:
```
24 70
```
