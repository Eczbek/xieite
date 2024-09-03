# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:Centuries
Defined in fragment [xieite:time.Centuries](../../../src/time/centuries.cpp)

&nbsp;

## Description
An alias to a `std::chrono::duration` specialization to represent centuries.

&nbsp;

## Synopsis
#### 1)
```cpp
using Centuries = std::chrono::duration<std::intmax_t, std::ratio<3155695200>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::this_thread::sleep_for(xieite::time::Centuries(3));

    std::println("Hello, world!");
}
```
Output (in 300 years):
```
Hello, world!
```
