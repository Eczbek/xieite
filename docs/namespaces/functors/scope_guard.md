# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:ScopeGuard \{\}
Defined in fragment [xieite:functors.ScopeGuard](../../../src/functors/scope_guard.cpp)

&nbsp;

## Description
Executes a callback when it goes out of scope.

&nbsp;

## Synopsis
#### 1)
```cpp
struct ScopeGuard {
    template<std::invocable<> Functor>
    constexpr ScopeGuard(Functor&&) noexcept;

    constexpr void release() noexcept;
};
```
- [ScopeGuard\(\)](./structures/scope_guard/1/operators/constructor.md)
- [release\(\)](./structures/scope_guard/1/release.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::functors::ScopeGuard _ = [] {
        std::println("foo");
    };

    std::println("bar");
}
```
Output:
```
bar
foo
```
