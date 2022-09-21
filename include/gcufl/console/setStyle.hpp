#pragma once


namespace gcufl::io {
	void setStyle(const int style) noexcept;

	void setStyle(const int effect, const int foreground) noexcept;

	void setStyle(const int effect, const int foreground, const int background) noexcept;
}
