export module xieite:containers.CopyMoveConstructible;

import std;
import :containers.MaybeMoveConstructible;

export namespace xieite::containers {
	template<typename Type>
	using CopyMoveConstructible = xieite::containers::MaybeMoveConstructible<std::is_move_constructible_v<Type>>;
}
