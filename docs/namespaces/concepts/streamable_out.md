# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:StreamableOut\<\>
Defined in header [<xieite/concepts/streamable_out.hpp>](../../../include/xieite/concepts/streamable_out.hpp)

&nbsp;

## Description
Specifies that a type can be streamed out of.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
concept StreamableOut = requires(Type_ value, std::ostream outputStream) {
    { outputStream << value } -> std::same_as<std::ostream&>;
};
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/streamable_out.hpp"

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::StreamableOut<char>);
    std::println("{}", xieite::concepts::StreamableOut<Nope>);
}
```
Output:
```
true
false
```
