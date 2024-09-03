# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:InputStream\<\>
Defined in fragment [xieite:concepts.InputStream](../../../src/concepts/input_stream.cpp)

&nbsp;

## Description
Specifies that a type is `std::istream` or derives from it.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept InputStream = std::same_as<std::remove_cvref_t<Type>, std::istream> || std::derived_from<std::remove_cvref_t<Type>, std::istream>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::InputStream<decltype(std::cin)>);
    std::println("{}", xieite::concepts::InputStream<decltype(std::cout)>);
}
```
Output:
```
true
false
```
