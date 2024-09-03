# [xieite](../../../../../../xieite.md)\:\:[bits](../../../../../../bits.md)\:\:[Fill](../../../../fill.md)\:\:Fill\<\>\(\)
Defined in fragment [xieite:bits.Fill](../../../../../../../src/bits/fill.cpp)

&nbsp;

## Description
Constructs a `xieite::bits::Fill` thingamabob.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
constexpr Fill(Integral value) noexcept;
```
Accepts any integral type until I think of a reason for why it shouldn't.

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto fill = xieite::bits::Fill(-1);

    std::println("{}", fill.value);
}
```
Output:
```
255
```
