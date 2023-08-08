# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../StandardStreamsController.md)\:\:readString
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Reads the entire input buffer, clearing it in the process

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
std::string readString() noexcept;
```
#### Return type
- `std::string` - Anything that's in the input buffer
