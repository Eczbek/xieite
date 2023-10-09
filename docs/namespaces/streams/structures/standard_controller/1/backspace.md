# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardController](../../../standard_controller.md)\:\:backspace
Defined in header [<xieite/streams/standard_controller.hpp>](../../../../../../include/xieite/streams/standard_controller.hpp)

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
