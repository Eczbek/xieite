#pragma once


namespace gcufl::io::escapeCodes {
	enum struct ScreenErasor
	: int {
		FromCursor = 0,
		UntilCursor,
		All
	};
}
