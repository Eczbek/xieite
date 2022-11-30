# GCUFL_CONCAT
Declared in `<xieite/macros/CONCAT.hpp>`

<br/>

Combines two values.

<br/><br/>

## Definition
```cpp
#define GCUFL_CONCAT(x, y) GCUFL_CONCAT_PRIMITIVE(x, y)
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/CONCAT.hpp>

int main() {
	std::cout << (GCUFL_CONCAT(4, 5) + 1) << '\n';
}
```
Output:
```
46
```
