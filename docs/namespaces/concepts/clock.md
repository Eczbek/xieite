# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Clock\<\>
Defined in fragment [xieite:concepts.Clock](../../../src/concepts/clock.cpp)

&nbsp;

## Description
Specifies that a type satisfied `std::chrono::is_clock_v`. To be deprecated once `std::specialization_of` is standardized.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Clock = std::chrono::is_clock_v<Type>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::Clock<std::chrono::steady_clock>);
    std::println("{}", xieite::concepts::Clock<Nope>);
}
```
Output:
```
true
false
```
