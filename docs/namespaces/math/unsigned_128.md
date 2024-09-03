# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Unsigned128
Defined in fragment [xieite:math.Unsigned128](../../../src/math/unsigned_128.cpp)

&nbsp;

## Description
A type alias to a compiler-specific extension for an unsigned 128-bit integer. Requires at least one of `XIEITE_COMPILER_TYPE_GCC`, `XIEITE_COMPILER_TYPE_CLANG`, or `XIEITE_COMPILER_TYPE_MSVC` to be true.

&nbsp;

## Synopsis
#### 1)
```cpp
using Unsigned128 = /* ... */
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", std::numeric_limits<std::uint64_t>::max());
    std::println("{}", std::numeric_limits<xieite::math::Unsigned128>::max());
}
```
Possible output:
```
18446744073709551615
340282366920938463463374607431768211455
```
