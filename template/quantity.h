#pragma once

namespace tymeta {

template <typename T, T ...Args>
struct tyVector {
	using type = tyVector<T, Args...>;
};

using mass =		tyVector<int, 1, 0, 0, 0, 0, 0, 0>;
using length =		tyVector<int, 0, 1, 0, 0, 0, 0, 0>;
using time =		tyVector<int, 0, 0, 1, 0, 0, 0, 0>;
using charge =		tyVector<int, 0, 0, 0, 1, 0, 0, 0>;
using temperature = tyVector<int, 0, 0, 0, 0, 1, 0, 0>;
using intensity =	tyVector<int, 0, 0, 0, 0, 0, 1, 0>;
using amount_of_substance = tyVector<int, 0, 0, 0, 0, 0, 0, 1>;

template <typename T, typename Dimensions>
struct quantity {
	explicit quantity(T x): m_value(x) { }
	T value() const { return m_value; }
private:
	T m_value;
};

template <typename T, typename D> quantity<T, D>
operator+(const quantity<T, D> &lhs, const quantity<T, D> &rhs)
{
	return quantity<T, D>(lhs.value() + rhs.value());
}

template <typename T, typename D> quantity<T, D>
operator-(const quantity<T, D> &lhs, const quantity<T, D> &rhs)
{
	return quantity<T, D>(lhs.value() - rhs.value());
}

template <typename Tv, Tv v1, Tv v2>
struct tyPlus_impl {
	using type = tyPlus_impl<Tv, v1, v2>;
	const static Tv value = v1 + v2;
};

struct tyPlus {
	template <typename Tv, Tv v1, Tv v2>
	struct apply : tyPlus_impl<Tv, v1, v2> { };
};

template <typename Tv, Tv v1, Tv v2>
struct tyMinus_impl {
	using type = tyMinus_impl<Tv, v1, v2>;
	const static Tv value = v1 - v2;
};

struct tyMinus {
	template <typename Tv, Tv v1, Tv v2>
	struct apply : tyMinus_impl<Tv, v1, v2> { };
};

template <typename T1, typename T2, typename bop>
struct tyTransform { };

template <
	template<typename Tv, Tv ...Args> class T1,
	template<typename Tv, Tv ...Args> class T2,
	typename Tv,
	Tv ...Args1,
	Tv ...Args2,
	typename bop
>
struct tyTransform<T1<Tv, Args1...>, T2<Tv, Args2...>, bop> {
	using type = tyVector<Tv, 
			bop::template apply<Tv, Args1, Args2>::value...>;
};

template <typename T, typename D1, typename D2> 
quantity<T, typename tyTransform<D1, D2, tyPlus>::type>
operator*(const quantity<T, D1> &lhs, const quantity<T, D2> &rhs)
{
	using dim = typename tyTransform<D1, D2, tyPlus>::type;
	return quantity<T, dim>(lhs.value() * rhs.value());
}

template <typename T, typename D1, typename D2>
quantity<T, typename tyTransform<D1, D2, tyPlus>::type>
operator/(const quantity<T, D1> &lhs, const quantity<T, D2> &rhs)
{
	using dim = typename tyTransform<D1, D2, tyMinus>::type;
	return quantity<T, dim>(lhs.value() / rhs.value());
}

} // namespace tymeta

