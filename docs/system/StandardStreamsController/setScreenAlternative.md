# [xieite](../../xieite.md)::[system](../../system.md)::[StandardStreamsController<inputStream, outputStream>](../StandardStreamsController.md)::setScreenAlternative
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

<br/>

Enables or disables the alternative screen

<br/><br/>

## Synopsis

<br/>

```cpp
void setScreenAlternative(bool value) noexcept;
```
### Parameters
- `value` - A `bool` to determine whether to save or restore the screen

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/system/terminal.hpp>

int main() {
	xieite::system::terminal.setScreenAlternative(true);
	std::cout << "Hello, ";
	xieite::system::terminal.setScreenAlternative(false);
	std::cout << "world!\n";
}
```
Output:
```
world!
```
