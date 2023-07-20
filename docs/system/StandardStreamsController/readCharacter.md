# [xieite](../../xieite.md)::[system](../../system.md)::[StandardStreamsController<inputStream, outputStream>](../StandardStreamsController.md)::readCharacter
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

<br/>

Waits for and returns the next keypress input

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
char readCharacter() noexcept;
```
### Return value
- A `char` - The input character

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/system/terminal.hpp>

int main() {
	std::cin.putback('h');

	std::cout << xieite::system::terminal.readCharacter() << '\n';
}
```
Output:
```
h
```
