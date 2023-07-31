# [xieite](../../xieite.md)::[system](../../system.md)::[StandardStreamsController<inputStream, outputStream>](../StandardStreamsController.md)::backspace
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
void backspace(std::size_t count) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/system/terminal.hpp>

int main() {
	std::cout << "Hello, world!";
	xieite::system::terminal.backspace(6);
	std::cout << "something\n";
}
```
Possible output:
```
Hello, something
```
