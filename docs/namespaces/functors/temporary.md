# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:temporary\<\>\(\)
Defined in fragment [xieite:functors.temporary](../../../src/functors/temporary.cpp)

&nbsp;

## Description
Creates a temporary object for the duration of the expression this is invoked from.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
[[nodiscard]] constexpr Type& temporary(Type&& value = Type()) noexcept;
```

&nbsp;

## Example
```cpp
import std.compat;
import xieite;

void old_c_garbage(int* status) {
    puts("ghghghghghghg");
};

int main() {
    // Don't care about status
    old_c_garbage(&xieite::functors::temporary<int>());
}
```
Output:
```
ghghghghghghg
```
