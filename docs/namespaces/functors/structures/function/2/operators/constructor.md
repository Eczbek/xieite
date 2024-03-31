# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Function<Result(Arguments...)>](../../../../function.md)\:\:Function\(\)
Defined in header [<xieite/functors/function.hpp>](../../../../../../../include/xieite/functors/function.hpp)

&nbsp;

## Description
Constructs a `xieite::functors::Function<Result(Arguments...)>`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Function() noexcept;
```
#### 2)
```cpp
constexpr Function(const xieite::functors::Function<Result(Arguments...)>& function) noexcept;
```
#### 3)
```cpp
template<xieite::concepts::Functable<Result(Arguments...)> Functor>
requires(!std::same_as<std::remove_cvref_t<Functor>, xieite::functors::Function<Result(Arguments...)>>)
constexpr Function(Functor&& functor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/function.hpp"

int main() {
    using Function = xieite::functors::Function<void()>;

    Function foo;

    Function bar = [] {
        std::println("Hello, world!");
    };

    Function baz = bar;

    baz();
}
```
Output:
```
Hello, world!
```
