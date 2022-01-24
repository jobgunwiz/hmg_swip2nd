#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// 문1)
	// int score [2][3] 배열 변수 선언과 -1값으로 초기화하세요
	// char result[2][3] 배열 변수 선언과 ‘F’ 값으로 초기화하세요
	int score[2][3] = { -1, -1, -1, -1, -1, -1};
	char result[2][3] = { 'F', 'F', 'F', 'F', 'F', 'F'};

	//int     score;
	//char    result;

	// 문2) score 0,0과, 1,2 요소의 값을 출력하세요
	printf("score[0][0] == %d, score[1][2] == %d \n", score[0][0], score[1][2] );//"문2=>    // <- 작성
	// 문3)sizeof를 이용해서 각각 요소의 크기를 출력하세요
	printf("sizeof score == %d, sizeof score[0] == %d, sizeof score[0][0] == %d\n", sizeof(score), sizeof(score[0]), sizeof(score[0][0]));//"문3=>    // <- 작성
	// 문3 이어서) sizeof를 이요하여 배열 요소의 총 수를 계산해서 출력하세요
	printf("\t 총 배열 수 %d\n", sizeof(score)/ sizeof(int));//"\t 총 배열 수 %d\n"     // <- 작성

	// 문4) 반복문을 이용해서 score, result의 주소값을 출력하세요
	printf("문4=> score\n");
	for (int i = 0; i < sizeof(score) / sizeof(score[0]) /*sizeof를 이용해서 반복 수를 계산하세요*/; i++) {          // <- 작성
		for (int j = 0; j < sizeof(score[0]) / sizeof(score[0][0]) /*sizeof를 이용해서 반복 수를 계산하세요 */ ; j++) {         // <- 작성
			printf("\t      [%d] [%d] = %p", i, j, &score[i][j]);//// <- 작성
		}
		printf("\n");
		// <- 작성
	}
	printf(" result\n");
	// result 주소값 출력
	for (int i = 0; i < sizeof(result) / sizeof(result[0]) /*sizeof를 이용해서 반복 수를 계산하세요*/; i++) {          // <- 작성
		for (int j = 0; j < sizeof(result[0]) / sizeof(result[0][0]) /*sizeof를 이용해서 반복 수를 계산하세요 */; j++) {         // <- 작성
			printf("\t      [%d] [%d] = %p", i, j, &result[i][j]);//// <- 작성
		}
		printf("\n");
		// <- 작성
	}

	
	// 문5) do while을 이용하여 학생의 성적을 입력 받으세요.
	int i = 0;
	int j = 0;
	do
	{
		printf("enter number %d student's score (ex: 60 60 80) >>> ", i + 1);
		scanf_s("%d %d %d", &score[i][0], &score[i][1], &score[i][2]);
		// scanf_s는 문자나 문자열을 입력받을 때 버퍼 길이를 전달

		// 문6) 입력 후 내부 for문을 이용하여 70점보다 큰 점수라면 결과를 P로 변경하세요 
		for (j = 0;j < 3;j++) {
			if (score[i][j] > 70) {
				result[i][j] = 'P';
			}
		}
		i++;
	} while (i < 2);


	// 결과 출력
	// 이중 for문 사용
	// score값과 result 값 출력
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			printf("\t[%d] [%d] = %d, %c", i, j, score[i][j], result[i][j]);
		}
		printf("\n");
	}
}
