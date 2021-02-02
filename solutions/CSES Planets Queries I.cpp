---
id: cses-1750
source: CSES
title: Planet Queries I
author: Dong Liu
---

Simply construct a parent matrix (in powers of 2), then answer each query by jumping from the starting node based on the binary representation of the distance.

Since the query distances can be up to $10^9$, we set the maximum depth to $\mathcal ceil(\log_2{10^9}) = 30$.

**Time Complexity**: $\mathcal{O}(N\log N)$

<LanguageSection>

<CPPSection>

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
const int MAXD = 30; // ceil(log2(10^9))

// number of planets and queries
int n, q; 

// parent matrix where [i][j] corresponds to i's (2^j)th parent
int parent[MAXN][MAXD]; 

int jump(int a, int d) {
	for(int i=0; i<MAXD; i++) if(d & (1<<i)) 
		a = parent[a][i];
	return a;
}

int main() {
	cin >> n >> q;
	for(int i=1; i<=n; i++) {
		cin >> parent[i][0];
	}
	// evaluate the parent matrix
	for(int d=1; d<MAXD; d++)
	for(int i=1; i<=n; i++) {
		parent[i][d] = parent[parent[i][d-1]][d-1];
	}
	// process queries
	while(q--) {
		int a, d;
		cin >> a >> d;
		cout << jump(a, d) << '\n';
	}
}

```

</CPPSection>

</LanguageSection>
