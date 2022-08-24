# gcufl::io::style
A namespace of constant ANSI styles.
Some styles may be stacked.
## Example
```cpp
#include <iostream>
#include <gcufl/io.hpp>

int main() {
	std::cout << gcufl::io::style::fg::brightRed << "Hello, world!\n";
}
```
Output (in red color):
```
Hello, world!
```
