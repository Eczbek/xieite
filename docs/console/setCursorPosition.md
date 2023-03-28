# xieite::console::setCursorPosition
Defined in header `<xieite/console/setCursorPosition.hpp>`

<br/>

Sets the terminal cursor's absolute position.

<br/><br/>

## Declarations
```cpp
constexpr std::string setCursorPosition(xieite::console::CursorPosition position) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/setCursorPosition.hpp>

int main() {
	std::cout
		<< xieite::console::setCursorPosition({ 2, 5 })
		<< "Hello, world!\n";
}
```
Output:
```


     Hello, world!
```
