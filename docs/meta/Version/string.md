# [`xieite`](../../../README.md)`::`[`meta`](../../../docs/meta.md)`::`[`Version`](../../../docs/meta/Version.md)`::string`
Defined in header [`<xieite/meta/Version.hpp>`](../../../include/xieite/meta/Version.hpp)

<br/>

Stringifies a version into the format `v<major>.<minor>.<patch>[-<label>]`.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::string string() const noexcept;
```
### Return value
- A `std::string`
