# gcufl::fs::read
```cpp
std::string read(const std::string& path) noexcept;
```
Reads the content of a file into a `std::string`.
If the file does not exist, returns `""`.
## Example
```cpp
#include <iostream>
#include <fstream>
#include <gcufl/fs>

int main() {
	std::string path = "./test.txt";

	std::ofstream writer(path);
	if (writer)
		writer << "Hello, world!\n";

	std::cout << gcufl::fs::read(path);
}
```
Output:
```
Hello, world!
```
