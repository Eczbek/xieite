# [xieite](../../xieite.md)::[metadata](../../metadata.md)::[Version](../Version.md)::string
Defined in header [<xieite/metadata/Version.hpp>](../../../include/xieite/metadata/Version.hpp)

<br/>

Stringifies a version into the format `v<major>.<minor>.<patch>[-<label>]`

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::string string() const noexcept;
```
### Return value
- A `std::string`
