# [xieite](../../../xieite.md)\:\:[streams](../../../streams.md)\:\:StandardHandle
Defined in header [<xieite/streams/standard_handle.hpp>](../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
A class for controlling standard IO with modes and styles.

&nbsp;

## Synopses
#### 1)
```cpp
struct StandardHandle {
    std::istream& inputStream;
    std::ostream& outputStream;

    StandardHandle(std::istream&, std::ostream&);

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
- [setInputBlocking](./structures/standard_handle/1/set_input_blocking.md)
- [setInputEcho](./structures/standard_handle/1/set_input_echo.md)
- [setInputCanonical](./structures/standard_handle/1/set_input_canonical.md)
- [setInputSignals](./structures/standard_handle/1/set_input_signals.md)
- [setOutputProcessing](./structures/standard_handle/1/set_output_processing.md)
- [setForegroundColor](./structures/standard_handle/1/set_foreground_color.md)
- [resetForegroundColor](./structures/standard_handle/1/reset_foreground_color.md)
- [setBackgroundColor](./structures/standard_handle/1/set_background_color.md)
- [resetBackgroundColor](./structures/standard_handle/1/reset_background_color.md)
- [setTextBold](./structures/standard_handle/1/set_text_bold.md)
- [setTextItalic](./structures/standard_handle/1/set_text_italic.md)
- [setTextUnderline](./structures/standard_handle/1/set_text_underline.md)
- [setTextBlinking](./structures/standard_handle/1/set_text_blinking.md)
- [setColorsSwapped](./structures/standard_handle/1/set_colors_swapped.md)
- [setTextVisible](./structures/standard_handle/1/set_text_visible.md)
- [setTextStrikethrough](./structures/standard_handle/1/set_text_strikethrough.md)
- [resetStyles](./structures/standard_handle/1/reset_styles.md)
- [clearScreen](./structures/standard_handle/1/clear_screen.md)
- [clearLine](./structures/standard_handle/1/clear_line.md)
- [getCursorPosition](./structures/standard_handle/1/get_cursor_position.md)
- [setCursorPosition](./structures/standard_handle/1/set_cursor_position.md)
- [moveCursorPosition](./structures/standard_handle/1/move_cursor_position.md)
- [setCursorVisible](./structures/standard_handle/1/set_cursor_visible.md)
- [setCursorAlternative](./structures/standard_handle/1/set_cursor_alternative.md)
- [setScreenAlternative](./structures/standard_handle/1/set_screen_alternative.md)
- [getScreenSize](./structures/standard_handle/1/get_screen_size.md)
- [readCharacter](./structures/standard_handle/1/read_character.md)
- [readString](./structures/standard_handle/1/read_string.md)
- [readKey](./structures/standard_handle/1/read_key.md)
- [putBackString](./structures/standard_handle/1/put_back_string.md)
- [backspace](./structures/standard_handle/1/backspace.md)