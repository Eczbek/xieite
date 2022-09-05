# gcufl::is
```cpp
template <gcufl::os::type>
constexpr bool is = false;

#if defined(_WIN32) || defined(__WINDOWS__)
template <>
constexpr bool is<gcufl::os::type::Windows> = true;
#endif

#if defined(__APPLE__) || defined(__MACH__)
template <>
constexpr bool is<gcufl::os::type::Mac> = true;
#endif

#if defined(__unix__) || defined(__unix)
template <>
constexpr bool is<gcufl::os::type::Unix> = true;
#endif
```
An operating-system dependant constant.
## Example
```cpp
#include <gcufl/os.hpp>
#include <iostream>

int main() {
	std::cout << std::boolalpha << gcufl::os::is<gcufl::os::type::Unix> << '\n';
}
```
Possible output:
```
true
```
