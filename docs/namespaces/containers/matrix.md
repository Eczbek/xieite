# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:Matrix\<\> \{\}
Defined in header [<xieite/containers/matrix.hpp>](../../../include/xieite/containers/matrix.hpp)

&nbsp;

## Description
A structure for interpreting one-dimensional data as multidimensional, allowing for reversion and rotation of individual dimensions.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Value_>
struct Matrix {
    constexpr Matrix() noexcept;

    template<xieite::concepts::RangeOf<Value_> Range_>
    explicit(false) constexpr Matrix(Range_&&) noexcept;

    explicit(false) constexpr Matrix(std::initializer_list<Value_>) noexcept;

    template<typename Self_, xieite::concepts::RangeOf<std::size_t> Range_>
    constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value_, std::is_const_v<Self_>>>> operator[](this Self_&&, Range_&&) noexcept;

    template<typename Self_, std::convertible_to<std::size_t>... Sizes_>
    constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value_, std::is_const_v<Self_>>>> operator[](this Self_&&, Sizes_...) noexcept;

    constexpr const std::vector<Value_>& data() const noexcept;

    constexpr const std::vector<std::size_t>& size() const noexcept;

    template<xieite::concepts::RangeOf<std::size_t> Range_>
    constexpr std::optional<std::monostate> resize(Range_&&) noexcept;

    template<std::convertible_to<std::size_t>... Sizes_>
    constexpr std::optional<std::monostate> resize(Sizes_...) noexcept;

    template<xieite::concepts::RangeOf<std::size_t> Range_>
    constexpr std::optional<std::monostate> reverse(Range_&&) noexcept;

    template<std::convertible_to<std::size_t>... Sizes_>
    constexpr std::optional<std::monostate> reverse(Sizes_...) noexcept;

    template<std::integral Integral_, xieite::concepts::RangeOf<std::size_t> Range_>
    constexpr std::optional<std::monostate> rotate(Integral_, Range_&&) noexcept;

    template<std::integral Integral_, std::convertible_to<std::size_t>... Sizes_>
    constexpr std::optional<std::monostate> rotate(Integral_, Sizes_...) noexcept;
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
            std::println("{} ", matrix[x, y].value());
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
