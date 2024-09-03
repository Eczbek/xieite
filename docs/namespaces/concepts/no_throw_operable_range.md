# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowOperableRange\<\>
Defined in fragment [xieite:concepts.NoThrowOperableRange](../../../src/concepts/no_throw_operable_range.cpp)

&nbsp;

## Description
Specifies that a type is a range which can be generally operated on without throwing exceptions. See definition for specifics.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Range>
concept NoThrowOperableRange = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using Range = std::array<int, 3>;

    std::println("{}", xieite::concepts::NoThrowOperableRange<Range>);
}
```
Output:
```
true
```
