# gcufl::fs::read
Declared in `<gcufl/fs/read.hpp>`
```cpp
std::string read(const std::string& path) noexcept;
```
Reads the content of a file into a `std::string`.
## Example
```cpp
#include <gcufl/fs/read.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::fs::read("./main.cpp") << '\n';
}
```
Possible output:
```
#include <gcufl/fs/read.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::fs::read("./main.cpp") << '\n';
}
```
