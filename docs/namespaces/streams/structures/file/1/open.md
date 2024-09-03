# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[File](../../../file.md)\:\:open\<\>\(\)
Defined in fragment [xieite:streams.File](../../../../../../src/streams/file.cpp)

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
import std;
import xieite;
void open(const std::wstring& path, const std::wstring& mode) noexcept;
#endif
```
#### 3)
```cpp
void open(int descriptor, const std::string& mode) noexcept;
```
#### 4)
```cpp
import std;
import xieite;
void open(int descriptor, const std::wstring& mode) noexcept;
#endif
```
#### 5)
```cpp
template<xieite::concepts::Stream Stream>
void open(Stream& stream) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::streams::File file;
    file.open(std::cout);
    std::println(file.File(), "Hello, world!");
}
```
Possible output:
```
Hello, world!
```
