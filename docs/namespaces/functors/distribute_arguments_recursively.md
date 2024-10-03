# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:distributeArgumentsRecursively\<\>\(\)
Defined in fragment [xieite:functors.distributeArgumentsRecursively](../../../src/functors/distribute_arguments_recursively.cpp)

&nbsp;

## Description
Distributes arguments among several calls to a functor, but recursively such that one of the arguments to succeeding calls is the result of the previous.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t arity, std::size_t previousResultIndex = 0, typename Functor, typename... Arguments>
requires((arity > previousResultIndex) && (arity <= sizeof...(Arguments)) && ((arity == 1) || ((arity > 1) && !((sizeof...(Arguments) - 1) % (arity - 1)))) && xieite::types::List<xieite::types::Any>::Repeat<arity>::Prepend<Functor>::To<std::is_invocable>::value)
/* discardable */ constexpr decltype(auto) distributeArgumentsRecursively(Functor&& functor, Arguments&&... arguments)
noexcept(xieite::types::List<xieite::types::Any>::Repeat<arity>::Prepend<Functor>::To<std::is_nothrow_invocable>::value);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto lambda = [](int x, int total) {
        std::println("total: {}", total);
        return total + x;
    };

    int total = xieite::functors::distributeArgumentsRecursively<2, 1>(lambda, 1, 2, 3, 4, 5);
    std::println("total: {}", total);
}
```
Output:
```
total: 2
total: 3
total: 6
total: 10
total: 15
```
