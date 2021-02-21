// instructions, pay attention:
//1. input(i, val); **work with range[0,n)
//2. build_log();
//3. build_table();


const int K = 18; //ceil(log(array size))
struct RMQ1d{
	int n; //mxn must be a bit larger than n
	int LOG[mxn];
	ll st[mxn][K];
	
	RMQ1d(int sz){
		n=sz;
	}

	void input(int pos, ll val){
		st[pos][0]=val;
	}

	void build_log(){
		LOG[1]=0;
		for(int i=2;i<mxn;i++){
			LOG[i]=LOG[i/2]+1;
		}
	}

	void build_table(){
		for(int j=1;j<=K;j++){
			for(int i=0;i+(1<<j)<=n;i++){
				st[i][j]=min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
			}
		}
	}

	ll min_query(int a, int b){ //min value in range [a,b]
		int j=LOG[b-a+1];
		return min(st[a][j],st[b-(1<<j)+1][j]);
	}
};
