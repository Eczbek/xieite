# [xieite](../../xieite.md)::[system](../../system.md)::[StandardStreamsController<inputStream, outputStream>](../StandardStreamsController.md)::clearScreen
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

<br/>

Clears the entire screen

<br/><br/>

## Synopsis

<br/>

```cpp
void clearScreen() noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/system/terminal.hpp>

int main() {
	std::cout << "Hello, world!\n";

	xieite::system::terminal.clearScreen();
}
```
Output:
```
```
