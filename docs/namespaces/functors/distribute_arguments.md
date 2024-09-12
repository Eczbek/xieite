# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:distributeArguments\<\>\(\)
Defined in fragment [xieite:functors.distributeArguments](../../../src/functors/distribute_arguments.cpp)

&nbsp;

## Description
Distributes arguments among several calls to a functor.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t arity, typename Functor, typename... Arguments>
requires(/* ... */ && (arity > 0) && !(sizeof...(Arguments) % arity))
constexpr void distributeArguments(Functor&& functor, Arguments&&... arguments)
noexcept(/* ... */);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto lambda = [](int x, int y, int z) {
        std::println("{} {} {}", x, y, z);
    };

    xieite::functors::distributeArguments<3>(lambda, 1, 2, 3, 4, 5, 6);
}
```
Output:
```
1 2 3
4 5 6
```
