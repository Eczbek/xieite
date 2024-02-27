# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Loop
Defined in header [<xieite/threads/loop.hpp>](../../../include/xieite/threads/loop.hpp)

&nbsp;

## Description
Runs a callback constantly. Compile with `-pthread`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Loop {
    template<std::invocable<> Functor>
    Loop(const Functor&);

    operator bool() const;

    void stop();
};
```
##### Member functions
- [Loop](./structures/loop/1/operators/constructor.md)
- [operator typename](./structures/loop/1/operators/cast.md)
- [stop](./structures/loop/1/stop.md)

&nbsp;

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include "xieite/threads/loop.hpp"

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
