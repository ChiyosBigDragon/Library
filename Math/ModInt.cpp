#include <bits/stdc++.h>
using namespace std;

// BEGIN CUT HERE
/**
 * @tparam MOD
 */
template<int_fast64_t MOD>
struct ModInt {
public:
	int_fast64_t x;
	ModInt() : x(0) {}
	ModInt(int_fast64_t x) : x(x >= 0 ? x % MOD : (MOD - (-x) % MOD) % MOD) {}
	constexpr ModInt operator-() const {
		return ModInt(-x);
	}
	constexpr ModInt& operator+=(const ModInt& rhs) {
		x += rhs.x;
		if(x >= MOD) {
			x -= MOD;
		}
		return (*this);
	}
	constexpr ModInt operator+(const ModInt& rhs) const {
		return ModInt(*this) += rhs;
	}
	constexpr ModInt& operator-=(const ModInt& rhs) {
		x += MOD - rhs.x;
		if(x >= MOD) {
			x -= MOD;
		}
		return (*this);
	}
	constexpr ModInt operator-(const ModInt& rhs) const {
		return ModInt(*this) -= rhs;
	}
	constexpr ModInt& operator*=(const ModInt& rhs) {
		x *= rhs.x;
		if(x >= MOD) {
			x %= MOD;
		}
		return (*this);
	}
	constexpr ModInt operator*(const ModInt& rhs) const {
		return ModInt(*this) *= rhs;
	}
	constexpr ModInt& operator/=(const ModInt &rhs) {
		(*this) *= rhs.inverse();
		return (*this);
	}
	constexpr ModInt operator/(const ModInt& rhs) const {
		return ModInt(*this) /= rhs;
	}
	constexpr bool operator==(const ModInt& rhs) {
		return x == rhs.x;
	}
	constexpr bool operator!=(const ModInt& rhs) {
		return x != rhs.x;
	}
	/**
	 * @brief x ^ n
	 */
	constexpr ModInt pow(int_fast64_t n) const {
		int_fast64_t tmp = x;
		int_fast64_t ret = 1;
		while(n > 0){
			if(n & 1) {
				ret = ret * tmp % MOD;
			}
			tmp = tmp * tmp % MOD;
			n >>= static_cast<int_fast64_t>(1);
		}
		return ModInt(ret);
	}
	/**
	 * @brief 1 / x
	 */
	constexpr ModInt inverse() const {
		int_fast64_t a = x, b = MOD, s = 1, t = 0;
		while(b > 0) {
			int_fast64_t u = a / b;
			a -= u * b;
			s -= u * t;
			swap(a, b);
			swap(s, t);
		}
		return ModInt(s);
	}
	friend istream& operator>>(istream& lhs, ModInt<MOD>& rhs) {
		int_fast64_t x;
		lhs >> x;
		rhs = ModInt<MOD>(x);
		return lhs;
	}
	friend ostream& operator<<(ostream& lhs, const ModInt<MOD>& rhs) {
		return lhs << rhs.x;
	}
};
// END CUT HERE