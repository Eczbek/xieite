# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:isUniformMatrix\<\>\(\)
Defined in fragment [xieite:algorithms.isUniformMatrix](../../../src/algorithms/is_uniform_matrix.cpp)

&nbsp;

## Description
Checks whether all the ranges within one range have the same size.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::input_range Range>
requires(std::ranges::input_range<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr bool isUniformMatrix(Range&& matrix)
noexcept(/* ... */);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::vector<std::vector<int>> matrix1 = {
        { 1, 2, 3 },
        { 4, 5, 6 }
    };

    std::vector<std::vector<int>> matrix2 = {
        { 1 },
        { 2, 3 },
        { 4, 5, 6 }
    };

    std::println("{}", xieite::algorithms::isUniformMatrix(matrix1));
    std::println("{}", xieite::algorithms::isUniformMatrix(matrix2));
}
```
Output:
```
true
false
```
