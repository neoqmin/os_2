#include <pthread.h>
#include <stdio.h>

int sum;					// 스레드에서 파라메터로 받은 값을 더해서 반환하는 전역변수
void *runner(void *param);

int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;
	
	printf("Entering %s\n", __FUNCTION__);

	if (argc != 2)			// 파라메터의 존재 유/무 확인
	{
		return -1;
	}
	if (atoi(argv[1]) < 0)	// 음수인지 양수인지 판단, 음수면 실패
	{
		return -1;
	}
	pthread_attr_init(&attr);	// thread 속성 초기화

	pthread_create(&tid, &attr, runner, argv[1]);	// 전달 받은 파라메터로 스레드 생성(runner)

	pthread_join(tid, NULL);						// 스레드 종료대기

	printf("sum = %d\n",  sum);						// 합 출력
	
	printf("Leavign %s\n", __FUNCTION__);

}

void *runner(void *param)
{
	int i, upper = atoi(param);						// atoi(문자를 숫자로 변환)
	sum = 0;

	printf("Entering %s\n", __FUNCTION__);

	for (i = 1;i <= upper;i++)						// 1부터 주어진 숫자까지 더함
	{
		sum+=i;
	}
	
	printf("Leaving %s\n", __FUNCTION__);
	
	pthread_exit(0);
}
