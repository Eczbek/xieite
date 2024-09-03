# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:Decades
Defined in fragment [xieite:time.Decades](../../../src/time/decades.cpp)

&nbsp;

## Description
An alias to a `std::chrono::duration` specialization to represent decades.

&nbsp;

## Synopsis
#### 1)
```cpp
using Decades = std::chrono::duration<std::intmax_t, std::ratio<315569520>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::this_thread::sleep_for(xieite::time::Decades(5));

    std::println("Hello, world!");
}
```
Output (in 50 years):
```
Hello, world!
```
