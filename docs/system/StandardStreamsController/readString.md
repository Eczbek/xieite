# [xieite](../../xieite.md)::[system](../../system.md)::[StandardStreamsController<inputStream, outputStream>](../StandardStreamsController.md)::readString
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

<br/>

Reads the entire input buffer, clearing it in the process

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
std::string readString() noexcept;
```
### Return value
- A `std::string` - Anything that's in the input buffer
