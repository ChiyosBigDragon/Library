#include <bits/stdc++.h>
using namespace std;

// BEGIN CUT HERE
/**
 * @brief セグメント木
 * @tparam S 要素モノイド
 */
template<class S>
struct SegmentTree {
public:
	/**
	 * @brief 単位元で初期化
	 * @param N サイズ
	 * @param F 二項演算 (S, S) -> S 
 	 * @param e 要素モノイドの単位元
	 */
	SegmentTree(const size_t N, const function<S(S, S)>& F, const S& e) : SegmentTree(vector<S>(N, e), F, e) {}
	/**
	 * @brief 与配列で初期化
	 * @param v 配列
	 * @param F 二項演算 (S, S) -> S 
 	 * @param e 要素モノイドの単位元
	 */
	SegmentTree(const vector<S>& v, const function<S(S, S)>& F, const S& e) : F(F), e(e) {
		N = 1 << pow2(v.size());
		val = vector<S>(N << 1, e);
		for(size_t i = 0; i < v.size(); ++i) {
			val[N + i] = v[i];
		}
		for(size_t i = N - 1; i >= 1; --i) {
			update(i);
		}
	}
	/**
	 * @brief 1点更新
	 */
	void set(size_t idx, const S& _val) {
		assert(idx < N);
		idx += N;
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
		S valL = e;
		S valR = e;
		for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
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
	 * @brief 1点取得
	 */
	S get(const size_t idx) {
		assert(idx < N);
		return val[N + idx];
	}
	/**
	 * @brief 1点取得
	 */
	S operator[](const size_t idx) {
		assert(idx < N);
		return val[N + idx];
	}
private:
	const function<S(S, S)> F;
	const S e;
	size_t N;
	vector<S> val;
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
	 * @brief v[idx]の更新
	 */
	void update(size_t idx) {
		val[idx] = F(val[idx << 1], val[(idx << 1) | 1]);
	}
};
// END CUT HERE