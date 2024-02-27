# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:Pipe
Defined in header [<xieite/streams/pipe.hpp>](../../../include/xieite/streams/pipe.hpp)

&nbsp;

## Description
Provides a wrapper for a `std::FILE*` pipe, automatically closed upon destruction.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Pipe {
	std::FILE* const file;

	Pipe(const std::string&, const std::string&);
};
```
##### Member variables
- file
##### Member functions
- [Pipe](./structures/pipe/1/operators/constructor.md)
