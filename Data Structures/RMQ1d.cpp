// instructions, pay attention:
//1. input(i, val); **work with range[0,n)
//2. build_table();

struct RMQ1d{
	int n;
	int mxnsz;
	int K;
	vi LOG;
	vector<vll> st;
	
	RMQ1d(int sz){
		n=sz;
		mxnsz=n+10;
		LOG.resize(mxnsz);
		build_log();
		K=LOG[n]+1;
		st=vector<vll>(mxnsz,vll(K));
	}

	void input(int pos, ll val){
		st[pos][0]=val;
	}

	void build_log(){
		LOG[1]=0;
		for(int i=2;i<n+5;i++){
			LOG[i]=LOG[i/2]+1;
		}
	}

	void build_table(){
		for(int j=1;j<=K;j++){
			for(int i=0;i+(1<<j)<=n;i++){
				st[i][j]=gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
			}
		}
	}

	ll gcd_query(int a, int b){ //gcd value in range [a,b]
		int j=LOG[b-a+1];
		return gcd(st[a][j],st[b-(1<<j)+1][j]);
	}
};
