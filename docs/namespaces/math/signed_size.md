# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:SignedSize
Defined in fragment [xieite:math.SignedSize](../../../src/math/signed_size.cpp)

&nbsp;

## Description
A type alias for the signed version of `std::size_t`.

&nbsp;

## Synopsis
#### 1)
```cpp
using SignedSize = std::make_signed_t<std::size_t>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::types::name<xieite::math::SignedSize>);
}
```
Possible output:
```
long int
```
