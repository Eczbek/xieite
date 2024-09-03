# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Duration\<\>
Defined in fragment [xieite:concepts.Duration](../../../src/concepts/duration.cpp)

&nbsp;

## Description
Specifies that a type is a `std::chrono::duration`. To be deprecated once `std::specialization_of` is standardized.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Duration = xieite::traits::IsDuration<std::remove_cv_t<Type>>::value;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::Duration<std::chrono::hours>);
    std::println("{}", xieite::concepts::Duration<Nope>);
}
```
Output:
```
true
false
```
