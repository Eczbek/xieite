# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:StandardHandle \{\}
Defined in header [<xieite/streams/standard_handle.hpp>](../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
A class for controlling standard IO with modes and styles. Currently only works on UNIX-like systems.

&nbsp;

## Synopsis
#### 1)
```cpp
struct StandardHandle {
    std::FILE* inputFile;
    std::FILE* outputFile;

    StandardHandle(std::FILE*, std::FILE*) noexcept;

    void setInputBlocking(bool) noexcept;

    void setInputEcho(bool) noexcept;

    void setInputCanon(bool) noexcept;

    void setInputSignals(bool) noexcept;

    void setOutputProcessing(bool) noexcept;

    void setForegroundColor(const xieite::streams::Color&) noexcept;

    void resetForegroundColor() noexcept;

    void setBackgroundColor(const xieite::streams::Color&) noexcept;

    void resetBackgroundColor() noexcept;

    void setTextBold(bool) noexcept;

    void setTextItalic(bool) noexcept;

    void setTextUnderlined(bool) noexcept;

    void setTextBlinking(bool) noexcept;

    void setTextInvisible(bool) noexcept;

    void setTextStriked(bool) noexcept;

    void setColorsSwapped(bool) noexcept;

    void resetStyles() noexcept;

    void resetModes() noexcept;

    xieite::streams::Position getCursorPosition() noexcept;

    void setCursorPosition(xieite::streams::Position) noexcept;

    void moveCursorPosition(xieite::streams::Position) noexcept;

    void setCursorVisible(bool) noexcept;

    void setCursorShapeBlock(bool) noexcept;

    void setCursorShapeUnderscore(bool) noexcept;

    void setCursorShapePipe(bool) noexcept;

    void setCursorAlternate(bool) noexcept;

    void setScreenAlternate(bool) noexcept;

    xieite::streams::Position getScreenSize() noexcept;

    void clearScreen() noexcept;

    void clearScreenUntil() noexcept;

    void clearScreenUntil(xieite::streams::Position) noexcept;

    void clearScreenFrom() noexcept;

    void clearScreenFrom(xieite::streams::Position) noexcept;

    void clearLine() noexcept;

    void clearLine(xieite::streams::Position) noexcept;

    void clearLineUntil() noexcept;

    void clearLineUntil(xieite::streams::Position) noexcept;

    void clearLineFrom() noexcept;

    void clearLineFrom(xieite::streams::Position) noexcept;

    char readCharacter() noexcept;

    std::string readString() noexcept;

    xieite::streams::Key readKey() noexcept;
};
```
- [setInputBlocking\(\)](./structures/standard_handle/1/set_input_blocking.md)
- [setInputEcho\(\)](./structures/standard_handle/1/set_input_echo.md)
- [setInputCanon\(\)](./structures/standard_handle/1/set_input_canon.md)
- [setInputSignals\(\)](./structures/standard_handle/1/set_input_signals.md)
- [setOutputProcessing\(\)](./structures/standard_handle/1/set_output_processing.md)
- [setForegroundColor\(\)](./structures/standard_handle/1/set_foreground_color.md)
- [resetForegroundColor\(\)](./structures/standard_handle/1/reset_foreground_color.md)
- [setBackgroundColor\(\)](./structures/standard_handle/1/set_background_color.md)
- [resetBackgroundColor\(\)](./structures/standard_handle/1/reset_background_color.md)
- [setTextBold\(\)](./structures/standard_handle/1/set_text_bold.md)
- [setTextItalic\(\)](./structures/standard_handle/1/set_text_italic.md)
- [setTextUnderlined\(\)](./structures/standard_handle/1/set_text_underlined.md)
- [setTextBlinking\(\)](./structures/standard_handle/1/set_text_blinking.md)
- [setTextInvisible\(\)](./structures/standard_handle/1/set_text_visible.md)
- [setTextStriked\(\)](./structures/standard_handle/1/set_text_striked.md)
- [setColorsSwapped\(\)](./structures/standard_handle/1/set_colors_swapped.md)
- [resetStyles\(\)](./structures/standard_handle/1/reset_styles.md)
- [getCursorPosition\(\)](./structures/standard_handle/1/get_cursor_position.md)
- [setCursorPosition\(\)](./structures/standard_handle/1/set_cursor_position.md)
- [moveCursorPosition\(\)](./structures/standard_handle/1/move_cursor_position.md)
- [setCursorVisible\(\)](./structures/standard_handle/1/set_cursor_visible.md)
- [setCursorAlternate\(\)](./structures/standard_handle/1/set_cursor_alternate.md)
- [setScreenAlternate\(\)](./structures/standard_handle/1/set_screen_alternate.md)
- [getScreenSize\(\)](./structures/standard_handle/1/get_screen_size.md)
- [clearScreen\(\)](./structures/standard_handle/1/clear_screen.md)
- [clearScreenUntil\(\)](./structures/standard_handle/1/clear_screen_until.md)
- [clearScreenFrom\(\)](./structures/standard_handle/1/clear_screen_from.md)
- [clearLine\(\)](./structures/standard_handle/1/clear_line.md)
- [clearLineUntil\(\)](./structures/standard_handle/1/clear_line_until.md)
- [clearLineFrom\(\)](./structures/standard_handle/1/clear_line_from.md)
- [readCharacter\(\)](./structures/standard_handle/1/read_character.md)
- [readString\(\)](./structures/standard_handle/1/read_string.md)
- [readKey\(\)](./structures/standard_handle/1/read_key.md)

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/color.hpp"
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setForegroundColor(xieite::streams::Color(255, 0, 0));

    std::println("Hello, world!");
}
```
Possible output:

![output](./structures/standard_handle/1/set_foreground_color.png)
