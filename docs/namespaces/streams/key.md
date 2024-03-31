# [xieite](../../../xieite.md)\:\:[streams](../../../streams.md)\:\:Key \{\}
Defined in header [<xieite/streams/key.hpp>](../../../include/xieite/streams/key.hpp)

&nbsp;

## Description
An enumeration of input keys. See header file for definitions.

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/key.hpp"

int main() {
    std::println("{}", xieite::streams::Key::NumpadDigit0 == xieite::streams::Key::Insert);
}
```
Output:
```
true
```
