# [xieite](../../xieite.md)::[system](../../system.md)::[StandardStreamsController<inputStream, outputStream>](../StandardStreamsController.md)::setCursorPosition
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

<br/>

Sets the terminal cursor's position

<br/><br/>

## Synopsis

<br/>

```cpp
void setCursorPosition(xieite::system::OutputPosition position) noexcept;
```
### Parameters
- `position` - A `xieite::system::OutputPosition` copy, the new cursor coordinates

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/system/terminal.hpp>

int main() {
	xieite::system::terminal.setCursorPosition({ 2, 5 });
	std::cout << "Hello, world!\n";
}
```
Possible output:
```


     Hello, world!
```
