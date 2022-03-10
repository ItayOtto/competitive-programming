struct FT { //1 based indexing
	vll arr;
	ll mxnsz;
	FT(int sz){
		mxnsz = sz + 5;
		arr=vll(sz + 10, 0);
	}

	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < mxnsz; pos += pos & (-pos)) arr[pos] += dif;
	}

	ll query(int pos) { // sum of values in [1, pos]
		ll sm = 0;
		for (; pos > 0; pos -= pos &(-pos)) sm += arr[pos];
		return sm;
	}

	ll range(int l, int r){ // sum of values in [l, r]
		return query(r) - query(l - 1);
	}

	ll get(int pos){
		return range(pos,pos);
	}
};

//additional script for calculating number of inversions in permutation arr
/* 
int n;
ll inversions = 0;
for(int i = 0; i < n; i++) {
	inversions += range(arr[i]+1,n);
	update(arr[i], 1);
}*/
