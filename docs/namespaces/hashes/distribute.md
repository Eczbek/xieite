# [xieite](../../xieite.md)\:\:[hashes](../../hashes.md)\:\:distribute\<\>\(\)
Defined in fragment [xieite:hashes.distribute](../../../src/hashes/distribute.cpp)

&nbsp;

## Description
Distributes the bits of an integer magically. See definition for specifics.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral, std::floating_point Phi = double>
[[nodiscard]] constexpr Integral distribute(Integral value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::uint32_t foo = 102030405;

    std::uint32_t bar = xieite::hashes::distribute(foo);

    std::println("{}", std::bitset<32>(foo).to_string());
    std::println("{}", std::bitset<32>(bar).to_string());
}
```
Possible output:
```
00000110000101001101110001000101
01000010111001000011110111101000
```
