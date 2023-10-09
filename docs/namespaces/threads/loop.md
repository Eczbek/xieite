# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Loop
Defined in header [<xieite/threads/loop.hpp>](../../../include/xieite/threads/loop.hpp)

&nbsp;

## Description
Runs a callback constantly. Compile with `-pthread`.

&nbsp;

## Synopses
#### 1)
```cpp
struct Loop {
    template<std::invocable<> Functor>
    Loop(const Functor&);

    bool good() const;

    void stop();
};
```
##### Member functions
- [Loop](./structures/loop/1/operators/constructor.md)
- [good](./structures/loop/1/good.md)
- [stop](./structures/loop/1/stop.md)

&nbsp;

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/loop.hpp>

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
