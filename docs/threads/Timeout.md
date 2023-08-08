# [xieite](../xieite.md)\:\:[threads](../threads.md)\:\:Timeout
Defined in header [<xieite/threads/Timeout.hpp>](../../include/xieite/threads/Timeout.hpp)

&nbsp;

## Description
Runs a callback once after a set amount of time. Compile with `-pthread`

&nbsp;

## Synopsis
```cpp
struct Timeout {
    template<std::invocable<> Invocable, xieite::concepts::ChronoDuration ChronoDuration>
    Timeout(const Invocable&, ChronoDuration) noexcept;

    bool good() const;

    void stop();
};
```
#### Public members
## Contents
|- <a href="./Timeout/constructor.md">Timeout</a>
|- <a href="./Timeout/good.md">good</a>
`- <a href="./Timeout/stop.md">stop</a>

&nbsp;

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/Timeout.hpp>

int main() {
    xieite::threads::Timeout timeout([] {
        std::cout << "Hello, world!\n";
    }, std::chrono::seconds(3));

    std::this_thread::sleep_for(std::chrono::seconds(1));

    timeout.stop();
}
```
Output:
```
```
