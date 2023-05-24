# [`xieite`](../../README.md)`::`[`terminal`](../../docs/terminal.md)`::getPosition`
Defined in header [`<xieite/terminal/getPosition.hpp>`](../../include/xieite/terminal/getPosition.hpp)

<br/>

Gets the cursor's position in the terminal. The coordinates correlate to the `{ +x, -y }` cartesian quadrant.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
inline xieite::terminal::Position getPosition() noexcept;
```
### Return value
- `xieite::terminal::Position` - The cursor's current position