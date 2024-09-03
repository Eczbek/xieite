# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:OutputStream\<\>
Defined in fragment [xieite:concepts.OutputStream](../../../src/concepts/output_stream.cpp)

&nbsp;

## Description
Specifies that a type is `std::ostream` or derives from it.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept OutputStream = std::same_as<std::remove_cvref_t<Type>, std::ostream> || std::derived_from<std::remove_cvref_t<Type>, std::ostream>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::OutputStream<decltype(std::cin)>);
    std::println("{}", xieite::concepts::OutputStream<decltype(std::cout)>);
}
```
Output:
```
false
true
```
