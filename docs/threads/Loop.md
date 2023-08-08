# [xieite](../xieite.md)\:\:[threads](../threads.md)\:\:Loop
Defined in header [<xieite/threads/Loop.hpp>](../../include/xieite/threads/Loop.hpp)

&nbsp;

## Description
Runs a callback constantly. Compile with `-pthread`

&nbsp;

## Synopsis
```cpp
struct Loop {
    template<std::invocable<> Invocable>
    Loop(const Invocable&);

    bool good() const;

    void stop();
};
```
#### Public members
## Contents
|- <a href="./Loop/constructor.md">Loop</a>
|- <a href="./Loop/good.md">good</a>
`- <a href="./Loop/stop.md">stop</a>

&nbsp;

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/Loop.hpp>

int main() {
    xieite::threads::Loop loop([] {
        static int i = 0;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        std::cout << ++i << '\n';
    });

    std::this_thread::sleep_for(std::chrono::seconds(5));
}
```
Possible output:
```
1
2
3
4
```
