# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Function<Return(Arguments...)>](../../../../function.md)\:\:Function\<\>\(\)
Defined in fragment [xieite:functors.Function](../../../../../../../src/functors/function.cpp)

&nbsp;

## Description
Constructs a `xieite::functors::Function<Return(Arguments...)>`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Function() noexcept;
```
#### 2)
```cpp
explicit(false) constexpr Function(const xieite::functors::Function<Return(Arguments...)>& function) noexcept;
```
#### 3)
```cpp
template<xieite::concepts::Invocable<Return(Arguments...)> Functor>
requires(!std::same_as<std::remove_cvref_t<Functor>, xieite::functors::Function<Return(Arguments...)>>)
explicit(false) constexpr Function(Functor&& functor) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
