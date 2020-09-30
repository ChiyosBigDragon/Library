#include <bits/stdc++.h>
using namespace std;

// BEGIN CUT HERE
/**
 * @brief セグメント木
 * @tparam S モノイド
 * @tparam F 二項演算 (S, S) -> S 
 * @tparam e モノイドの単位元
 */
template<class S, auto F, S e>
struct SegmentTree {
public:
	/**
	 * @brief 単位元で初期化
	 * @param _N サイズ
	 */
	SegmentTree(size_t _N) : SegmentTree(vector<S>(_N, e)) {}
	/**
	 * @brief 与配列で初期化
	 * @param _v 配列
	 */
	SegmentTree(const vector<S>& _v) {
		N = pow2(_v.size());
		v = vector<S>(N << 1, e);
		for(int i = 0; i < _v.size(); ++i) {
			v[N + i] = _v[i];
		}
		for(int i = N - 1; i >= 1; --i) {
			update(i);
		}
	}
	/**
	 * @brief 1点更新
	 */
	void set(size_t idx, const S val) {
		assert(idx < N);
		idx += N;
		v[idx] = val;
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
			valL = (l & 1) ? F(valL, v[l++]) : valL;
			valR = (r & 1) ? F(v[--r], valR) : valR;
		}
		return F(valL, valR);
	}
	/**
	 * @brief 1点取得
	 */
	S get(const size_t idx) {
		assert(idx < N);
		return v[N + idx];
	}
	/**
	 * @brief 1点取得
	 */
	S operator[](const size_t idx) {
		assert(idx < N);
		return v[N + idx];
	}
private:
	size_t N;
	vector<S> v;
	/**
	 * @return n <= k なる最小の2べき k
	 */
	size_t pow2(size_t n) {
		size_t sz = 1;
		while(sz < n) {
			sz <<= 1;
		}
		return sz;
	}
	/**
	 * @brief v[idx]の更新
	 */
	void update(size_t idx) {
		v[idx] = F(v[idx << 1], v[(idx << 1) | 1]);
	}
};
// END CUT HERE