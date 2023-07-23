# [xieite](../xieite.md)::[system](../system.md)::getStreamFile
Defined in header [<xieite/system/getStreamFile.hpp>](../../include/xieite/system/getStreamFile.hpp)

<br/>

Extracts a `std::FILE*` from a stream

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::SameAsOrDerivedFrom<std::istream, std::ostream> Stream>
[[nodiscard]]
inline std::FILE* getStreamFile(const Stream& stream) noexcept;
```
### Template parameters
- `Stream` - A stream type satisfying `xieite::concepts::SameAsOrDerivedFrom` of `std::istream` and `std::ostream`
### Parameters
- `stream` - A `Stream` constant reference
### Return value
- A `std::FILE` pointer

<br/><br/>

## Example
```cpp
#include <cstdio>
#include <iostream>
#include <xieite/system/getStreamFile.hpp>

int main() {
	std::fprintf(xieite::system::getStreamFile(std::cout), "Hello, world!\n");
}
```
Output:
```
Hello, world!
```
