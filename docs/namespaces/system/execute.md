# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:execute\(\)
Defined in fragment [xieite:system.execute](../../../src/system/execute.cpp)

&nbsp;

## Description
Executes a command and returns its output. Works on both UNIX-like and Windows systems.

&nbsp;

## Synopsis
#### 1)
```cpp
xieite::system::Result execute(std::string_view command) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto result = xieite::system::execute("echo Hello, world!");
    std::println("output: {}", result.output);
    std::println("status: {}", result.status);
}
```
Possible output:
```
output: Hello, world!

status: 0
```
