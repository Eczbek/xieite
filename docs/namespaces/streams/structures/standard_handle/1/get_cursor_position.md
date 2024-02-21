# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:getPosition
Defined in header [<xieite/streams/standard_handle.hpp"](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Gets the cursor's position in the terminal. Coordinates correlate to the `{ +x, -y }` cartesian quadrant.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] xieite::streams::Position getPosition() const noexcept;
```
