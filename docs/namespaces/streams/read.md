# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:read\(\)
Defined in fragment [xieite:streams.read](../../../src/streams/read.cpp)

&nbsp;

## Description
Reads the entire contents of an input stream, including whitespace.

&nbsp;

## Synopsis
#### 1)
```cpp
std::string read(std::istream& inputStream) noexcept;
```
#### 2)
```cpp
std::string read(std::FILE* inputFile) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::ofstream("test.txt") << "Hello, world!\n";

    std::ifstream reader = std::ifstream("test.txt");
    std::println("{}", xieite::streams::read(reader));
}
```
Output:
```
Hello, world!
```
