# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:StreamableOut\<\>
Defined in fragment [xieite:concepts.StreamableOut](../../../src/concepts/streamable_out.cpp)

&nbsp;

## Description
Specifies that a type can be streamed out of.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept StreamableOut = requires(Type value, std::ostream outputStream) {
    { outputStream << value } -> std::convertible_to<std::ostream&>;
};
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::StreamableOut<char>);
    std::println("{}", xieite::concepts::StreamableOut<Nope>);
}
```
Output:
```
true
false
```
