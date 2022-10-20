# gcufl::stream::read
Declared in `<gcufl/stream/read.hpp>`
```cpp
std::string read(std::istream& inputStream) noexcept;

[[nodiscard]]
std::string read(std::FILE* file) noexcept;
```
1. Reads entire contents of `std::ifstream`.
2. Reads a `std::FILE`.
## Example
```cpp
#include <gcufl/stream/read.hpp>
#include <fstream>
#include <iostream>

int main() {
	std::ifstream fileReadStream("./main.cpp");
	std::cout << gcufl::stream::read(fileReadStream) << '\n';
}
```
Possible output:
```
#include <gcufl/stream/read.hpp>
#include <fstream>
#include <iostream>

int main() {
	std::ifstream fileReadStream("./main.cpp");
	std::cout << gcufl::stream::read(fileReadStream) << '\n';
}
```
