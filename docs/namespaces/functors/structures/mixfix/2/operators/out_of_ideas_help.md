# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Mixfix<Return(Argument)>](../../../../mixfix.md)\:\:operator???\<\>\(\)
Defined in fragment [xieite:functors.Mixfix](../../../../../../../src/functors/mixfix.cpp)

&nbsp;

## Description
Calls the underlying functor with one argument.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<Argument> ArgumentReference>
friend constexpr auto operator/*   ->* * / % + - << >> <=> < <= > >= == != & ^ | && || *= /= %= += -= <<= >>= &= ^= |= ,   */(ArgumentReference&& argument, const Mixfix& mixfix)
XIEITE_ARROW(/* ... */)
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::functors::Mixfix<int(int)> half = [](int x) {
        return x / 2;
    };

    std::println("{}", 14 <half);
}
```
Output:
```
7
```
