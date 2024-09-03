# [xieite](../../../../../../xieite.md)\:\:[streams](../../../../../../streams.md)\:\:[File](../../../../file.md)\:\:File\<\>\(\)
Defined in fragment [xieite:streams.File](../../../../../../../src/streams/file.cpp)

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
import std;
import xieite;
File(const std::wstring& path, const std::wstring& mode) noexcept;
#endif
```
#### 4)
```cpp
File(int descriptor, const std::string& mode) noexcept;
```
#### 5)
```cpp
import std;
import xieite;
File(int descriptor, const std::wstring& mode) noexcept;
#endif
```
#### 6)
```cpp
template<xieite::concepts::Stream Stream>
File(Stream& stream) noexcept;
```
#### 7)
```cpp
File(const std::string& path, const std::string& mode, xieite::streams::File other) noexcept;
```
#### 8)
```cpp
import std;
import xieite;
File(const std::wstring& path, const std::wstring& mode, xieite::streams::File other) noexcept;
#endif
```

&nbsp;

## [Example](../../../../file.md#Example)
