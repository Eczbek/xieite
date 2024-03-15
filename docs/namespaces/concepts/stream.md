# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Stream
Defined in header [<xieite/concepts/output_stream.hpp>](../../../include/xieite/concepts/output_stream.hpp)

&nbsp;

## Description
Specifies that a type is, or derives from, `std::istream` or `std::ostream`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Stream = xieite::concepts::InputStream<Type> || xieite::concepts::OutputStream<Type>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/stream.hpp"

int main() {
    std::println("{}", xieite::concepts::Stream<decltype(std::cin)>);
    std::println("{}", xieite::concepts::Stream<decltype(std::cout)>);
    std::println("{}", xieite::concepts::Stream<int>);
}
```
Output:
```
true
true
false
```
