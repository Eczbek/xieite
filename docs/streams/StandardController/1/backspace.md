# [xieite](../../../xieite.md)\:\:[streams](../../../streams.md)\:\:[StandardController\<inputStream, outputStream\>](../../StandardController.md)\:\:backspace
Defined in header [<xieite/streams/StandardController.hpp>](../../../../include/xieite/streams/StandardController.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
void backspace(std::size_t count) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/streams/terminal.hpp>

int main() {
    std::cout << "Hello, world!";
    xieite::streams::terminal.backspace(6);
    std::cout << "something\n";
}
```
Possible output:
```
Hello, something
```
