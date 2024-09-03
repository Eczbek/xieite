# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Pool](../../../../pool.md)\:\:Pool\(\)
Defined in fragment [xieite:threads.Pool](../../../../../../../src/threads/pool.cpp)

&nbsp;

## Description
Constructs a `xieite::threads::Pool`, creates initial threads.

&nbsp;

## Synopsis
#### 1)
```cpp
Pool(std::size_t threadCount = std::thread::hardware_concurrency());
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto pool = xieite::threads::Pool(4);

    std::println("{}", pool.getThreadCount());
}
```
Output:
```
4
```
