# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:StreamableIn
Defined in header [<xieite/concepts/streamable_in.hpp>](../../../include/xieite/concepts/streamable_in.hpp)

&nbsp;

## Description
Specifies that a type can be streamed into.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept StreamableIn = requires(Type value, std::istream inputStream) {
    { inputStream >> value } -> std::same_as<std::istream&>;
};
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/streamable_in.hpp"

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::StreamableIn<int>);
    std::println("{}", xieite::concepts::StreamableIn<Nope>);
}
```
Output:
```
true
false
```
