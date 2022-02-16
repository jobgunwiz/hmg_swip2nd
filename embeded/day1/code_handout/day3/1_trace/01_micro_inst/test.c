int foo(int n) {
	int z;
	z = n + 4;
	return z;
}

void foo2(int g, int h, int i, int j) {
	int f;

	f = (g+h)-(i+j);
}

int main() {
	int s;
	int y;

	s = 1;	
	y = s + 2;
	y = y + foo(y);
	return y;
}
