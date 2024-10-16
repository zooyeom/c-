//배열에서의 중요점 3가지
//1.배열은 "연속적인" 메모리상에서 만들어진다
//2.배열의 첫번째 방 번호는 0으로 시작한다
//3.배열은 for문과 같이 사용한다


/*[예시] 3개의 정수를 입력받고 출력
#include <stdio.h>
int main() {
	int array[3];
	for (int i = 0; i < 3; i++) scanf("%d", &array[i]);
	for (int i = 0; i < 3; i++) printf("%d", array[i]);
}*/

/*[배열활용1] 10명의 성적을 입력받아 평균과 최고점, 최저점을 출력
#include <stdio.h>
int main(){
	int array[10];
	int max;
	int low;
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &array[i]);
	}
	max = array[0];
	low = array[0];
	for (int i = 0; i < 10; i++) {
		if (max < array[i]) max = array[i];
		if (low > array[i]) low = array[i];
		sum += array[i];
	}
	printf("최고점: %d 최저점: %d 평균: %.2f", max, low, (float)sum / 10);
}*/

/*[배열활용2] 10개의 숫자를 입력받아 큰 순서대로 나열
#include <stdio.h>
int main() {
	int array[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &array[i]);
	}
}*/

//[배열활용3] 10진수를 입력받아 2진수로 출력하시오
#include <stdio.h>
int main() {
	int number;
	scanf("%d", &number);
	for(int i=0;i<)
}

//[배열활용4] 로또번호를 추천하는 프로그램
