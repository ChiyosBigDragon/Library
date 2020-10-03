#include <bits/stdc++.h>
using namespace std;

// BEGIN CUT HERE
/**
 * @brief 遅延評価セグメント木
 * @tparam S 要素モノイド
 * @tparam T 作用素モノイド
 */
template<class S, class T>
struct LazySegmentTree {
public:
	/**
	 * @brief 単位元で初期化
	 * @param N サイズ
	 * @param F 二項演算 (S, S) -> S
	 * @param G 二項演算 (S, T) -> S
	 * @param H 二項演算 (T, T) -> T
	 * @param se 要素モノイドの単位元
	 * @param te 作用素モノイドの単位元
	 */
	LazySegmentTree(const size_t N, const function<S(S, S)>& F, const function<S(S, T)>& G, const function<T(T, T)>& H, const S& se, const T& te) : LazySegmentTree(vector<S>(N, se), F, G, H, se, te) {}
	/**
	 * @brief 与配列で初期化
	 * @param v 配列
	 * @param F 二項演算 (S, S) -> S
	 * @param G 二項演算 (S, T) -> S
	 * @param H 二項演算 (T, T) -> T
	 * @param se 要素モノイドの単位元
	 * @param te 作用素モノイドの単位元
	 */
	LazySegmentTree(const vector<S>& v, const function<S(S, S)>& F, const function<S(S, T)>& G, const function<T(T, T)>& H, const S& se, const T& te) : F(F), G(G), H(H), se(se), te(te) {
		height = pow2(v.size());
		N = 1 << height;
		val = vector<S>(N << 1, se);
		lazy = vector<T>(N << 1, te);
		for(int i = 0; i < v.size(); ++i) {
			val[N + i] = v[i];
		}
		for(int i = N - 1; i >= 1; --i) {
			update(i);
		}
	}
	/**
	 * @brief 1点更新
	 */
	void set(size_t idx, const S& _val) {
		assert(idx < N);
		idx += N;
		for(size_t i = height; i >= 1; --i) {
			apply(idx >> i, lazy[idx >> i]);
		}
		val[idx] = _val;
		while(idx > 1) {
			idx >>= 1;
			update(idx);
		}
	}
	/**
	 * @brief 区間取得[l, r)
	 */
	S get(size_t l, size_t r) {
		assert(l < r and r <= N);
		l += N;
		r += N;
		for(size_t i = height; i >= 1; --i) {
			if((l >> i) << i != l) apply(l >> i, lazy[l >> i]);
			if((r >> i) << i != r) apply((r - 1) >> i, lazy[(r - 1) >> i]);
		}
		S valL = se;
		S valR = se;
		for(; l < r; l >>= 1, r >>= 1) {
			if(l & 1) {
				valL = F(valL, val[l++]);
			}
			if(r & 1) {
				valR = F(val[--r], valR);
			}
		}
		return F(valL, valR);
	}
	/**
	 * @brief 区間作用[l, r)
	 */
	void apply(size_t l, size_t r, const T& _val) {
		assert(l < r and r <= N);
		l += N;
		r += N;
		for(size_t i = height; i >= 1; --i) {
			if((l >> i) << i != l) apply(l >> i, lazy[l >> i]);
			if((r >> i) << i != r) apply((r - 1) >> i, lazy[(r - 1) >> i]);
		}
		for(size_t _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
			if(_l & 1) {
				val[_l] = G(val[_l], _val);
				lazy[_l] = H(lazy[_l], _val);
				++_l;
			}
			if(_r & 1) {
				--_r;
				val[_r] = G(val[_r], _val);
				lazy[_r] = H(lazy[_r], _val);
			}
		}
		for(size_t i = 1; i <= height; ++i) {
			if((l >> i) << i != l) update(l >> i);
			if((r >> i) << i != r) update((r - 1) >> i);
		}
	}
	/**
	 * @brief 1点取得
	 */
	S get(size_t idx) {
		assert(idx < N);
		idx += N;
		for(size_t i = height; i >= 1; --i) {
			apply(idx >> i, lazy[idx >> i]);
		}
		return val[idx];
	}
	/**
	 * @brief 1点取得
	 */
	S operator[](const size_t idx) {
		assert(idx < N);
		return get(idx);
	}
private:
	const function<S(S, S)> F;
	const function<S(S, T)> G;
	const function<T(T, T)> H;
	const S se;
	const T te;
	size_t N;
	size_t height;
	vector<S> val;
	vector<T> lazy;
	/**
	 * @return n <= 2^k なる最小の k
	 */
	size_t pow2(const size_t n) {
		size_t k = 0;
		while((1 << k) < n) {
			++k;
		}
		return k;
	}
	/**
	 * @brief val[idx]の更新
	 */
	void update(const size_t idx) {
		val[idx] = F(val[idx << 1], val[(idx << 1) | 1]);
	}
	/**
	 * @brief val[idx]からの伝播
	 */
	void apply(const size_t idx, const T& _val) {
		if(lazy[idx] != te) {
			val[idx << 1] = G(val[idx << 1], _val);
			val[(idx << 1) | 1] = G(val[(idx << 1) | 1], _val);
			lazy[idx << 1] = H(lazy[idx << 1], _val);
			lazy[(idx << 1) | 1] = H(lazy[(idx << 1) | 1], _val);
			lazy[idx] = te;
		}
	}
};
// END CUT HERE
