# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:Matrix\<\> \{\}
Defined in header [<xieite/containers/matrix.hpp>](../../../include/xieite/containers/matrix.hpp)

&nbsp;

## Description
A structure for interpreting one-dimensional data as multidimensional, allowing for reversion and rotation of individual dimensions.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Value>
struct Matrix {
    constexpr Matrix() noexcept;

    template<std::ranges::input_range Range>
    requires(std::convertible_to<std::ranges::range_value_t<Range>, Value>)
    explicit(false) constexpr Matrix(Range&&) noexcept;

    explicit(false) constexpr Matrix(std::initializer_list<Value>) noexcept;

    template<typename Self, std::ranges::input_range Range>
    requires(std::convertible_to<std::ranges::range_value_t<Range>, std::size_t>)
    constexpr auto&& operator[](this Self&&, Range&&) noexcept;

    template<typename Self, std::convertible_to<std::size_t>... Sizes>
    constexpr auto&& operator[](this Self&&, Sizes...) noexcept;

    constexpr const std::vector<Value>& data() const noexcept;

    constexpr const std::vector<std::size_t>& size() const noexcept;

    template<std::ranges::input_range Range>
    requires(std::convertible_to<std::ranges::range_value_t<Range>, std::size_t>)
    constexpr void resize(Range&&) noexcept;

    template<std::convertible_to<std::size_t>... Sizes>
    constexpr void resize(Sizes...) noexcept;

    template<std::ranges::input_range Range>
    requires(std::convertible_to<std::ranges::range_value_t<Range>, std::size_t>)
    constexpr void reverse(Range&&) noexcept;

    template<std::convertible_to<std::size_t>... Sizes>
    constexpr void reverse(Sizes...) noexcept;

    template<std::integral Integral, std::ranges::input_range Range>
    requires(std::convertible_to<std::ranges::range_value_t<Range>, std::size_t>)
    constexpr void rotate(Integral, Range&&) noexcept;

    template<std::integral Integral, std::convertible_to<std::size_t>... Sizes>
    constexpr void rotate(Integral, Sizes...) noexcept;
};
```
- [Matrix\(\)](./structures/matrix/1/operators/constructor.md)
- [operator\[\]\(\)](./structures/matrix/1/operators/array_subscript.md)
- [data\(\)](./structures/matrix/1/data.md)
- [size\(\)](./structures/matrix/1/size.md)
- [resize\(\)](./structures/matrix/1/resize.md)
- [reverse\(\)](./structures/matrix/1/reverse.md)
- [rotate\(\)](./structures/matrix/1/rotate.md)

&nbsp;

## Example
```cpp
#include <cstddef>
#include <print>
#include "xieite/containers/matrix.hpp"

int main() {
    xieite::containers::Matrix<int> matrix = { 1, 2, 3, 4, 5, 6 };

    matrix.resize(2, 3);

    for (std::size_t x = 0; x < 2; ++x) {
        for (std::size_t y = 0; y < 3; ++y) {
            std::println("{} ", matrix[x, y]);
        }
    }
}
```
Output:
```
foo: 1
bar: 2
baz: 5
qux: 4
```
