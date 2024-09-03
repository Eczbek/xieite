# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:cleanStatus\(\)
Defined in fragment [xieite:system.cleanStatus](../../../src/system/clean_status.cpp)

&nbsp;

## Description
Cleans the exit status code of a process.

&nbsp;

## Synopsis
#### 1)
```cpp
inline int cleanStatus(int status) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::system::cleanStatus(16384));
}
```
Possible output:
```
64
```
