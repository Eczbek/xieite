# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Function<Return_(Arguments_...)>](../../../../function.md)\:\:Function\<\>\(\)
Defined in header [<xieite/functors/function.hpp>](../../../../../../../include/xieite/functors/function.hpp)

&nbsp;

## Description
Constructs a `xieite::functors::Function<Return_(Arguments_...)>`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Function() noexcept;
```
#### 2)
```cpp
explicit(false) constexpr Function(const xieite::functors::Function<Return_(Arguments_...)>& function) noexcept;
```
#### 3)
```cpp
template<xieite::concepts::Functable<Return_(Arguments_...)> Functor_>
requires(!std::same_as<std::remove_cvref_t<Functor_>, xieite::functors::Function<Return_(Arguments_...)>>)
explicit(false) constexpr Function(Functor_&& functor) noexcept;
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
