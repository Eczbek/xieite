# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:Pipe \{\}
Defined in header [<xieite/streams/pipe.hpp>](../../../include/xieite/streams/pipe.hpp)

&nbsp;

## Description
Provides a wrapper for a `std::FILE*` pipe, automatically closed upon destruction. Requires at least one of `XIEITE_PLATFORM_TYPE_UNIX` or `XIEITE_PLATFORM_TYPE_WINDOWS` to be true.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Pipe {
    Pipe() noexcept;

    Pipe(const std::string&, const std::string&) noexcept;

#if XIEITE_PLATFORM_TYPE_WINDOWS
    Pipe(const std::wstring&, const std::wstring&) noexcept;
#endif

    void open(const std::string&, const std::string&) noexcept;

#if XIEITE_PLATFORM_TYPE_WINDOWS
    void open(const std::wstring&, const std::wstring&) noexcept;
#endif

    int close() noexcept;

    std::FILE* file() const noexcept;

    int descriptor() const noexcept;
};
```
- [Pipe\(\)](./structures/pipe/1/operators/constructor.md)
- [open\(\)](./structures/pipe/open.md)
- [close\(\)](./structures/pipe/close.md)
- [file\(\)](./structures/pipe/file.md)
- [descriptor\(\)](./structures/pipe/descriptor.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/pipe.hpp"

int main() {
    auto _ = xieite::streams::Pipe("echo \"Hello, world!\"", "w");
}
```
Possible output:
```
Hello, world!
```
