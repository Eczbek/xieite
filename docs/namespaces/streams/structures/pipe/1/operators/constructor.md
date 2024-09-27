# [xieite](../../../../../../xieite.md)\:\:[streams](../../../../../../streams.md)\:\:[Pipe](../../../../pipe.md)\:\:Pipe\(\)
Defined in fragment [xieite:streams.Pipe](../../../../../../../src/streams/pipe.cpp)

&nbsp;

## Description
Constructs a `xieite::streams::Pipe`.

&nbsp;

## Synopsis
#### 1)
```cpp
Pipe(const std::string& command, const std::string& mode) noexcept;
```
#### 2)
```cpp
#if XIEITE_PLATFORM_TYPE_WINDOWS
Pipe(const std::wstring& command, const std::wstring& mode) noexcept;
#endif
```

&nbsp;

## [Example](../../../../pipe.md#Example)
