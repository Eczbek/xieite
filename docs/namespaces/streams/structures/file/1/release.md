# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[File](../../../file.md)\:\:release\(\)
Defined in fragment [xieite:streams.File](../../../../../../src/streams/file.cpp)

&nbsp;

## Description
Releases the stored `std::FILE*` and returns it.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] std::FILE* release() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto file = xieite::streams::File("test.txt");

    std::FILE* stream = file.release();
    // The stream will no longer be closed automatically
    std::fclose(stream);
}
```
