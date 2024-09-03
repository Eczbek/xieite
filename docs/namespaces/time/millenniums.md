# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:Millenniums
Defined in fragment [xieite:time.Millenniums](../../../src/time/millenniums.cpp)

&nbsp;

## Description
An alias to a `std::chrono::duration` specialization to represent millenniums.

&nbsp;

## Synopsis
#### 1)
```cpp
using Millenniums = std::chrono::duration<std::intmax_t, std::ratio<31556952000>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::this_thread::sleep_for(xieite::time::Millenniums(2));

    std::println("Hello, world!");
}
```
Output (in 2000 years):
```
Hello, world!
```
