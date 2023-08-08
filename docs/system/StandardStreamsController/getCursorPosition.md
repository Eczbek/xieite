# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../StandardStreamsController.md)\:\:getPosition
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Gets the cursor's position in the terminal. Coordinates correlate to the `{ +x, -y }` cartesian quadrant

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
xieite::system::BufferPosition getPosition() noexcept;
```
#### Return type
-  A `xieite::system::BufferPosition` - The cursor's current position
