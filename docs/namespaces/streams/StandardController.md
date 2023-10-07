# [xieite](../../../xieite.md)\:\:[streams](../../../streams.md)\:\:StandardController
Defined in header [<xieite/streams/StandardController.hpp>](../../../include/xieite/streams/StandardController.hpp)

&nbsp;

## Description
A class for controlling standard IO with modes and styles.

&nbsp;

## Synopses
#### 1)
```cpp
struct StandardController {
    std::istream& inputStream;
    std::ostream& outputStream;

    StandardController(std::istream&, std::ostream&);

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
- [setInputBlocking](./structures/StandardController/1/setInputBlocking.md)
- [setInputEcho](./structures/StandardController/1/setInputEcho.md)
- [setInputCanonical](./structures/StandardController/1/setInputCanonical.md)
- [setInputSignals](./structures/StandardController/1/setInputSignals.md)
- [setOutputProcessing](./structures/StandardController/1/setOutputProcessing.md)
- [setForegroundColor](./structures/StandardController/1/setForegroundColor.md)
- [resetForegroundColor](./structures/StandardController/1/resetForegroundColor.md)
- [setBackgroundColor](./structures/StandardController/1/setBackgroundColor.md)
- [resetBackgroundColor](./structures/StandardController/1/resetBackgroundColor.md)
- [setTextBold](./structures/StandardController/1/setTextBold.md)
- [setTextItalic](./structures/StandardController/1/setTextItalic.md)
- [setTextUnderline](./structures/StandardController/1/setTextUnderline.md)
- [setTextBlinking](./structures/StandardController/1/setTextBlinking.md)
- [setColorsSwapped](./structures/StandardController/1/setColorsSwapped.md)
- [setTextVisible](./structures/StandardController/1/setTextVisible.md)
- [setTextStrikethrough](./structures/StandardController/1/setTextStrikethrough.md)
- [resetStyles](./structures/StandardController/1/resetStyles.md)
- [clearScreen](./structures/StandardController/1/clearScreen.md)
- [clearLine](./structures/StandardController/1/clearLine.md)
- [getCursorPosition](./structures/StandardController/1/getCursorPosition.md)
- [setCursorPosition](./structures/StandardController/1/setCursorPosition.md)
- [moveCursorPosition](./structures/StandardController/1/moveCursorPosition.md)
- [setCursorVisible](./structures/StandardController/1/setCursorVisible.md)
- [setCursorAlternative](./structures/StandardController/1/setCursorAlternative.md)
- [setScreenAlternative](./structures/StandardController/1/setScreenAlternative.md)
- [getScreenSize](./structures/StandardController/1/getScreenSize.md)
- [readCharacter](./structures/StandardController/1/readCharacter.md)
- [readString](./structures/StandardController/1/readString.md)
- [readKey](./structures/StandardController/1/readKey.md)
- [putBackString](./structures/StandardController/1/putBackString.md)
- [backspace](./structures/StandardController/1/backspace.md)
