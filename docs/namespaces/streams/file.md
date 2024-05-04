# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:File \{\}
Defined in header [<xieite/streams/file.hpp>](../../../include/xieite/streams/file.hpp)

&nbsp;

## Description
A wrapper for a `std::FILE*` stream. Automatically closes upon destruction unless it holds `stdin`, `stdout`, or `stderr`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct File {
    File(std::FILE* = nullptr) noexcept;

    File(const std::string&, const std::string&) noexcept;

#if XIEITE_PLATFORM_TYPE_WINDOWS
    File(const std::wstring&, const std::wstring&) noexcept;
#endif

    File(const std::string&, const std::string&, xieite::streams::File) noexcept;

#if XIEITE_PLATFORM_TYPE_WINDOWS
    File(const std::wstring&, const std::wstring&, xieite::streams::File) noexcept;
#endif

#if XIEITE_PLATFORM_TYPE_UNIX || XIEITE_PLATFORM_TYPE_WINDOWS
    File(int, const std::string&) noexcept;
#endif

#if XIEITE_PLATFORM_TYPE_WINDOWS
    File(int, const std::wstring&) noexcept;
#endif

    template<xieite::concepts::Stream Stream_>
    File(const Stream_&) noexcept;

    std::FILE* file() const noexcept;

#if XIEITE_PLATFORM_TYPE_UNIX || XIEITE_PLATFORM_TYPE_WINDOWS
    int descriptor() const noexcept;
#endif
};
```
##### Members
- [File\<\>\(\)](./structures/file/1/operators/constructor.md)
- [file\(\)](./structures/file/file.md)
- [descriptor\(\)](./structures/file/descriptor.md)

&nbsp;

## Example
```cpp
#include <cstdio>
#include <iostream>
#include "xieite/streams/file.hpp"

int main() {
    std::fprintf(xieite::streams::File(std::cout).file(), "Hello, world!\n");
}
```
Possible output:
```
Hello, world!
```
