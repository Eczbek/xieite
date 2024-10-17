# [XIEITE](../../macros.md) \(loops\)
Defined in header [<xieite/loops.hpp>](../../../include/xieite/loops.hpp)

&nbsp;

## Description
Creates Python-style loops that allow appending an `else` block, except it only runs the `else` block if the loop is `break`'d within because it makes more sense to me like this. May create warnings in some cases if compiled with `-Wdangling-else`.

&nbsp;

## Synopsis
#### 1)
```cpp
#define for_if(...) /* ... */
```
#### 2)
```cpp
#define while_if(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/loops.hpp>

import std;

int main() {
    for_if (int i = 0; i < 10; ++i) {
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
