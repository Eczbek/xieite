# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:StandardHandle \{\}
Defined in header [<xieite/streams/standard_handle.hpp>](../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
A class for controlling standard IO with modes and styles. Requires `XIEITE_PLATFORM_TYPE_UNIX` to be true.

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

    template<std::size_t channels_>
    requires(channels_ >= 3)
    static constexpr std::string stringSetForegroundColor(const xieite::streams::Color<channels_>&) noexcept;

    template<std::size_t channels_>
    requires(channels_ >= 3)
    void setForegroundColor(const xieite::streams::Color<channels_>&) noexcept;

    static constexpr std::string stringResetForegroundColor() noexcept;

    void resetForegroundColor() noexcept;

    template<std::size_t channels_>
    requires(channels_ >= 3)
    static constexpr std::string stringSetBackgroundColor(const xieite::streams::Color<channels_>&) noexcept;

    template<std::size_t channels_>
    requires(channels_ >= 3)
    void setBackgroundColor(const xieite::streams::Color<channels_>&) noexcept;

    static constexpr std::string stringResetBackgroundColor() noexcept;

    void resetBackgroundColor() noexcept;

    static constexpr std::string stringSetTextBold(bool) noexcept;

    void setTextBold(bool) noexcept;

    static constexpr std::string stringSetTextItalic(bool) noexcept;

    void setTextItalic(bool) noexcept;

    static constexpr std::string stringSetTextUnderlined(bool) noexcept;

    void setTextUnderlined(bool) noexcept;

    static constexpr std::string stringSetTextBlinking(bool) noexcept;

    void setTextBlinking(bool) noexcept;

    static constexpr std::string stringSetTextInvisible(bool) noexcept;

    void setTextInvisible(bool) noexcept;

    static constexpr std::string stringSetTextStriked(bool) noexcept;

    void setTextStriked(bool) noexcept;

    static constexpr std::string stringSetColorsSwapped(bool) noexcept;

    void setColorsSwapped(bool) noexcept;

    static constexpr std::string stringResetStyles() noexcept;

    void resetStyles() noexcept;

    void resetModes() noexcept;

    xieite::streams::Position getCursorPosition() noexcept;

    static constexpr std::string stringSetCursorPosition(xieite::streams::Position) noexcept;

    void setCursorPosition(xieite::streams::Position) noexcept;

    static constexpr std::string stringMoveCursorPosition(xieite::streams::Position) noexcept;

    void moveCursorPosition(xieite::streams::Position) noexcept;

    static constexpr std::string stringSetCursorInvisible(bool) noexcept;

    void setCursorInvisible(bool) noexcept;

    static constexpr std::string stringSetCursorShapeBlock(bool) noexcept;

    void setCursorShapeBlock(bool) noexcept;

    static constexpr std::string stringSetCursorShapeUnderscore(bool) noexcept;

    void setCursorShapeUnderscore(bool) noexcept;

    static constexpr std::string stringSetCursorShapePipe(bool) noexcept;

    void setCursorShapePipe(bool) noexcept;

    static constexpr std::string stringSetCursorAlternate(bool) noexcept;

    void setCursorAlternate(bool) noexcept;

    static constexpr std::string stringSetScreenAlternate(bool) noexcept;

    void setScreenAlternate(bool) noexcept;

    xieite::streams::Position getScreenSize() noexcept;

    static constexpr std::string stringClearScreen() noexcept;

    void clearScreen() noexcept;

    static constexpr std::string stringClearScreenUntil() noexcept;

    void clearScreenUntil() noexcept;

    static constexpr std::string stringClearScreenFrom() noexcept;

    void clearScreenFrom() noexcept;

    static constexpr std::string stringClearLine() noexcept;

    void clearLine() noexcept;

    static constexpr std::string stringClearLineUntil() noexcept;

    void clearLineUntil() noexcept;

    static constexpr std::string stringClearLineFrom() noexcept;

    void clearLineFrom() noexcept;

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
- [stringSetForegroundColor\<\>\(\)](./structures/standard_handle/1/string_set_foreground_color.md)
- [setForegroundColor\<\>\(\)](./structures/standard_handle/1/set_foreground_color.md)
- [stringResetForegroundColor\(\)](./structures/standard_handle/1/string_reset_foreground_color.md)
- [resetForegroundColor\(\)](./structures/standard_handle/1/reset_foreground_color.md)
- [stringSetBackgroundColor\<\>\(\)](./structures/standard_handle/1/string_set_background_color.md)
- [setBackgroundColor\<\>\(\)](./structures/standard_handle/1/set_background_color.md)
- [stringResetBackgroundColor\(\)](./structures/standard_handle/1/string_reset_background_color.md)
- [resetBackgroundColor\(\)](./structures/standard_handle/1/reset_background_color.md)
- [stringSetTextBold\(\)](./structures/standard_handle/1/string_set_text_bold.md)
- [setTextBold\(\)](./structures/standard_handle/1/set_text_bold.md)
- [stringSetTextItalic\(\)](./structures/standard_handle/1/string_set_text_italic.md)
- [setTextItalic\(\)](./structures/standard_handle/1/set_text_italic.md)
- [stringSetTextUnderlined\(\)](./structures/standard_handle/1/string_set_text_underlined.md)
- [setTextUnderlined\(\)](./structures/standard_handle/1/set_text_underlined.md)
- [stringSetTextBlinking\(\)](./structures/standard_handle/1/string_set_text_blinking.md)
- [setTextBlinking\(\)](./structures/standard_handle/1/set_text_blinking.md)
- [stringSetTextInvisible\(\)](./structures/standard_handle/1/string_set_text_invisible.md)
- [setTextInvisible\(\)](./structures/standard_handle/1/set_text_visible.md)
- [stringSetTextStriked\(\)](./structures/standard_handle/1/string_set_text_striked.md)
- [setTextStriked\(\)](./structures/standard_handle/1/set_text_striked.md)
- [stringSetColorsSwapped\(\)](./structures/standard_handle/1/string_set_colors_swapped.md)
- [setColorsSwapped\(\)](./structures/standard_handle/1/set_colors_swapped.md)
- [stringResetStyles\(\)](./structures/standard_handle/1/string_reset_styles.md)
- [resetStyles\(\)](./structures/standard_handle/1/reset_styles.md)
- [getCursorPosition\(\)](./structures/standard_handle/1/get_cursor_position.md)
- [stringSetCursorPosition\(\)](./structures/standard_handle/1/string_set_cursor_position.md)
- [setCursorPosition\(\)](./structures/standard_handle/1/set_cursor_position.md)
- [stringMoveCursorPosition\(\)](./structures/standard_handle/1/string_move_cursor_position.md)
- [moveCursorPosition\(\)](./structures/standard_handle/1/move_cursor_position.md)
- [stringSetCursorInvisible\(\)](./structures/standard_handle/1/string_set_cursor_invisible.md)
- [setCursorInvisible\(\)](./structures/standard_handle/1/set_cursor_invisible.md)
- [stringSetCursorShapeBlock\(\)](./structures/standard_handle/1/string_set_cursor_shape_block.md)
- [setCursorShapeBlock\(\)](./structures/standard_handle/1/set_cursor_shape_block.md)
- [stringSetCursorShapeUnderscore\(\)](./structures/standard_handle/1/string_set_cursor_shape_underscore.md)
- [setCursorShapeUnderscore\(\)](./structures/standard_handle/1/set_cursor_shape_underscore.md)
- [stringSetCursorShapePipe\(\)](./structures/standard_handle/1/string_set_cursor_shape_pipe.md)
- [setCursorShapePipe\(\)](./structures/standard_handle/1/set_cursor_shape_pipe.md)
- [stringSetCursorAlternate\(\)](./structures/standard_handle/1/string_set_cursor_alternate.md)
- [setCursorAlternate\(\)](./structures/standard_handle/1/set_cursor_alternate.md)
- [stringSetScreenAlternate\(\)](./structures/standard_handle/1/string_set_screen_alternate.md)
- [setScreenAlternate\(\)](./structures/standard_handle/1/set_screen_alternate.md)
- [getScreenSize\(\)](./structures/standard_handle/1/get_screen_size.md)
- [stringClearScreen\(\)](./structures/standard_handle/1/string_clear_screen.md)
- [clearScreen\(\)](./structures/standard_handle/1/clear_screen.md)
- [stringClearScreenUntil\(\)](./structures/standard_handle/1/string_clear_screen_until.md)
- [clearScreenUntil\(\)](./structures/standard_handle/1/clear_screen_until.md)
- [stringClearScreenFrom\(\)](./structures/standard_handle/1/string_clear_screen_from.md)
- [clearScreenFrom\(\)](./structures/standard_handle/1/clear_screen_from.md)
- [stringClearLine\(\)](./structures/standard_handle/1/string_clear_line.md)
- [clearLine\(\)](./structures/standard_handle/1/clear_line.md)
- [stringClearLineUntil\(\)](./structures/standard_handle/1/string_clear_line_until.md)
- [clearLineUntil\(\)](./structures/standard_handle/1/clear_line_until.md)
- [stringClearLineFrom\(\)](./structures/standard_handle/1/string_clear_line_from.md)
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
