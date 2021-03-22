// make sure to pre-calc this only once!
// val[x] = # of unique prime factors of x
const int N=2e7+3;
int val[N]; //this line needs to be in the global area
vi primes;
for (int i=2; i<N; ++i) {
	if (!val[i]){
    	val[i] = 1;
    	primes.push_back(i);
	}
	for (int p : primes){
		if (i * p >= N) break;
		if (i % p == 0){
			val[i * p] = val[i];
			break;
		}
		else{
			val[i * p] = val[i] + 1;
		}
	}
}
