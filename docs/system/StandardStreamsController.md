# [xieite](./xieite.md)\:\:[system](../system.md)\:\:StandardStreamsController
Defined in header [<xieite/system/StandardStreamsController.hpp>](../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
A class for controlling standard text streams with modes and styles.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::istream& inputStream, std::ostream& outputStream>
struct StandardStreamsController {
    StandardStreamsController();

    void setInputBlocking(bool);

    void setInputEcho(bool);

    void setInputCanonical(bool);

    void setInputSignals(bool);

    void setOutputProcessing(bool);

    void setForegroundColor(const xieite::graphics::Color&);

    void resetForegroundColor();

    void setBackgroundColor(const xieite::graphics::Color&);

    void resetBackgroundColor();

    void setTextBold(bool);

    void setTextItalic(bool);

    void setTextUnderline(bool);

    void setTextBlinking(bool);

    void setColorsSwapped(bool);

    void setTextVisible(bool);

    void setTextStrikethough(bool);

    void resetStyles();

    void clearScreen();

    void clearLine();

    xieite::system::BufferPosition getCursorPosition();

    void setCursorPosition(xieite::system::BufferPosition);

    void moveCursorPosition(xieite::system::BufferPosition);

    void setCursorVisible(bool);

    void setCursorAlternative(bool);

    void setScreenAlternative(bool);

    xieite::system::BufferPosition getScreenSize();

    char readCharacter();

    std::string readString();

    void putBackString(std::string_view);

    void backspace(std::size_t);
};
```
##### Member functions
- [StandardStreamsController](./StandardStreamsController/constructor.md)
- [setInputBlocking](./StandardStreamsController/setInputBlocking.md)
- [setInputEcho](./StandardStreamsController/setInputEcho.md)
- [setInputCanonical](./StandardStreamsController/setInputCanonical.md)
- [setInputSignals](./StandardStreamsController/setInputSignals.md)
- [setOutputProcessing](./StandardStreamsController/setOutputProcessing.md)
- [setForegroundColor](./StandardStreamsController/setForegroundColor.md)
- [resetForegroundColor](./StandardStreamsController/resetForegroundColor.md)
- [setBackgroundColor](./StandardStreamsController/setBackgroundColor.md)
- [resetBackgroundColor](./StandardStreamsController/resetBackgroundColor.md)
- [setTextBold](./StandardStreamsController/setTextBold.md)
- [setTextItalic](./StandardStreamsController/setTextItalic.md)
- [setTextUnderline](./StandardStreamsController/setTextUnderline.md)
- [setTextBlinking](./StandardStreamsController/setTextBlinking.md)
- [setColorsSwapped](./StandardStreamsController/setColorsSwapped.md)
- [setTextVisible](./StandardStreamsController/setTextVisible.md)
- [setTextStrikethrough](./StandardStreamsController/setTextStrikethrough.md)
- [resetStyles](./StandardStreamsController/resetStyles.md)
- [clearScreen](./StandardStreamsController/clearScreen.md)
- [clearLine](./StandardStreamsController/clearLine.md)
- [getCursorPosition](./StandardStreamsController/getCursorPosition.md)
- [setCursorPosition](./StandardStreamsController/setCursorPosition.md)
- [moveCursorPosition](./StandardStreamsController/moveCursorPosition.md)
- [setCursorVisible](./StandardStreamsController/setCursorVisible.md)
- [setCursorAlternative](./StandardStreamsController/setCursorAlternative.md)
- [setScreenAlternative](./StandardStreamsController/setScreenAlternative.md)
- [getScreenSize](./StandardStreamsController/getScreenSize.md)
- [readCharacter](./StandardStreamsController/readCharacter.md)
- [readString](./StandardStreamsController/readString.md)
- [putBackString](./StandardStreamsController/putBackString.md)
- [backspace](./StandardStreamsController/backspace.md)
