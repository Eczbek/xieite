export module xieite:system.Result;

import std;

export namespace xieite::system {
	struct Result {
		std::string output;
		int status = 0;
	};
}
