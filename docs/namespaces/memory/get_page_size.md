# [xieite](../../xieite.md)\:\:[memory](../../memory.md)\:\:getPageSize\(\)
Defined in fragment [xieite:memory.getPageSize](../../../src/memory/get_page_size.cpp)

&nbsp;

## Description
Gets the system's page size in bytes. Requires at least one of `XIEITE_PLATFORM_TYPE_UNIX` or `XIEITE_PLATFORM_TYPE_WINDOWS` to be true.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] inline std::size_t getPageSize() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::memory::getPageSize());
}
```
Possible output:
```
4096
```
