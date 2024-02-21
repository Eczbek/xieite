# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:ProcessGuard
Defined in header [<xieite/functors/process_guard.hpp"](../../../include/xieite/functors/process_guard.hpp)

&nbsp;

## Description
Executes a callback when the program ends.

&nbsp;

## Synopses
#### 1)
```cpp
struct ProcessGuard {
    template<std::invocable<> Functor>
    ProcessGuard(Functor);

    void release();
};
```
##### Member functions
- [ProcessGuard](./structures/process_guard/1/operators/constructor.md)
- [release](./structures/process_guard/1/release.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/functors/process_guard.hpp"

void foo() {
    xieite::functors::ProcessGuard guard([] {
        std::cout << "foo\n";
    });
}

int main() {
    foo();

    std::cout << "bar\n";
}
```
Output:
```
bar
foo
```
