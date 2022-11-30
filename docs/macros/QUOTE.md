# GCUFL_QUOTE
Declared in `<xieite/macros/QUOTE.hpp>`

<br/>

Converts an expression to a string literally.

<br/><br/>

## Definition
```cpp
#define GCUFL_QUOTE(x) #x
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/QUOTE.hpp>

int main() {
	std::cout << GCUFL_QUOTE(2 + 2) << '\n';
}
```
Output:
```
2 + 2
```
