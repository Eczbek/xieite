# [xieite](../../xieite.md)::[system](../../system.md)::[StandardStreamsController<inputStream, outputStream>](../StandardStreamsController.md)::getPosition
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

<br/>

Gets the cursor's position in the terminal. Coordinates correlate to the `{ +x, -y }` cartesian quadrant

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
xieite::system::BufferPosition getPosition() noexcept;
```
### Return value
-  A `xieite::system::BufferPosition` - The cursor's current position
