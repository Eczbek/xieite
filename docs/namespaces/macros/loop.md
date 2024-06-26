# [XIEITE](../../macros.md)\_LOOP\_...\(\)
Defined in header [<xieite/macros/loop.hpp>](../../../include/xieite/macros/loop.hpp)

&nbsp;

## Description
Creates a Python-style loop that allows appending an `else` block, except it only runs the `else` block if the loop is `break`'d within because it makes more sense to me like this. May create warnings if compiled with `-Wdangling-else`.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_LOOP_FOR(...) /* ... */
```
#### 2)
```cpp
#define XIEITE_LOOP_WHILE(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/for.hpp"

int main() {
    XIEITE_LOOP_FOR (int i = 0; i < 10; ++i) {
        if (i == 5) {
            break;
        }
    } else {
        std::println("Break detected!");
    }
}
```
Output:
```
Break detected!
```
