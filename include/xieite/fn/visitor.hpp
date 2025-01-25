#pragma once

namespace xieite {
	template<typename... Fs>
	struct visitor : Fs... {
		using Fs::operator()...;
	};

	template<typename... Fs>
	visitor(Fs...) -> visitor<Fs...>;
}
