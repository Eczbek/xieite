# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[File](../../../file.md)\:\:reopen\(\)
Defined in header [<xieite/streams/file.hpp>](../../../../../../include/xieite/streams/file.hpp)

&nbsp;

## Description
Reopens a file.

&nbsp;

## Synopsis
#### 1)
```cpp
void reopen(const std::string& path, const std::string& mode, xieite::streams::File other) noexcept;
```
#### 2)
```cpp
#if XIEITE_PLATFORM_TYPE_WINDOWS
void reopen(const std::wstring& path, const std::wstring& mode, xieite::streams::File other) noexcept;
#endif
```

&nbsp;

## Example
no
