struct DSU {
	vector<int> link;

	DSU(int x) {init(x);}

	void init(int x) {
		link.assign(x,-1);
	}

	bool merge(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (link[x] > link[y]) swap(x,y);
		link[x] += link[y];
		link[y] = x;
		return true; 
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}
 
	int root(int u){
		while(link[u] >= 0 && link[link[u]]>=0) u=link[u]=link[link[u]];
		if(link[u]<0) return u;
		if(link[link[u]<0]) return link[u];
	}

	int size(int u){
		return -link[root(u)];
	}
};
