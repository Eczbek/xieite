# [xieite](../xieite.md)::[system](../system.md)::openFilePipe
Defined in header [<xieite/system/openFilePipe.hpp>](../../include/xieite/system/openFilePipe.hpp)

<br/>

Opens a file pipe

<br/><br/>

## Synopsis

<br/>

```cpp
inline std::FILE* openFilePipe(const char* command, const char* mode) noexcept;
```
### Parameters
- `command` - A constant `char` pointer
- `mode` - Another constant `char` pointer
### Return value
- A `std::FILE` pointer
