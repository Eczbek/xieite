# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:WideCharacter\<\>
Defined in fragment [xieite:concepts.WideCharacter](../../../src/concepts/wide_character.cpp)

&nbsp;

## Description
Specifies that a type is a wide character, according to [the standard draft](https://eel.is/c++draft/basic.fundamental#8).

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept WideCharacter = xieite::concepts::SameAsAny<std::remove_cv_t<Type>, wchar_t, char16_t, char32_t>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::WideCharacter<char16_t>);
    std::println("{}", xieite::concepts::WideCharacter<char>);
}
```
Output:
```
true
false
```
