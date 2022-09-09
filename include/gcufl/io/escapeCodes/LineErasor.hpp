#pragma once


namespace gcufl::io::escapeCodes {
	enum struct LineErasor
	: int {
		FromCursor = 0,
		UntilCursor,
		All
	};
}
