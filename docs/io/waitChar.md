# gcufl::io::waitChar
```cpp
char waitChar(const bool echo = false) noexcept;
```
Waits for an input and then reads it. Doesn't wait for the next key, like `Enter`, to be pressed.
## Example
```cpp
#include <gcufl/io.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::io::waitChar() << '\n';
}
```
Possible output:
```
h
```
