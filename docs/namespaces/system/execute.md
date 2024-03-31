# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:execute\(\)
Defined in header [<xieite/system/execute.hpp>](../../../include/xieite/system/execute.hpp)

&nbsp;

## Description
Executes a command and returns its output. Works on both UNIX-like and Windows systems.

&nbsp;

## Synopsis
#### 1)
```cpp
inline std::string execute(std::string_view command) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/system/execute.hpp"

int main() {
    std::println("{}", xieite::system::execute("echo Hello, world!");
}
```
Possible output:
```
Hello, world!
```
