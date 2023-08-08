# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:StreamableOut
Defined in header [<xieite/concepts/StreamableOut.hpp>](../../include/xieite/concepts/StreamableOut.hpp)

&nbsp;

## Description
Specifies that a type can be streamed out of.

&nbsp;

## Synopsis
```cpp
template<typename Type>
concept StreamableOut = requires(Type value, std::ostream outputStream) {
    { outputStream << value } -> std::same_as<std::ostream&>;
};
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/concepts/StreamableOut.hpp>

struct Unstreamable {};

int main() {
    std::cout
        << std::boolalpha
        << xieite::concepts::StreamableOut<char> << '\n'
        << xieite::concepts::StreamableOut<Unstreamable> << '\n';
}
```
Output:
```
true
false
```
