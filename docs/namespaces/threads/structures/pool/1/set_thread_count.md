# [xieite](../../../../../xieite.md)\:\:[threads](../../../../../threads.md)\:\:[Pool](../../../pool.md)\:\:setThreadCount\(\)
Defined in fragment [xieite:threads.Pool](../../../../../../src/threads/pool.cpp)

&nbsp;

## Description
Sets the amount of threads to use.

&nbsp;

## Synopsis
#### 1)
```cpp
void setThreadCount(std::size_t threadCount);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto pool = xieite::threads::Pool(2);

    std::println("{}", pool.getThreadCount());

    pool.setThreadCount(4);

    std::println("{}", pool.getThreadCount());
}
```
Output:
```
2
4
```
