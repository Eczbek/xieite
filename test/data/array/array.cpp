#include <xte/data/array.hpp>
#include <xte/data/non_copyable.hpp>
#include <xte/data/non_movable.hpp>
#include <xte/meta/type.hpp>
#include <xte/preproc/template.hpp>
#include <xte/util/as_lvalue.hpp>
#include <xte/util/as_xvalue.hpp>
#include <iterator>
#include <ranges>

struct no_default_ctor {
	constexpr no_default_ctor(int) noexcept {}
};

struct throwing_default_ctor {
	constexpr throwing_default_ctor() noexcept(false) {}
};

struct throwing_copy_ctor {
	throwing_copy_ctor() = default;
	constexpr throwing_copy_ctor(const throwing_copy_ctor&) noexcept(false) {}
	throwing_copy_ctor(throwing_copy_ctor&&) = default;
};

struct throwing_move_ctor {
	throwing_move_ctor() = default;
	throwing_move_ctor(const throwing_move_ctor&) = default;
	constexpr throwing_move_ctor(throwing_move_ctor&&) noexcept(false) {}
};

struct throwing_copy_and_move_ctor {
	throwing_copy_and_move_ctor() = default;
	constexpr throwing_copy_and_move_ctor(const throwing_copy_and_move_ctor&) noexcept(false) {}
	constexpr throwing_copy_and_move_ctor(throwing_copy_and_move_ctor&&) noexcept(false) {}
};

