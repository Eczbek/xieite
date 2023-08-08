# [xieite](../xieite.md)\:\:[system](../system.md)\:\:execute
Defined in header [<xieite/system/execute.hpp>](../../include/xieite/system/execute.hpp)

&nbsp;

## Description
Executes a command and returns its output

&nbsp;

## Synopsis
```cpp
inline std::string execute(std::string_view command) noexcept;
```
#### Function parameters
- `command` - A `std::string_view`
#### Return type
- `std::string`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/system/execute.hpp>

int main() {
    std::cout << xieite::system::execute("echo Hello, world!");
}
```
Output:
```
Hello, world!
```
