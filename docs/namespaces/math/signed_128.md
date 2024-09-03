# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Signed128
Defined in fragment [xieite:math.Signed128](../../../src/math/signed_128.cpp)

&nbsp;

## Description
A type alias to a compiler-specific extension for a signed 128-bit integer. Requires at least one of `XIEITE_COMPILER_TYPE_GCC`, `XIEITE_COMPILER_TYPE_CLANG`, or `XIEITE_COMPILER_TYPE_MSVC` to be true.

&nbsp;

## Synopsis
#### 1)
```cpp
using Signed128 = /* ... */
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::Signed128 foo = std::numeric_limits<std::uint64_t>::max();

    std::println("{}", foo);

    std::println("{}", foo * -397846);
}
```
Possible output:
```
18446744073709551615
-7338963342749050271821290
```
