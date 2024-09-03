# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:readString\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Reads the entire input buffer, clearing it in the process.

&nbsp;

## Synopsis
#### 1)
```cpp
std::string readString() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::println("{}", terminal.readString());
}
```
Possible output:
```
test
```
