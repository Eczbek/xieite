# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:decayAsTuple\<\>\(\)
Defined in fragment [xieite:containers.decayAsTuple](../../../src/containers/decay_as_tuple.cpp)

&nbsp;

## Description
Forwards arguments to a tuple in a reasonable manner. Mostly equivalent to simply constructing a tuple like `std::tuple(a, b, c)`, except avoiding funkiness like `std::tuple(std::pair(1, 2))` resulting in `std::tuple<int, int>`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Arguments>
[[nodiscard]] constexpr std::tuple<std::decay_t<Arguments>...> decayAsTuple(Arguments&&... arguments) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto foo = xieite::containers::decayAsTuple(1, 2.5, 'a');

    std::println("{}", xieite::types::name<decltype(foo)>);
}
```
Output:
```
std::tuple<int, double, char>
```
