# [xieite](../../../xieite.md)\:\:[streams](../../../streams.md)\:\:read\(\)
Defined in header [<xieite/streams/read.hpp>](../../../include/xieite/streams/read.hpp)

&nbsp;

## Description
Reads the entire contents of an input stream, including whitespace.

&nbsp;

## Synopsis
#### 1)
```cpp
inline std::string read(std::istream& inputStream) noexcept;
```

&nbsp;

## Example
```cpp
#include <fstream>
#include <print>
#include "xieite/streams/read.md>

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
