# [xieite](../../xieite.md)::[system](../../system.md)::[StandardStreamsController<inputStream, outputStream>](../StandardStreamsController.md)::moveCursorPosition
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

<br/>

Moves the terminal cursor's position

<br/><br/>

## Synopsis

<br/>

```cpp
void moveCursorPosition(xieite::system::BufferPosition difference) noexcept;
```
### Parameters
- `difference` - A `xieite::system::BufferPosition`, how many rows and columns to move
