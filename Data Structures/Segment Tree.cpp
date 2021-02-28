struct ST { 
	ll func(ll a, ll b) { return min(a, b); } // (any associative func)
	ll init_val = 1e18;

	ll seg[2*mxn];
	int n;

	ST(int sz = 0) {
		n=sz;
		for(int i=n;i<2*n;i++) seg[i]=init_val;
	}
	
	void update(int pos, ll val){ // set value at pos
		for(seg[pos+=n] = val; pos>1;pos>>=1){
			seg[pos>>1] = func(seg[pos],seg[pos^1]);
		}
	}

	ll query(int l, int r){  // min on interval [l, r]
		r++;
		ll res = init_val;
		for(l+=n, r+=n; l<r; l>>=1, r>>=1){
			if(l&1) res=func(res, seg[l++]);
			if(r&1) res=func(res, seg[--r]);
		}
		return res;
	}
};
