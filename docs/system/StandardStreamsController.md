# [xieite](./xieite.md)::[system](../system.md)::StandardStreamsController
Defined in header [<xieite/system/StandardStreamsController.hpp>](../include/xieite/system/StandardStreamsController.hpp)

<br/>

A class for controlling standard text streams with modes and styles

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::istream& inputStream, std::ostream& outputStream>
struct StandardStreamsController {
	StandardStreamsController();

	void setInputBlocking(bool);

	void setInputEcho(bool);

	void setInputCanonical(bool);

	void setInputSignals(bool);

	void setInputProcessing(bool);

	void setTextColor(const xieite::graphics::Color&);

	void resetTextColor();

	void setHighlightColor(const xieite::graphics::Color&);

	void resetHighlightColor();

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

	xieite::system::OutputPosition getCursorPosition();

	void setCursorPosition(xieite::system::OutputPosition);

	void setCursorVisible(bool);

	void setCursorAlternative(bool);

	void setScreenAlternative(bool);

	xieite::system::OutputPosition getScreenSize();

	char readCharacter();

	std::string readString();

	void putBackString(std::string_view);
};
```
### Template parameters
- `inputStream` - A `std::istream` reference
- `outputStream` - A `std::ostream` reference
### Public members
<pre><code>StandardStreamsController/
|- <a href="./StandardStreamsController/constructor.md">StandardStreamsController</a>
|- <a href="./StandardStreamsController/setInputBlocking.md">setInputBlocking</a>
|- <a href="./StandardStreamsController/setInputEcho.md">setInputEcho</a>
|- <a href="./StandardStreamsController/setInputCanonical.md">setInputCanonical</a>
|- <a href="./StandardStreamsController/setInputSignals.md">setInputSignals</a>
|- <a href="./StandardStreamsController/setInputProcessing.md">setInputProcessing</a>
|- <a href="./StandardStreamsController/setTextColor.md">setTextColor</a>
|- <a href="./StandardStreamsController/resetTextColor.md">resetTextColor</a>
|- <a href="./StandardStreamsController/setHighlightColor.md">setHighlightColor</a>
|- <a href="./StandardStreamsController/resetHighlightColor.md">resetHighlightColor</a>
|- <a href="./StandardStreamsController/setTextBold.md">setTextBold</a>
|- <a href="./StandardStreamsController/setTextItalic.md">setTextItalic</a>
|- <a href="./StandardStreamsController/setTextUnderline.md">setTextUnderline</a>
|- <a href="./StandardStreamsController/setTextBlinking.md">setTextBlinking</a>
|- <a href="./StandardStreamsController/setColorsSwapped.md">setColorsSwapped</a>
|- <a href="./StandardStreamsController/setTextVisible.md">setTextVisible</a>
|- <a href="./StandardStreamsController/setTextStrikethrough.md">setTextStrikethrough</a>
|- <a href="./StandardStreamsController/resetStyles.md">resetStyles</a>
|- <a href="./StandardStreamsController/clearScreen.md">clearScreen</a>
|- <a href="./StandardStreamsController/clearLine.md">clearLine</a>
|- <a href="./StandardStreamsController/getCursorPosition.md">getCursorPosition</a>
|- <a href="./StandardStreamsController/setCursorPosition.md">setCursorPosition</a>
|- <a href="./StandardStreamsController/setCursorVisible.md">setCursorVisible</a>
|- <a href="./StandardStreamsController/setCursorAlternative.md">setCursorAlternative</a>
|- <a href="./StandardStreamsController/setScreenAlternative.md">setScreenAlternative</a>
|- <a href="./StandardStreamsController/getScreenSize.md">getScreenSize</a>
|- <a href="./StandardStreamsController/readCharacter.md">readCharacter</a>
|- <a href="./StandardStreamsController/readString.md">readString</a>
`- <a href="./StandardStreamsController/putBackString.md">putBackString</a>
</code></pre>