consteval {
	XTE_TEMPLATE {
		static_assert(xte::array<int>().data() == nullptr);
		static_assert(xte::array<int>().size() == 0);
		static_assert(xte::array<int>().capacity() == 0);
		static_assert(requires { xte::array<xte::non_copyable>(); });
		static_assert(requires { xte::array<xte::non_movable>(); });
		static_assert(noexcept(xte::array<int>()));
		static_assert(noexcept(xte::array<throwing_default_ctor>()));

		static_assert((xte::array<int> {}).data() == nullptr);
		static_assert((xte::array<int> {}).size() == 0);
		static_assert((xte::array<int> {}).capacity() == 0);
		static_assert(requires { xte::array<xte::non_copyable> {}; });
		static_assert(requires { xte::array<xte::non_movable> {}; });
		static_assert(noexcept(xte::array<int> {}));
		static_assert(noexcept(xte::array<throwing_default_ctor> {}));

		static_assert(auto(xte::as_lvalue(xte::array<int>())).data() == nullptr);
		static_assert(auto(xte::as_lvalue(xte::array<int>())).size() == 0);
		static_assert(auto(xte::as_lvalue(xte::array<int>())).capacity() == 0);
		static_assert(!requires { auto(xte::as_lvalue(xte::array<xte::non_copyable>())); });
		static_assert(requires { auto(xte::as_lvalue(xte::array<xte::non_movable>())); });
		static_assert(!noexcept(auto(xte::as_lvalue(xte::array<int>()))));
		static_assert(!noexcept(auto(xte::as_lvalue(xte::array<throwing_default_ctor>()))));
		static_assert(!noexcept(auto(xte::as_lvalue(xte::array<throwing_copy_ctor>()))));
		static_assert(!noexcept(auto(xte::as_lvalue(xte::array<throwing_move_ctor>()))));

		static_assert(auto(xte::as_xvalue(xte::array<int>())).data() == nullptr);
		static_assert(auto(xte::as_xvalue(xte::array<int>())).size() == 0);
		static_assert(auto(xte::as_xvalue(xte::array<int>())).capacity() == 0);
		static_assert(requires { auto(xte::as_xvalue(xte::array<xte::non_copyable>())); });
		static_assert(requires { auto(xte::as_xvalue(xte::array<xte::non_movable>())); });
		static_assert(noexcept(auto(xte::as_xvalue(xte::array<int>()))));
		static_assert(noexcept(auto(xte::as_xvalue(xte::array<throwing_default_ctor>()))));
		static_assert(noexcept(auto(xte::as_xvalue(xte::array<throwing_copy_ctor>()))));
		static_assert(noexcept(auto(xte::as_xvalue(xte::array<throwing_move_ctor>()))));
		static_assert(noexcept(auto(xte::as_xvalue(xte::array<throwing_copy_and_move_ctor>()))));

		static_assert((xte::array<int> { 1, 2, 3 }).data() != nullptr);
		static_assert((xte::array<int> { 1, 2, 3 }).size() == 3);
		static_assert((xte::array<int> { 1, 2, 3 }).capacity() >= 3);
		static_assert((xte::array<xte::non_copyable> { {}, {}, {} }).data() != nullptr);
		static_assert((xte::array<xte::non_copyable> { {}, {}, {} }).size() == 3);
		static_assert((xte::array<xte::non_copyable> { {}, {}, {} }).capacity() >= 3);
		static_assert(!requires { xte::array<xte::non_movable> { {}, {}, {} }; });
		static_assert(!noexcept(xte::array<int> { 1, 2, 3 }));

		static_assert((xte::array { 1, 2, 3 }).data() != nullptr);
		static_assert((xte::array { 1, 2, 3 }).size() == 3);
		static_assert((xte::array { 1, 2, 3 }).capacity() >= 3);
		static_assert(!noexcept(xte::array { 1, 2, 3 }));

		static_assert((xte::array<int>(std::from_range, xte::as_lvalue(xte::array<int>()))).data() == nullptr);
		static_assert((xte::array<int>(std::from_range, xte::as_lvalue(xte::array<int>()))).size() == 0);
		static_assert((xte::array<int>(std::from_range, xte::as_lvalue(xte::array<int>()))).capacity() == 0);
		static_assert((xte::array<int>(std::from_range, xte::as_lvalue(xte::array<int> { 1, 2, 3 }))).data() != nullptr);
		static_assert((xte::array<int>(std::from_range, xte::as_lvalue(xte::array<int> { 1, 2, 3 }))).size() == 3);
		static_assert((xte::array<int>(std::from_range, xte::as_lvalue(xte::array<int> { 1, 2, 3 }))).capacity() >= 3);
		static_assert(!requires { xte::array<xte::non_copyable>(std::from_range, xte::as_lvalue(xte::array<xte::non_copyable>())); });
		static_assert(requires { xte::array<xte::non_movable>(std::from_range, xte::as_lvalue(xte::array<xte::non_movable>())); });
		static_assert(!noexcept(xte::array<int>(std::from_range, xte::as_lvalue(xte::array<int>()))));

		static_assert((xte::array<int>(std::from_range, xte::array<int>())).data() == nullptr);
		static_assert((xte::array<int>(std::from_range, xte::array<int>())).size() == 0);
		static_assert((xte::array<int>(std::from_range, xte::array<int>())).capacity() == 0);
		static_assert((xte::array<int>(std::from_range, xte::array<int> { 1, 2, 3 })).data() != nullptr);
		static_assert((xte::array<int>(std::from_range, xte::array<int> { 1, 2, 3 })).size() == 3);
		static_assert((xte::array<int>(std::from_range, xte::array<int> { 1, 2, 3 })).capacity() >= 3);
		static_assert(requires { xte::array<xte::non_copyable>(std::from_range, xte::array<xte::non_copyable>()); });
		static_assert(!requires { xte::array<xte::non_movable>(std::from_range, xte::array<xte::non_movable>()); });
		static_assert(!noexcept(xte::array<int>(std::from_range, xte::array<int>())));

		{
			static constexpr xte::type<int[]> a { 1, 2, 3 };
			static constexpr xte::type<xte::non_copyable[]> b { {}, {}, {} };
			static constexpr xte::type<xte::non_movable[]> c { {}, {}, {} };

			static_assert(xte::array<int>(std::begin(a), std::begin(a)).data() == nullptr);
			static_assert(xte::array<int>(std::begin(a), std::begin(a)).size() == 0);
			static_assert(xte::array<int>(std::begin(a), std::begin(a)).capacity() == 0);
			static_assert(xte::array<int>(std::begin(a), std::end(a)).data() != nullptr);
			static_assert(xte::array<int>(std::begin(a), std::end(a)).size() == 3);
			static_assert(xte::array<int>(std::begin(a), std::end(a)).capacity() >= 3);
			static_assert(!requires { xte::array<xte::non_copyable>(std::begin(b), std::end(b)); });
			static_assert(requires { xte::array<xte::non_movable>(std::begin(c), std::end(c)); });
			static_assert(!noexcept(xte::array<int>(std::begin(a), std::end(a))));
		}

		static_assert(xte::array<int>(0).data() == nullptr);
		static_assert(xte::array<int>(0).size() == 0);
		static_assert(xte::array<int>(0).capacity() == 0);
		static_assert(xte::array<int>(3).data() != nullptr);
		static_assert(xte::array<int>(3).size() == 3);
		static_assert(xte::array<int>(3).capacity() >= 3);
		static_assert(requires { xte::array<xte::non_copyable>(3); });
		static_assert(requires { xte::array<xte::non_movable>(3); });
		static_assert(!requires { xte::array<no_default_ctor>(3); });
		static_assert(!noexcept(xte::array<int>(3)));

		static_assert(xte::array<int>(3, 0).data() != nullptr);
		static_assert(xte::array<int>(3, 0).size() == 3);
		static_assert(xte::array<int>(3, 0).capacity() >= 3);
		static_assert(!requires { xte::array<xte::non_copyable>(3, {}); });
		static_assert(requires { xte::array<xte::non_movable>(3, {}); });
		static_assert(requires { xte::array<no_default_ctor>(3, { 0 }); });
		static_assert(!noexcept(xte::array<int>(3, 0)));
	}
}
