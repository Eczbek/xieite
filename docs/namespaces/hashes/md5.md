# [xieite](../../xieite.md)\:\:[hashes](../../hashes.md)\:\:md5\(\)
Defined in fragment [xieite:hashes.md5](../../../src/hashes/md5.cpp)

&nbsp;

## Description
Generates a 128-bit hash of a string using the MD5 algorithm.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string md5(std::string_view value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::hashes::md5("Hello, world!"));
}
```
Output:
```
8B0866384E860A3929B7FC07B8447E9B
```
