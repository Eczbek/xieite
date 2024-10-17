# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:NumberComponents \{\}
Defined in fragment [xieite:strings.NumberComponents](../../../src/strings/number_components.cpp)

&nbsp;

## Description
A structure for storing integer-related characters. See definition for specifics.

&nbsp;

## Synopsis
#### 1)
```cpp
struct NumberComponents {
    std::string_view digits = xieite::strings::characters::alphanumeric;
    std::string_view negatives = "-";
    std::string_view positives = "+";
    std::string_view points = ".";
    std::string_view exponents = "Ee";
    std::size_t precision = 50;

    static constexpr NumberComponents /* nullary..tetrasexagesimal */(std::size_t precision = 50) noexcept;
};
```
- digits
- negatives
- positives
- points
- exponents
- precision
- `/* nullary..tetrasexagesimal */`\(\)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::NumberComponents::hexadecimal().digits);
}
```
Output:
```
0123456789ABCDEF
```
