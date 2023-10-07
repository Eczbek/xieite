# [xieite](../xieite.md)\:\:[streams](../streams.md)\:\:Position
Defined in header [<xieite/streams/Position.hpp>](../../include/xieite/streams/Position.hpp)

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
- [Position](./Position/1/operators/constructor.md)
