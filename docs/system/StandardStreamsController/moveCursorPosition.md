# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../StandardStreamsController.md)\:\:moveCursorPosition
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Moves the terminal cursor's position

&nbsp;

## Synopsis
```cpp
void moveCursorPosition(xieite::system::BufferPosition difference) noexcept;
```
#### Function parameters
- `difference` - A `xieite::system::BufferPosition`, how many rows and columns to move
