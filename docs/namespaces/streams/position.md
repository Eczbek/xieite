# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:Position
Defined in header [<xieite/streams/position.hpp>](../../../include/xieite/streams/position.hpp)

&nbsp;

## Description
A class for storing a position in the terminal output buffer.

&nbsp;

## Synopses
#### 1)
```cpp
struct Position {
    int row;
    int column;

    constexpr Position(int, int);

    friend constexpr bool operator==(xieite::streams::Position, xieite::streams::Position);
};
```
##### Member variables
- row
- column
##### Member functions
- [Position](./structures/position/1/operators/constructor.md)
