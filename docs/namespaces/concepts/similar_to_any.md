# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SimilarToAny\<\>
Defined in fragment [xieite:concepts.SimilarToAny](../../../src/concepts/similar_to_any.cpp)

&nbsp;

## Description
Specifies that a type is the same as at least one of several other types, disregarding constant, volatile, and reference qualifiers. Passing no target types evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
concept SimilarToAny = (... || xieite::concepts::SimilarTo<Source, Targets>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::SimilarToAny<int, const int, int&, volatile int&&>);
    std::println("{}", xieite::concepts::SimilarToAny<int, volatile float, double*&&>);
}
```
Output:
```
true
false
```
