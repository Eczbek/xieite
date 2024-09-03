# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowOperableIterator\<\>
Defined in fragment [xieite:concepts.NoThrowOperableIterator](../../../src/concepts/no_throw_operable_iterator.cpp)

&nbsp;

## Description
Specifies that a type is an iterator which can be generally operated on without throwing exceptions. See definition for specifics.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Iterator>
concept NoThrowOperableIterator = /* ... */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using Iterator = std::array<int, 3>::iterator;

    std::println("{}", xieite::concepts::NoThrowOperableIterator<Iterator>);
}
```
Output:
```
true
```
