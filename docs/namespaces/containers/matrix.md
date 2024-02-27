# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:Matrix
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

    template<xieite::concepts::RangeOf<Value> Range>
    constexpr Matrix(Range&&) noexcept;

    constexpr Matrix(const std::initializer_list<Value>) noexcept;

    template<typename Self, xieite::concepts::RangeOf<std::size_t> Range>
    constexpr std::convertible_to<Value> auto&& operator[](this Self&&, Range&&);

    template<typename Self, std::convertible_to<std::size_t>... Sizes>
    constexpr std::convertible_to<Value> auto&& operator[](this Self&&, Sizes...);

    constexpr const std::vector<Value>& data() const noexcept;

    constexpr const std::vector<std::size_t>& size() const noexcept;

    template<xieite::concepts::RangeOf<std::size_t> Range>
    constexpr void resize(Range&&);

    template<std::convertible_to<std::size_t>... Sizes>
    constexpr void resize(Sizes...);

    template<xieite::concepts::RangeOf<std::size_t> Range>
    constexpr void reverse(Range&&) ;

    template<std::convertible_to<std::size_t>... Sizes>
    constexpr void reverse(Sizes...);

    template<std::integral Integer, xieite::concepts::RangeOf<std::size_t> Range>
    constexpr void rotate(Integer, Range&&);

    template<std::integral Integer, std::convertible_to<std::size_t>... Sizes>
    constexpr void rotate(Integer, Sizes...);
};
```
##### Member functions
- [Matrix](./structures/matrix/1/operators/constructor.md)
- [operator\[\]](./structures/matrix/1/operators/array_subscript.md)
- [data](./structures/matrix/1/data.md)
- [size](./structures/matrix/1/size.md)
- [resize](./structures/matrix/1/resize.md)
- [reverse](./structures/matrix/1/reverse.md)
- [rotate](./structures/matrix/1/rotate.md)

&nbsp;

## Example
```cpp
#include <print>
#include <utility>
#include "xieite/containers/matrix.hpp"

int main() {
    constexpr xieite::containers::Matrix<std::string_view, int, 4> map {
        { "foo", 1 },
        { "bar", 2 },
        { "baz", 3 },
        { "qux", 4 }
    };

    for (auto [key, value] : map) {
        std::println("{}: {}", key, value);
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
