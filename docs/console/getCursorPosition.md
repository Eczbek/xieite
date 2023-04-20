# `xieite::console::getPosition`
Defined in header [`<xieite/console/getPosition.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/console/getPosition.hpp)

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
- [`xieite::console::Position`](https://github.com/Eczbek/xieite/tree/main/docs/console/Position.md)
