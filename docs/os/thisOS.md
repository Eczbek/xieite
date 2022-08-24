# gcufl::thisOS
```cpp
#if defined(_WIN32) || defined(__WINDOWS__)
	constexpr auto thisOS = gcufl::os::Windows;
#elif defined(__APPLE__) || defined(__MACH__)
	constexpr auto thisOS = gcufl::os::Mac;
#elif defined(__unix__) || defined(__unix)
	constexpr auto thisOS = gcufl::os::Unix;
#endif
```
An operating-system dependant constant.
## Example
```cpp
#include <iostream>
#include <gcufl/os.hpp>

int main() {
	switch (gcufl::thisOS) {
		case gcufl::os::Windows:
			std::cout << "Windows\n";
			break;
		case gcufl::os::Max:
			std::cout << "Mac\n";
			break;
		case gcufl::os::Unix:
			std::cout << "Unix\n";
			break;
	}
}
```
Possible output:
```
Unix
```
