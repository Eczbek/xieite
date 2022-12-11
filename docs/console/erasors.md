# xieite::console::erasors
Declared in `<xieite/console/erasors.hpp>`

<br/>

A namespace of console text erasors.

<br/><br/>

## Definitions
```cpp
constexpr std::string_view screenFromCursor = "\x1b[0J";
```
```cpp
constexpr std::string_view screenUntilCursor = "\x1b[1J";
```
```cpp
constexpr std::string_view screen = "\x1b[2J";
```
```cpp
constexpr std::string_view lineFromCursor = "\x1b[0K";
```
```cpp
constexpr std::string_view lineUntilCursor = "\x1b[1K";
```
```cpp
constexpr std::string_view line = "\x1b[2K";
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/erasors.hpp>

int main() {
	std::cout
		<< "Hello, "
		<< xieite::console::erasors::line
		<< "world!\n";
}
```
Output:
```
       world!
```
