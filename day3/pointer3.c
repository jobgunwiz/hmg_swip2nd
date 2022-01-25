#include <stdio.h>

int main()
{
	char ch[5] = {"13579"};

	char* p_ch = ch;
	char* p_ch_bak = ch;

	for(int i = 0; i < 5; i++){
		printf("[%d]%p, %c \n", i, &ch[i], ch[i]);
		printf("\n");
	}	

	char t = *p_ch++;
	printf("1. t == %c, %c : %p\n",t, *p_ch, p_ch);

	p_ch = p_ch_bak;

	t = (*p_ch)++;
	printf("2. t == %c, %c : %p\n",t, *p_ch, p_ch);
	printf("first thing : %c\n", ch[0]);

	p_ch = p_ch_bak;
	t = *++p_ch;
	printf("3. t == %c, %c : %p\n",t, *p_ch, p_ch);
        printf("first thing : %c\n", ch[0]);


        p_ch = p_ch_bak;
        t = ++*p_ch;
        printf("4. t == %c, %c : %p\n",t, *p_ch, p_ch);
        printf("first thing : %c\n", ch[0]);


	return 0;
}
