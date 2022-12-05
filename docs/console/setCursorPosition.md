# xieite::console::setCursorPosition
Declared in `<xieite/console/setCursorPosition.hpp>`

<br/>

Sets the cursor's position.

<br/><br/>

## Declaration
```cpp
void setCursorPosition(const xieite::console::CursorPosition position) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/setCursorPosition.hpp>

int main() {
	xieite::console::setCursorPosition({ 2, 5 });
	std::cout << "Hello, world!\n";
}
```
Output:
```


     Hello, world!
```
