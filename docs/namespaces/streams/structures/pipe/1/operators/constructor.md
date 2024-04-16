# [xieite](../../../../../../xieite.md)\:\:[streams](../../../../../../streams.md)\:\:[Pipe](../../../../pipe.md)\:\:Pipe\(\)
Defined in header [<xieite/streams/pipe.hpp>](../../../../../../../include/xieite/streams/pipe.hpp)

&nbsp;

## Description
Constructs a `xieite::streams::Pipe`.

&nbsp;

## Synopsis
#### 1)
```cpp
#if XIEITE_PLATFORM_TYPE_UNIX || XIEITE_PLATFORM_TYPE_WINDOWS
Pipe(const std::string& command, const std::string& mode) noexcept;
#endif
```
#### 2)
```cpp
#if XIEITE_PLATFORM_TYPE_WINDOWS
Pipe(const std::wstring& command, const std::wstring& mode) noexcept;
#endif
```

&nbsp;

## [Example](../../../../pipe.md#Example)
