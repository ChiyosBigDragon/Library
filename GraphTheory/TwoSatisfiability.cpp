#include <bits/stdc++.h>
using namespace std;

#include "./StronglyConnectedComponents.cpp"

// BEGIN CUT HERE
struct TwoSatisfiability {
	const int V;
	// pos[x] := xの真理値
	vector<bool> pos;
	StronglyConnectedComponents scc;
	TwoSatisfiability(const int V) : V(V), pos(vector<bool>(2 * V)), scc(StronglyConnectedComponents(2 * V)) {}
	// A -> B <=> not B -> not A
	inline void addIF(int A, const bool Apos, int B, const bool Bpos) {
		if(not Apos) A = NOT(A);
		if(not Bpos) B = NOT(B);
		scc.addEdge(A, B); // A -> B
		scc.addEdge(NOT(B), NOT(A)); // not B -> not A
	}
	// A <=> (not A -> A)
	void addUNARY(const int A, const bool Apos) {
		addIF(A, not Apos, A, Apos); // not A -> A
	}
	// A or B <=> not A -> B
	void addOR(const int A, const bool Apos, const int B, const bool Bpos) {
		addIF(A, not Apos, B, Bpos); // not A -> B
	}
	// not(A and B) => A -> not B
	void addNAND(const int A, const bool Apos, const int B, const bool Bpos) {
		addIF(A, Apos, B, not Bpos); // A -> not B
	}
	// A xor B <=> not(A and B) and not(not A and not B)
	void addXOR(const int A, const bool Apos, const int B, const bool Bpos) {
		addNAND(A, Apos, B, Bpos); // not(A and B)
		addNAND(A, not Apos, B, not Bpos); // not(not A and not B)
	}
	// not(A xor B) <=> A xor not B
	void addXNOR(const int A, const bool Apos, const int B, const bool Bpos) {
		addXOR(A, Apos, B, not Bpos); // A xor not B
	}
	bool solve() {
		scc.build();
		for(int i = 0; i < V; ++i) {
			if(scc.get(i) == scc.get(i + V)) {
				return false;
			}
			pos[i] = (scc.get(i) > scc.get(i + V));
		}
		return true;
	}
	bool get(int x) {
		return pos[x];
	}
	private:
	constexpr int NOT(const int A) const {
		return (A + V) % (2 * V);
	}
};
// END CUT HERE