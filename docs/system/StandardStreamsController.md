# [xieite](../xieite.md)\:\:[system](../system.md)\:\:StandardStreamsController
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
	
    xieite::system::BufferPosition readArrow();

    void putBackString(std::string_view);

    void backspace(std::size_t);
};
```
##### Member functions
- [StandardStreamsController](./StandardStreamsController/1/constructor.md)
- [setInputBlocking](./StandardStreamsController/1/setInputBlocking.md)
- [setInputEcho](./StandardStreamsController/1/setInputEcho.md)
- [setInputCanonical](./StandardStreamsController/1/setInputCanonical.md)
- [setInputSignals](./StandardStreamsController/1/setInputSignals.md)
- [setOutputProcessing](./StandardStreamsController/1/setOutputProcessing.md)
- [setForegroundColor](./StandardStreamsController/1/setForegroundColor.md)
- [resetForegroundColor](./StandardStreamsController/1/resetForegroundColor.md)
- [setBackgroundColor](./StandardStreamsController/1/setBackgroundColor.md)
- [resetBackgroundColor](./StandardStreamsController/1/resetBackgroundColor.md)
- [setTextBold](./StandardStreamsController/1/setTextBold.md)
- [setTextItalic](./StandardStreamsController/1/setTextItalic.md)
- [setTextUnderline](./StandardStreamsController/1/setTextUnderline.md)
- [setTextBlinking](./StandardStreamsController/1/setTextBlinking.md)
- [setColorsSwapped](./StandardStreamsController/1/setColorsSwapped.md)
- [setTextVisible](./StandardStreamsController/1/setTextVisible.md)
- [setTextStrikethrough](./StandardStreamsController/1/setTextStrikethrough.md)
- [resetStyles](./StandardStreamsController/1/resetStyles.md)
- [clearScreen](./StandardStreamsController/1/clearScreen.md)
- [clearLine](./StandardStreamsController/1/clearLine.md)
- [getCursorPosition](./StandardStreamsController/1/getCursorPosition.md)
- [setCursorPosition](./StandardStreamsController/1/setCursorPosition.md)
- [moveCursorPosition](./StandardStreamsController/1/moveCursorPosition.md)
- [setCursorVisible](./StandardStreamsController/1/setCursorVisible.md)
- [setCursorAlternative](./StandardStreamsController/1/setCursorAlternative.md)
- [setScreenAlternative](./StandardStreamsController/1/setScreenAlternative.md)
- [getScreenSize](./StandardStreamsController/1/getScreenSize.md)
- [readCharacter](./StandardStreamsController/1/readCharacter.md)
- [readString](./StandardStreamsController/1/readString.md)
- [readArrow](./StandardStreamsController/1/readArrow.md)
- [putBackString](./StandardStreamsController/1/putBackString.md)
- [backspace](./StandardStreamsController/1/backspace.md)
