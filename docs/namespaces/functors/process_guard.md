# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:ProcessGuard \{\}
Defined in fragment [xieite:functors.ProcessGuard](../../../src/functors/process_guard.cpp)

&nbsp;

## Description
Executes a callback when the program ends.

&nbsp;

## Synopsis
#### 1)
```cpp
struct ProcessGuard {
    template<std::invocable<> Functor, auto = [] {}>
    ProcessGuard(Functor&&) noexcept;

    void release() noexcept;
};
```
- [ProcessGuard\<\>\(\)](./structures/process_guard/1/operators/constructor.md)
- [release\(\)](./structures/process_guard/1/release.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

void foo() {
    xieite::functors::ProcessGuard _ = [] {
        std::println("foo");
    };
}

int main() {
    foo();

    std::println("bar");
}
```
Output:
```
bar
foo
```
