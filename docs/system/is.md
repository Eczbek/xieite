# gcufl::system::is
Declared in `<gcufl/system/is.hpp>`
```cpp
template<gcufl::system::Type>
constexpr bool is = false;

#if defined(_WIN32) || defined(__WINDOWS__)
template<>
constexpr bool is<gcufl::system::Type::Windows> = true;
#endif

#if defined(__APPLE__) || defined(__MACH__)
template<>
constexpr bool is<gcufl::system::Type::Mac> = true;
#endif

#if defined(__unix__) || defined(__unix)
template<>
constexpr bool is<gcufl::system::Type::Unix> = true;
#endif
```
Specifies the operating system on which it is compiled.
<br/>
It depends on macros provided by the compiler.
## Example
```cpp
#include <gcufl/system/is.hpp>
#include <gcufl/system/Type.hpp>
#include <iostream>

int main() {
	if (gcufl::system::is<gcufl::system::Type::Windows>)
		std::cout << "Windows\n";
	else if (gcufl::system::is<gcufl::system::Type::Mac>)
		std::cout << "Mac\n";
	else if (gcufl::system::is<gcufl::system::Type::Unix>)
		std::cout << "Unix\n";
}
```
Possible output:
```
Unix
```
