# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:StandardController
Defined in header [<xieite/streams/StandardController.hpp>](../../include/xieite/streams/StandardController.hpp)

&nbsp;

## Description
A class for controlling standard IO with modes and styles.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::istream& inputStream, std::ostream& outputStream>
struct StandardController {
    void setInputBlocking(bool) const;

    void setInputEcho(bool) const;

    void setInputCanonical(bool) const;

    void setInputSignals(bool) const;

    void setOutputProcessing(bool) const;

    void setForegroundColor(const xieite::graphics::Color&) const;

    void resetForegroundColor() const;

    void setBackgroundColor(const xieite::graphics::Color&) const;

    void resetBackgroundColor() const;

    void setTextBold(bool) const;

    void setTextItalic(bool) const;

    void setTextUnderline(bool) const;

    void setTextBlinking(bool) const;

    void setColorsSwapped(bool) const;

    void setTextVisible(bool) const;

    void setTextStrikethough(bool) const;

    void resetStyles() const;

    void clearScreen() const;

    void clearLine() const;

    xieite::streams::Position getCursorPosition() const;

    void setCursorPosition(xieite::streams::Position) const;

    void moveCursorPosition(xieite::streams::Position) const;

    void setCursorVisible(bool) const;

    void setCursorAlternative(bool) const;

    void setScreenAlternative(bool) const;

    xieite::streams::Position getScreenSize() const;

    char readCharacter() const;

    std::string readString() const;

    xieite::streams::Key readKey() const;

    void putBackString(std::string_view) const;

    void backspace(std::size_t) const;
};
```
##### Member functions
- [setInputBlocking](./StandardController/1/setInputBlocking.md)
- [setInputEcho](./StandardController/1/setInputEcho.md)
- [setInputCanonical](./StandardController/1/setInputCanonical.md)
- [setInputSignals](./StandardController/1/setInputSignals.md)
- [setOutputProcessing](./StandardController/1/setOutputProcessing.md)
- [setForegroundColor](./StandardController/1/setForegroundColor.md)
- [resetForegroundColor](./StandardController/1/resetForegroundColor.md)
- [setBackgroundColor](./StandardController/1/setBackgroundColor.md)
- [resetBackgroundColor](./StandardController/1/resetBackgroundColor.md)
- [setTextBold](./StandardController/1/setTextBold.md)
- [setTextItalic](./StandardController/1/setTextItalic.md)
- [setTextUnderline](./StandardController/1/setTextUnderline.md)
- [setTextBlinking](./StandardController/1/setTextBlinking.md)
- [setColorsSwapped](./StandardController/1/setColorsSwapped.md)
- [setTextVisible](./StandardController/1/setTextVisible.md)
- [setTextStrikethrough](./StandardController/1/setTextStrikethrough.md)
- [resetStyles](./StandardController/1/resetStyles.md)
- [clearScreen](./StandardController/1/clearScreen.md)
- [clearLine](./StandardController/1/clearLine.md)
- [getCursorPosition](./StandardController/1/getCursorPosition.md)
- [setCursorPosition](./StandardController/1/setCursorPosition.md)
- [moveCursorPosition](./StandardController/1/moveCursorPosition.md)
- [setCursorVisible](./StandardController/1/setCursorVisible.md)
- [setCursorAlternative](./StandardController/1/setCursorAlternative.md)
- [setScreenAlternative](./StandardController/1/setScreenAlternative.md)
- [getScreenSize](./StandardController/1/getScreenSize.md)
- [readCharacter](./StandardController/1/readCharacter.md)
- [readString](./StandardController/1/readString.md)
- [readKey](./StandardController/1/readKey.md)
- [putBackString](./StandardController/1/putBackString.md)
- [backspace](./StandardController/1/backspace.md)
