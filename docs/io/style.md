# gcufl::io::style
A namespace of constant ANSI styles.
Some styles may be combined.
## Example
```cpp
#include <gcufl/io.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::io::style::fg::brightRed << "Hello, world!\n";
}
```
Output (in bright-red color):
```
Hello, world!
```
