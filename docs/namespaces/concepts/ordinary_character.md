# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:OrdinaryCharacter\<\>
Defined in fragment [xieite:concepts.OrdinaryCharacter](../../../src/concepts/ordinary_character.cpp)

&nbsp;

## Description
Specifies that a type is a narrow character, according to [the standard draft](https://eel.is/c++draft/basic.fundamental#7).

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept OrdinaryCharacter = xieite::concepts::SameAsAny<std::remove_cv_t<Type>, char, signed char, unsigned char>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::concepts::OrdinaryCharacter<char>);
    std::println("{}", xieite::concepts::OrdinaryCharacter<char8_t>);
}
```
Output:
```
true
false
```
