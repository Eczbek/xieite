# `xieite::console::getPosition`
Defined in header [`<xieite/console/getPosition.hpp>`](../../include/xieite/console/getPosition.hpp)

<br/>

Gets the cursor's position in the terminal. The coordinates correlate to the `{ +x, -y }` cartesian quadrant.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
inline xieite::console::Position getPosition() noexcept;
```
### Return value
- `xieite::console::Position` - The cursor's current position

<br/><br/>

## See also
- [`xieite::console::Position`](../../docs/console/Position.md)
