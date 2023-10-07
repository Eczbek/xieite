# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Loop
Defined in header [<xieite/threads/Loop.hpp>](../../../include/xieite/threads/Loop.hpp)

&nbsp;

## Description
Runs a callback constantly. Compile with `-pthread`.

&nbsp;

## Synopses
#### 1)
```cpp
struct Loop {
    template<std::invocable<> Invocable>
    Loop(const Invocable&);

    bool good() const;

    void stop();
};
```
##### Member functions
- [Loop](./structures/Loop/1/operators/constructor.md)
- [good](./structures/Loop/1/good.md)
- [stop](./structures/Loop/1/stop.md)

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
