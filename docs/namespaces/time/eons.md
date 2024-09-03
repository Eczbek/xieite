# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:Eons
Defined in fragment [xieite:time.Eons](../../../src/time/eons.cpp)

&nbsp;

## Description
An alias to a `std::chrono::duration` specialization to represent eons.

&nbsp;

## Synopsis
#### 1)
```cpp
using Eons = std::chrono::duration<std::intmax_t, std::ratio<31556952000000000>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::this_thread::sleep_for(xieite::time::Eons(7));

    std::println("Hello, world!");
}
```
Output (in 7'000'000'000 years):
```
Hello, world!
```
