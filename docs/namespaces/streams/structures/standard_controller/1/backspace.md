# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:backspace
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

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
#include <xieite/streams/standard_handle.hpp>

int main() {
    auto terminal = xieite::streams::StandardHandle(std::cin, std::cout);

    std::cout << "Hello, world!";
    terminal.backspace(6);
    std::cout << "something\n";
}
```
Possible output:
```
Hello, something
```
