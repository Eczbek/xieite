# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:Pipe \{\}
Defined in header [<xieite/streams/pipe.hpp>](../../../include/xieite/streams/pipe.hpp)

&nbsp;

## Description
Provides a wrapper for a `std::FILE*` pipe, automatically closed upon destruction.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Pipe {
    std::FILE* const file;

    Pipe(const std::string&, const std::string&);
};
```
##### Members
- file
- [Pipe\(\)](./structures/pipe/1/operators/constructor.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/pipe.hpp"

int main() {
    auto _ = xieite::streams::Pipe("echo \"Hello, world!\"", "w");
}
```
Possible output:
```
Hello, world!
```
