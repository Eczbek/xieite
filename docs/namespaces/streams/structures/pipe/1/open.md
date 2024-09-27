# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[Pipe](../../../pipe.md)\:\:open\(\)
Defined in fragment [xieite:streams.Pipe](../../../../../../src/streams/pipe.cpp)

&nbsp;

## Description
Opens a pipe.

&nbsp;

## Synopsis
#### 1)
```cpp
void open(const std::string& command, const std::string& mode) noexcept;
```
#### 2)
```cpp
#if XIEITE_PLATFORM_TYPE_WINDOWS
void open(const std::wstring& command, const std::wstring& mode) noexcept;
#endif
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::streams::Pipe pipe;
    pipe.open("echo Hello, world!", "r");
    std::println("{}", xieite::streams::read(pipe.file()));
}
```
Possible output:
```
Hello, world!
```
