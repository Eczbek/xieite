# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:execute\(\)
Defined in header [<xieite/system/execute.hpp>](../../../include/xieite/system/execute.hpp)

&nbsp;

## Description
Executes a command and returns its output. Works on both UNIX-like and Windows systems.

&nbsp;

## Synopsis
#### 1)
```cpp
inline xieite::system::Result execute(std::string_view command) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/system/execute.hpp"

int main() {
    auto result = xieite::system::execute("echo Hello, world!");
    std::println("output: {}", result.output);
    std::println("status: {}", result.status);
}
```
Possible output:
```
output: Hello, world!

status: 0
```
