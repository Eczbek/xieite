# [xieite](../xieite.md)\:\:[functors](../functors.md)\:\:ProcessGuard
Defined in header [<xieite/functors/ProcessGuard.hpp>](../../include/xieite/functors/ProcessGuard.hpp)

&nbsp;

## Description
Executes a callback when the program ends

&nbsp;

## Synopsis
```cpp
struct ProcessGuard {
    template<std::invocable<> Invocable>
    ProcessGuard(const Invocable&);

    void release();
};
```
#### Public members
## Contents
|- <a href="./ProcessGuard/constructor.md">ProcessGuard</a>
`- <a href="./ProcessGuard/release.md">release</a>

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
