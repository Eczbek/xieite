# xieite::console::getArrowKey
Defined in header `<xieite/console/getArrowKey.hpp>`

<br/>

Waits for an arrow key input and returns its code immediately.

```
'A' = up
'B' = down
'C' = right
'D' = left
0 = none
```

<br/><br/>

## Declarations
```cpp
inline char getArrowKey(const bool echo = false) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/getArrowKey.hpp>

int main() {
	std::cout << xieite::console::getArrowKey() << '\n';
}
```
Possible interaction:
```
A
```
