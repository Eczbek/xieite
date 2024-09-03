# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:forwardTuple\<\>\(\)
Defined in fragment [xieite:containers.forwardTuple](../../../src/containers/forward_tuple.cpp)

&nbsp;

## Description
Forwards every item of a tuple.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::SpecializationOf<std::tuple> Tuple>
[[nodiscard]] constexpr auto forwardTuple(Tuple&& tuple) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto foo = xieite::containers::forwardTuple(std::make_tuple(1, 2.5, 'a'));

    std::println("{}", xieite::types::name<decltype(foo)>);
}
```
Output:
```
std::tuple<int&&, double&&, char&&>
```
