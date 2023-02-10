# xieite::console::setCursorPosition
Declared in `<xieite/console/setCursorPosition.hpp>`

<br/>

Sets the cursor's position.

<br/><br/>

## Declaration
```cpp
constexpr std::string setCursorPosition(const xieite::console::CursorPosition position) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
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
