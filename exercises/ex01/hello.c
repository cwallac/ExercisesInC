int main() {
	/*
	Optimization removes unneeded assignments. In this case, we do not really need
	the value of x, we know x will be 5 and we are only printing the value of y so
	x is never assigned in memory and instead y is assigned and printed out. 
	*/
	int x = 5;
	int y = x + 1;
	printf(y);
}