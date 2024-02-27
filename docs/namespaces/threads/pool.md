# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Pool
Defined in header [<xieite/threads/pool.hpp>](../../../include/xieite/threads/pool.hpp)

&nbsp;

## Description
Creates a "pool" of threads for distributing jobs between. Compile with `-pthread`.

&nbsp;

## Synopsis
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
- [Pool](./structures/pool/1/operators/constructor.md)
- [setThreadCount](./structures/pool/1/set_thread_count.md)
- [getThreadCount](./structures/pool/1/get_thread_count.md)
- [enqueue](./structures/pool/1/enqueue.md)

&nbsp;

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include "xieite/threads/pool.hpp"

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
