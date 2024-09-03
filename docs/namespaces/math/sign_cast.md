# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:signCast\<\>\(\)
Defined in fragment [xieite:math.signCast](../../../src/math/sign_cast.cpp)

&nbsp;

## Description
Casts a value to the signedness of the target type before converting the value.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Target, std::integral Source>
[[nodiscard]] constexpr Target signCast(Source value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::int8_t foo = -1;

    std::uint64_t bar = static_cast<std::uint64_t>(foo);

    std::uint64_t baz = xieite::math::signCast<std::uint64_t>(foo);

    std::println("{}", bar);
    std::println("{}", baz);
}
```
Output:
```
18446744073709551615
255
```
