# [xieite](../xieite.md)::[system](../system.md)::getStreamFile
Defined in header [<xieite/system/getStreamFile.hpp>](../../include/xieite/system/getStreamFile.hpp)

<br/>

Extracts a `std::FILE*` from a stream

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Character = char, xieite::concepts::SameAsOrDerivedFrom<std::basic_istream<Character>, std::basic_ostream<Character>> Stream>
[[nodiscard]]
inline std::FILE* getStreamFile(const Stream& stream) noexcept;
```
### Template parameters
- `Character` - A character type, `char` by default
- `Stream` - A stream type satisfying `xieite::concepts::SameAsOrDerivedFrom` of `std::basic_istream` of `Character`, and `std::basic_ostream` of `Character`
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
