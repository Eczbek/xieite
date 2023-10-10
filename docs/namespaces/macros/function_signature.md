# [XIEITE](../../macros.md)\_FUNCTION\_SIGNATURE
Defined in header [<xieite/macros/function_signature.hpp>](../../../include/xieite/macros/function_signature.hpp)

&nbsp;

## Description
Gets the function's signature as a string. See header file for definitions.

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/function_signature.hpp>

int main() {
    std::cout << XIEITE_FUNCTION_SIGNATURE << '\n';
}
```
Possible output:
```
int main()
```
