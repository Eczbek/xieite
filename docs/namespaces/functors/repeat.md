# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:repeat\<\>\(\)
Defined in fragment [xieite:functors.repeat](../../../src/functors/repeat.cpp)

&nbsp;

## Description
Repeats something a fixed number of times.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral auto count>
constexpr auto repeat(auto&& functor, auto&&... arguments)
XIEITE_ARROW(/* ... */)
```
#### 2)
```cpp
template<typename... Types>
constexpr auto repeat(auto&& functor, auto&&... arguments)
XIEITE_ARROW(/* ... */)
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::functors::repeat<5>(
        []<int i> {
            std::print("{}\n", i);
        }
    );
}
```
Output:
```
0
1
2
3
4
```
