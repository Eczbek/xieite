# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:NumberComponents \{\}
Defined in fragment [xieite:strings.NumberComponents](../../../src/strings/number_components.cpp)

&nbsp;

## Description
A namespace of collections of integer-related characters.

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
};
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::strings::NumberComponents().digits);
}
```
Output:
```
0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
```
