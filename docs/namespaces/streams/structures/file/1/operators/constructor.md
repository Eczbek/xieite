# [xieite](../../../../../../xieite.md)\:\:[streams](../../../../../../streams.md)\:\:[File](../../../../file.md)\:\:File\<\>\(\)
Defined in header [<xieite/streams/file.hpp>](../../../../../../../include/xieite/streams/file.hpp)

&nbsp;

## Description
Constructs a `xieite::streams::File`.

&nbsp;

## Synopsis
#### 1)
```cpp
File(std::FILE* stream = nullptr) noexcept;
```
#### 2)
```cpp
File(const std::string& path, const std::string& mode) noexcept;
```
#### 3)
```cpp
#if XIEITE_PLATFORM_TYPE_WINDOWS
File(const std::wstring& path, const std::wstring& mode) noexcept;
#endif
```
#### 4)
```cpp
File(int descriptor, const std::string& mode) noexcept;
```
#### 5)
```cpp
#if XIEITE_PLATFORM_TYPE_WINDOWS
File(int descriptor, const std::wstring& mode) noexcept;
#endif
```
#### 6)
```cpp
template<xieite::concepts::Stream Stream_>
File(Stream_& stream) noexcept;
```
#### 7)
```cpp
File(const std::string& path, const std::string& mode, xieite::streams::File other) noexcept;
```
#### 8)
```cpp
#if XIEITE_PLATFORM_TYPE_WINDOWS
File(const std::wstring& path, const std::wstring& mode, xieite::streams::File other) noexcept;
#endif
```

&nbsp;

## [Example](../../../../file.md#Example)
