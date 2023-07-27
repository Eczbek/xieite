# [xieite](../xieite.md)::[memory](../memory.md)::bufferSize
Defined in header [<xieite/memory/bufferSize.hpp>](../../include/xieite/memory/bufferSize.hpp)

<br/>

Defines a good amount of bytes to read at a time

<br/><br/>

## Synopsis

<br/>

```cpp
inline constexpr std::size_t bufferSize = ::sysconf(_SC_PAGE_SIZE);
```
