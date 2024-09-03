# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[Pipe](../../../pipe.md)\:\:file\(\)
Defined in fragment [xieite:streams.Pipe](../../../../../../src/streams/pipe.cpp)

&nbsp;

## Description
Returns the underlying file stream.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] std::FILE* file() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto pipe = xieite::streams::Pipe("echo Hello, world!", "r");

    std::println("{}", xieite::streams::read(pipe.file()));
}
```
Possible output:
```
Hello, world!
```
