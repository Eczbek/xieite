# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:StreamableIn\<\>
Defined in fragment [xieite:concepts.StreamableIn](../../../src/concepts/streamable_in.cpp)

&nbsp;

## Description
Specifies that a type can be streamed into.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept StreamableIn = requires(Type value, std::istream inputStream) {
    { inputStream >> value } -> std::convertible_to<std::istream&>;
};
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::StreamableIn<int>);
    std::println("{}", xieite::concepts::StreamableIn<Nope>);
}
```
Output:
```
true
false
```
