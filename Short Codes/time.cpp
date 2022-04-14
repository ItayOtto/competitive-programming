//following two lines are initializers 
auto start = std::chrono::steady_clock::now();
std::mt19937 rnd(start.time_since_epoch().count());

//this is how to get time sice program started
(std::chrono::steady_clock::now() - start).count()
	
//example for usage. code will run for 3 seconds. useful for randomized problems.
while((std::chrono::steady_clock::now() - start).count() < 3e9){
