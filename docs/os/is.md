# gcufl::os::is
Defined in `<gcufl/os/is.hpp>`
<br/><br/>
```cpp
template <gcufl::os::Type>
constexpr bool is = false;

#if defined(_WIN32) || defined(__WINDOWS__)
template <>
constexpr bool is<gcufl::os::Type::Windows> = true;
#endif

#if defined(__APPLE__) || defined(__MACH__)
template <>
constexpr bool is<gcufl::os::Type::Mac> = true;
#endif

#if defined(__unix__) || defined(__unix)
template <>
constexpr bool is<gcufl::os::Type::Unix> = true;
#endif
```
Specifies the operating system on which it is compiled.
<br/>
It depends on the macros provided by the compiler.
## Example
```cpp
#include <gcufl/os/is.hpp>
#include <gcufl/os/Type.hpp>
#include <iostream>

int main() {
	if (gcufl::os::is<gcufl::os::Type::Windows>)
		std::cout << "Windows\n";
	else if (gcufl::os::is<gcufl::os::Type::Mac>)
		std::cout << "Mac\n";
	else if (gcufl::os::is<gcufl::os::Type::Unix>)
		std::cout << "Unix\n";
}
```
Possible output:
```
Unix
```
