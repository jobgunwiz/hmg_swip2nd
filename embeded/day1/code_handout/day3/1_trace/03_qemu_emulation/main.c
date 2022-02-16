char str1[10] = "abcd";
int x = 10;
int y;
static int z;

int main(){
	int a = 10;
	static int b = 20;
	char str2[10] = "ijklmn";
	char str3[10];

	x = x + a;
	y = x + b;
	z = y;
	b = z;

	str3[0] = str1[0];
	str3[1] = str1[1];

	str2[0] = str3[0];
	str2[1] = str3[1];

	str1[0] = str2[2];
	str1[1] = str2[3];

	while(1);
}
