# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:characters
Defined in header [<xieite/strings/characters.hpp>](../../../include/xieite/strings/characters.hpp)

&nbsp;

## Description
A namespace of collections of characters.

&nbsp;

## Synopsis
#### 1)
```cpp
inline constexpr std::size_t alphabetSize = 26;
```
#### 2)
```cpp
inline constexpr std::string_view uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
```
#### 3)
```cpp
inline constexpr std::string_view lowercase = "abcdefghijklmnopqrstuvwxyz";
```
#### 4)
```cpp
inline constexpr std::string_view digits = "0123456789";
```
#### 5)
```cpp
inline constexpr std::string_view alphanumeric = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
```
#### 6)
```cpp
inline constexpr std::string_view vowels = "AEIOUaeiou";
```
#### 7)
```cpp
inline constexpr std::string_view consonants = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
```
#### 8)
```cpp
inline constexpr std::string_view whitespaces = "\t\n\v\f\r ";
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/characters.md"

int main() {
    std::println("{}", xieite::strings::characters::uppercase);
}
```
Output:
```cpp
ABCDEFGHIJKLMNOPQRSTUVWXYZ
```
