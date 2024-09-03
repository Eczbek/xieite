# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SimilarTo\<\>
Defined in fragment [xieite:concepts.SimilarTo](../../../src/concepts/similar_to.cpp)

&nbsp;

## Description
Specifies that two types are the same, disregarding constant, volatile, and reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename First, typename Second>
concept SimilarTo = std::same_as<std::remove_cvref_t<First>, std::remove_cvref_t<Second>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::SimilarTo<const int, volatile int&&>);
    std::println("{}", xieite::concepts::SimilarTo<int&&, const float>);
}
```
Output:
```
true
false
```
