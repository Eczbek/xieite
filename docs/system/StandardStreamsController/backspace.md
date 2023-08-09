# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../StandardStreamsController.md)\:\:backspace
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
void backspace(std::size_t count) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/system/terminal.hpp>

int main() {
    std::cout << "Hello, world!";
    xieite::system::terminal.backspace(6);
    std::cout << "something\n";
}
```
Possible output:
```
Hello, something
```
