# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Function<Return(Arguments...)>](../../../../function.md)\:\:operator typename\(\)
Defined in fragment [xieite:functors.Function](../../../../../../../src/functors/function.cpp)

&nbsp;

## Description
The boolean cast returns `true` if a functor is assigned, `false` otherwise.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] explicit constexpr operator bool() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using Function = xieite::functors::Function<void()>;

    Function foo;

    Function bar = [] {};

    std::println("{}", static_cast<bool>(foo));
    std::println("{}", static_cast<bool>(bar));
}
```
Output:
```
false
true
```
