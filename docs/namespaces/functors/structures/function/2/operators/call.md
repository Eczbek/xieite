# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Function<Return(Arguments...)>](../../../../function.md)\:\:operator\(\)\<\>\(\)
Defined in fragment [xieite:functors.Function](../../../../../../../src/functors/function.cpp)

&nbsp;

## Description
Calls the underlying functor.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... ArgumentReferences>
requires((... && std::convertible_to<ArgumentReferences, Arguments>))
constexpr Return operator()(ArgumentReferences&&... arguments) const;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::functors::Function<void()> foo = [] {
        std::println("Hello, world!");
    };

    foo();
}
```
Output:
```
Hello, world!
```
