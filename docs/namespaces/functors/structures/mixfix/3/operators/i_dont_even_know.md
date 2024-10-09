# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Mixfix<Return(LeftArgument, RightArgument)>](../../../../mixfix.md)\:\:operator???\<\>\(\)
Defined in fragment [xieite:functors.Mixfix](../../../../../../../src/functors/mixfix.cpp)

&nbsp;

## Description
Returns an intermediate state which must be used immediately.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<LeftArgument> LeftArgumentReference>
[[nodiscard]] friend constexpr auto operator/*   ->* * / % + - << >> <=> < <= > >= == != & ^ | && || *= /= %= += -= <<= >>= &= ^= |= ,   */(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(/* ... */))
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::types::Mixfix<int(int, int)> add = [](int x, int y) {
        return x + y;
    };

    std::println("{}", 5 <add> 7);
}
```
Output:
```
12
```
