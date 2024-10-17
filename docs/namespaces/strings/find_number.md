# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:findNumber\<\>\(\)
Defined in fragment [xieite:strings.findNumber](../../../src/strings/find_number.cpp)

&nbsp;

## Description
Finds an integral or fractional number within a string.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr std::string_view findNumber(std::string_view value, std::conditional_t<std::floating_point<Arithmetic>, xieite::math::SignedSize, Arithmetic> radix = 10, xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::findNumber<int>("abcd4abcd"));
    std::println("{}", xieite::strings::findNumber<double>("qwerty-3.14159e22qwerty"));
    std::println("{}", xieite::strings::findNumber<double>("+DEAD.BEEF", 16));
    std::println("{}", xieite::strings::findNumber<int>("847ey5wi7"));
}
```
Output:
```
4
-3.14159e22
+DEAD.BEEF
847
```
