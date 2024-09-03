# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Pool \{\}
Defined in fragment [xieite:threads.Pool](../../../src/threads/pool.cpp)

&nbsp;

## Description
Creates a "pool" of threads for distributing jobs between.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Pool {
    Pool(std::size_t = std::thread::hardware_concurrency()) noexcept;

    void setThreadCount(std::size_t) noexcept;

    std::size_t getThreadCount() const noexcept;

    template<std::invocable<> Functor>
    void enqueue(Functor&&) noexcept;
};
```
- [Pool\(\)](./structures/pool/1/operators/constructor.md)
- [setThreadCount\(\)](./structures/pool/1/set_thread_count.md)
- [getThreadCount\(\)](./structures/pool/1/get_thread_count.md)
- [enqueue\<\>\(\)](./structures/pool/1/enqueue.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::threads::Pool pool;

    pool.enqueue([] {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::println("abc");
    });

    pool.enqueue([] {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::println("def");
    });

    pool.enqueue([] {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::println("ghi");
    });
}
```
Possible output:
```
abc
def
ghi
```
