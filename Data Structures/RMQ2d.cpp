const int K = 9; //ceil(log(array size)) 
struct RMQ2d{
	int n,m; //mxn must be a bit larger
	int LOG[mxn];
	ll st[mxn][mxn][K][K];

	RMQ2d(int sz1, int sz2){
		n=sz1;
		m=sz2;
	}

	void input(int posx, int posy, ll val){
		st[posx][posy][0][0]=val;
	}

	void build_log(){
		LOG[1]=0;
		for(int i=2;i<mxn;i++){
			LOG[i]=LOG[i/2]+1;
		}
	}

	void build_table(){
		for(int i=0;i<=n;i++){
			for(int c=1;c<=K;c++){
				for(int j=0;j+(1<<c)<=m;j++){
					st[i][j][0][c]=max(st[i][j][0][c-1], st[i][j+(1<<(c-1))][0][c-1]);
				}
			}
		}
		for(int r=1;r<=K;r++){
			for(int c=0;c<=K;c++){
				for(int i=0;i+(1<<r)<=n;i++){
					for(int j=0;j+(1<<c)<=m;j++){
						st[i][j][r][c]=max(st[i][j][r-1][c], st[i+(1<<(r-1))][j][r-1][c]);
					}
				}
			}
		}
	}

	ll query(int y1, int x1, int y2, int x2){ //pay attention y,x,y,x
		int r=LOG[y2-y1+1];
		int c=LOG[x2-x1+1];
		ll m1 = max(st[y1][x1][r][c], st[y1][x2-(1<<c)+1][r][c]);
		ll m2 = max(st[y2-(1<<r)+1][x1][r][c], st[y2-(1<<r)+1][x2-(1<<c)+1][r][c]);
		return max(m1,m2);
	}
};
