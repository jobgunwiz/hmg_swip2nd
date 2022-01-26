#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int(*myCallback)(char* arg);
//not must, but needed for structure

//purpose : check password.. and authority
int result(char* arg)
{
	printf("%s", arg);
	printf("\n");
}

void checkPW(int password, myCallback callback)
{
	char* msg = "";

	switch (password) {
	case 1:

		//break;
	case 2:

		//break;
	case 3:
		msg = "login complete";
		break;
	default:
		msg = "failed";
		//just in one function.. so it's okay
		//return;
		break;
	}

	(*callback)(msg);
	//(*callback)("로그인 되었습니다");
}

int main()
{
	checkPW(1, &result);
	checkPW(2, &result);
	checkPW(3, &result);
	checkPW(4, &result);

	return 0;
}

