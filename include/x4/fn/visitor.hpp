#pragma once

namespace x4 {
	template<typename... Fs>
	struct visitor : Fs... {
		using Fs::operator()...;
	};

	template<typename... Fs>
	visitor(Fs...) -> visitor<Fs...>;
}
