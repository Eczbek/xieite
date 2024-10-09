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
friend constexpr Return operator/*   ->* * / % + - << >> <=> < <= > >= == != & ^ | && || *= /= %= += -= <<= >>= &= ^= |= ,   */(const Mixfix& mixfix, ArgumentReference&& argument)
XIEITE_ARROW_BASE(/* ... */)
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::functors::Mixfix<int(int)> square = [](int x) {
        return x * x;
    };

    std::println("{}", square> 2);
}
```
Output:
```
4
```
