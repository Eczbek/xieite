# gcufl::io::waitChar
```cpp
char waitChar(const bool echo = false) noexcept;
```
Waits for an input and then reads it. Doesn't wait for the next key, like Enter, to be pressed.
## Example
```cpp
#include <iostream>
#include <gcufl/io.hpp>

int main() {
	std::cout << gcufl::io::waitChar() << '\n';
}
```
Possible output:
```
h
```
