# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SimilarToAll\<\>
Defined in fragment [xieite:concepts.SimilarToAll](../../../src/concepts/similar_to_all.cpp)

&nbsp;

## Description
Specifies that a type is the same as all of several other types, disregarding constant, volatile, and reference qualifiers. Passing no target types evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
concept SimilarToAll = (... && xieite::concepts::SimilarTo<Source, Targets>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::SimilarToAll<int, const int, int&, volatile int&&>);
    std::println("{}", xieite::concepts::SimilarToAll<int, volatile float, double*&&>);
}
```
Output:
```
true
false
```
