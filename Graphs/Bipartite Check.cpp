vector<vi> adj(n);
vi s(n);
bool bipartite()
 {
	 bool bip = true;

	 for(int i = 0;i < n;i++)
		 s[i] = -1;

	 queue<int> q;

	 for(int i = 0;i < n;i++){
		 if(s[i] != -1)continue;

		 q.push(i);
		 s[i] = 0;

		 while(!q.empty()){
			 int v = q.front();
			 q.pop();

			 for(int u: adj[v]){
				 if(s[u] == -1){
					 s[u] = s[v] ^ 1;
					 q.push(u);
				 }else bip &= s[u] != s[v];
			 }
		 }
	 }
	 return bip;
 }
