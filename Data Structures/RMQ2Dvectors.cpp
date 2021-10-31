struct RMQ2d{
    int n,m,k1,k2; //mxn must be a bit larger
    int LOG[mxn];
    vector<vector<vector<vector<int>>>> stmin;
    vector<vector<vector<vector<int>>>> stmax;

    RMQ2d(int sz1, int sz2){
        build_log();
        n=sz1;
        m=sz2;
        k1=LOG[n];
        k2=LOG[m];
        stmin.resize(n+1, vector<vector<vector<int>>>(m+1, vector<vector<int>>(k1+1, vector<int>(k2+1))));
        stmax.resize(n+1, vector<vector<vector<int>>>(m+1, vector<vector<int>>(k1+1, vector<int>(k2+1))));

    }

    void input(int posx, int posy, ll val){
        stmin[posx][posy][0][0]=val;
        stmax[posx][posy][0][0]=val;
    }

    void build_log(){
        LOG[1]=0;
        for(int i=2;i<mxn;i++){
            LOG[i]=LOG[i/2]+1;
        }
    }

    void build_table(){
        for(int i=0;i<=n;i++){
            for(int c=1;c<=k2;c++){
                for(int j=0;j+(1<<c)<=m;j++){
                    stmin[i][j][0][c]=min(stmin[i][j][0][c-1], stmin[i][j+(1<<(c-1))][0][c-1]);
                    stmax[i][j][0][c]=max(stmax[i][j][0][c-1], stmax[i][j+(1<<(c-1))][0][c-1]);
                }
            }
        }
        for(int r=1;r<=k1;r++){
            for(int c=0;c<=k2;c++){
                for(int i=0;i+(1<<r)<=n;i++){
                    for(int j=0;j+(1<<c)<=m;j++){
                        stmin[i][j][r][c]=min(stmin[i][j][r-1][c], stmin[i+(1<<(r-1))][j][r-1][c]);
                        stmax[i][j][r][c]=max(stmax[i][j][r-1][c], stmax[i+(1<<(r-1))][j][r-1][c]);
                    }
                }
            }
        }
    }

    ll querymin(int y1, int x1, int y2, int x2){ //pay attention y,x,y,x
        int r=LOG[y2-y1+1];
        int c=LOG[x2-x1+1];
        ll m1 = min(stmin[y1][x1][r][c], stmin[y1][x2-(1<<c)+1][r][c]);
        ll m2 = min(stmin[y2-(1<<r)+1][x1][r][c], stmin[y2-(1<<r)+1][x2-(1<<c)+1][r][c]);
        return min(m1,m2);
    }
    ll querymax(int y1, int x1, int y2, int x2){ //pay attention y,x,y,x
        int r=LOG[y2-y1+1];
        int c=LOG[x2-x1+1];
        ll m1 = max(stmax[y1][x1][r][c], stmax[y1][x2-(1<<c)+1][r][c]);
        ll m2 = max(stmax[y2-(1<<r)+1][x1][r][c], stmax[y2-(1<<r)+1][x2-(1<<c)+1][r][c]);
        return max(m1,m2);
    }
};
