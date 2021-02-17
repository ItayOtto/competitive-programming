struct FT { //1 based indexing
	ll arr[mxn]={};
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < mxn; pos += pos&(-pos)) arr[pos] += dif;
	}
	ll query(int pos) { // sum of values in [1, pos]
		ll sm = 0;
		for (; pos > 0; pos -= pos &(-pos)) sm += arr[pos];
		return sm;
	}
	ll range(int l, int r){ // sum of values in [l, r]
		return query(r)-query(l-1);
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
