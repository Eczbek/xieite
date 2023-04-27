# [`xieite`](../../../README.md)`::`[`terminal`](../../../docs/terminal.md)`::`[`ModeLock`](../../../docs/terminal/ModeLock.md)`::setCanonical`
Defined in header [`<xieite/terminal/ModeLock.hpp>`](../../../include/xieite/terminal/ModeLock.hpp)

<br/>

Enables or disables canonical mode. When it is disabled, the input is read by bytes instead of by lines, therefore anything typed is read immediately instead of waiting for a newline. Disabled by default.

<br/><br/>

## Synopsis

<br/>

```cpp
void setCanonical(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to enable or disable canonical mode.
