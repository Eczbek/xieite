# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:File \{\}
Defined in fragment [xieite:streams.File](../../../src/streams/file.cpp)

&nbsp;

## Description
A wrapper for a `std::FILE*` stream. Automatically closes upon destruction unless it holds `stdin`, `stdout`, or `stderr`. Requires at least one of `XIEITE_PLATFORM_TYPE_UNIX` or `XIEITE_PLATFORM_TYPE_WINDOWS` to be true.

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

    File(int, const std::string&) noexcept;

#if XIEITE_PLATFORM_TYPE_WINDOWS
    File(int, const std::wstring&) noexcept;
#endif

    template<xieite::concepts::Stream Stream>
    File(Stream&) noexcept;

    File(const std::string&, const std::string&, xieite::streams::File) noexcept;

#if XIEITE_PLATFORM_TYPE_WINDOWS
    File(const std::wstring&, const std::wstring&, xieite::streams::File) noexcept;
#endif

    void open(const std::string&, const std::string&) noexcept;

#if XIEITE_PLATFORM_TYPE_WINDOWS
    void open(const std::wstring&, const std::wstring&) noexcept;
#endif

    void open(int, const std::string&) noexcept;

#if XIEITE_PLATFORM_TYPE_WINDOWS
    void open(int, const std::wstring&) noexcept;
#endif

    template<xieite::concepts::Stream Stream>
    void open(Stream&) noexcept;

    void reopen(const std::string&, const std::string&, xieite::streams::File) noexcept;

#if XIEITE_PLATFORM_TYPE_WINDOWS
    void reopen(const std::wstring&, const std::wstring&, xieite::streams::File) noexcept;
#endif

    int close() noexcept;

    std::FILE* file() const noexcept;

#if XIEITE_PLATFORM_TYPE_UNIX || XIEITE_PLATFORM_TYPE_WINDOWS
    int descriptor() const noexcept;
#endif

    std::FILE* release() noexcept;
};
```
- [File\<\>\(\)](./structures/file/1/operators/constructor.md)
- [open\<\>\(\)](./structures/file/1/open.md)
- [reopen\(\)](./structures/file/1/reopen.md)
- [close\(\)](./structures/file/1/close.md)
- [file\(\)](./structures/file/1/file.md)
- [descriptor\(\)](./structures/file/1/descriptor.md)
- [release\(\)](./structures/file/1/release.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println(xieite::streams::File(std::cout).File(), "Hello, world!");
}
```
Possible output:
```
Hello, world!
```
