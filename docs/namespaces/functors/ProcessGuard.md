# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:ProcessGuard
Defined in header [<xieite/functors/ProcessGuard.hpp>](../../../include/xieite/functors/ProcessGuard.hpp)

&nbsp;

## Description
Executes a callback when the program ends.

&nbsp;

## Synopses
#### 1)
```cpp
struct ProcessGuard {
    template<std::invocable<> Invocable>
    ProcessGuard(const Invocable&);

    void release();
};
```
##### Member functions
- [ProcessGuard](./structures/ProcessGuard/1/operators/constructor.md)
- [release](./structures/ProcessGuard/1/release.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/functors/ProcessGuard.hpp>

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
