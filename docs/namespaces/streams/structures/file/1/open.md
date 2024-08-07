# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[File](../../../file.md)\:\:open\<\>\(\)
Defined in header [<xieite/streams/file.hpp>](../../../../../../include/xieite/streams/file.hpp)

&nbsp;

## Description
Opens a file.

&nbsp;

## Synopsis
#### 1)
```cpp
void open(const std::string& path, const std::string& mode) noexcept;
```
#### 2)
```cpp
#if XIEITE_PLATFORM_TYPE_WINDOWS
void open(const std::wstring& path, const std::wstring& mode) noexcept;
#endif
```
#### 3)
```cpp
void open(int descriptor, const std::string& mode) noexcept;
```
#### 4)
```cpp
#if XIEITE_PLATFORM_TYPE_WINDOWS
void open(int descriptor, const std::wstring& mode) noexcept;
#endif
```
#### 5)
```cpp
template<xieite::concepts::Stream Stream_>
void open(Stream_& stream) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <print>
#include "xieite/streams/file.hpp"

int main() {
    xieite::streams::File file;
    file.open(std::cout);
    std::println(file.file(), "Hello, world!");
}
```
Possible output:
```
Hello, world!
```
