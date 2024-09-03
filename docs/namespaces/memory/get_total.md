# [xieite](../../xieite.md)\:\:[memory](../../memory.md)\:\:getTotal\(\)
Defined in fragment [xieite:memory.getTotal](../../../src/memory/get_total.cpp)

&nbsp;

## Description
Gets the system's total amount of memory. Requires at least one of `XIEITE_PLATFORM_TYPE_UNIX` or `XIEITE_PLATFORM_TYPE_WINDOWS` to be true.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] inline std::size_t getTotal() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::memory::getTotal());
}
```
Possible output:
```
16630874112
```
