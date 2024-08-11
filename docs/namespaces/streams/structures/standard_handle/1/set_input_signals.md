# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setInputSignals\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables input signals. Specifically, disables the special functionalities of Ctrl+C, Ctrl+Z, Ctrl+S, Ctrl+Q, Ctrl+V, and Ctrl+M, to instead read them as a sequence of normal characters.

&nbsp;

## Synopsis
#### 1)
```cpp
void setInputSignals(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/key.hpp"
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setInputSignals(false);

    xieite::streams::Key input = xieite::streams::Key::Unknown;
    do {
        std::print("Press Q to quit: ");
        input = terminal.readKey();
        std::println();
    } while ((input != xieite::streams::Key::UppercaseQ) && (input != xieite::streams::Key::LowercaseQ));

    std::println("Quitting!");
}
```
Possible output:
```
Press Q to quit: a
Press Q to quit: b
Press Q to quit: c
Press Q to quit: x
Press Q to quit: y
Press Q to quit: z
Press Q to quit: ^C
Press Q to quit: ^C
Press Q to quit: ^C
Press Q to quit: q
Quitting!
```
