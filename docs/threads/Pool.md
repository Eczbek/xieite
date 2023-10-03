# [xieite](../xieite.md)\:\:[threads](../threads.md)\:\:Pool
Defined in header [<xieite/threads/Pool.hpp>](../../include/xieite/threads/Pool.hpp)

&nbsp;

## Description
Creates a "pool" of threads for distributing jobs between. Compile with `-pthread`.

&nbsp;

## Synopses
#### 1)
```cpp
struct Pool {
    Pool(std::size_t = std::thread::hardware_concurrency());

    void setThreadCount(std::size_t);

    std::size_t getThreadCount();

    void enqueue(const std::function<void()>&);
};
```
##### Member functions
- [Pool](./Pool/1/operators/constructor.md)
- [setThreadCount](./Pool/1/setThreadCount.md)
- [getThreadCount](./Pool/1/getThreadCount.md)
- [enqueue](./Pool/1/enqueue.md)

&nbsp;

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/Pool.hpp>

int main() {
    xieite::threads::Pool loop([] {
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
