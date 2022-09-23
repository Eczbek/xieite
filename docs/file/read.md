# gcufl::file::read
Declared in `<gcufl/file/read.hpp>`
```cpp
std::string read(const std::string& path) noexcept;
```
Reads the content of a file into a `std::string`.
## Example
```cpp
#include <gcufl/file/read.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::file::read("./main.cpp") << '\n';
}
```
Possible output:
```
#include <gcufl/file/read.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::file::read("./main.cpp") << '\n';
}
```
