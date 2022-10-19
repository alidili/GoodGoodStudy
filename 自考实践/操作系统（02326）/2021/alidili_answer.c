#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#pragma comment(lib, "pthreadVC2.lib")

#define N 6

// 设置5种信号量，有5种不同类型的资源，每一种有1个,这样便于理解，因为每个哲学家需要的资源不同
sem_t chopsticks[N];

// 代表5个哲学家的编号
int philosophers[N] = { 0, 1, 2, 3, 4, 5 };

void delay(int len) {
	int i = rand() % len;
	int x;
	while (i > 0) {
		x = rand() % len;
		while (x > 0) {
			x--;
		}
		i--;
	}
}

void* philosopher(void* arg) {
	int i = *(int*)arg;
	// 左筷子的编号和哲学家的编号相同
	int left = i;
	// 右筷子的编号为哲学家编号+1
	int right = (i + 1) % N;
	while (1) {
		if (i % 2 == 0) {
			printf("哲学家%d正在思考问题\n", i);
			delay(60000);

			printf("哲学家%d饿了\n", i);
			// 此时这个哲学家左筷子的信号量-1之后>=0时，表示能继续执行。
			sem_wait(&chopsticks[right]); 
			printf("哲学家%d拿起了%d号筷子,现在只有一支筷子,不能进餐\n", i, right);
			sem_wait(&chopsticks[left]);
			printf("哲学家%d拿起了%d号筷子, 现在有两支筷子,开始进餐\n", i, left);
			delay(60000);
			sem_post(&chopsticks[left]);
			printf("哲学家%d放下了%d号筷子\n", i, left);
			sem_post(&chopsticks[right]);
			printf("哲学家%d放下了%d号筷子\n", i, right);
		}

		else {
			printf("哲学家%d正在思考问题\n", i);
			delay(60000);

			printf("哲学家%d饿了\n", i);
			// 此时这个哲学家左筷子的信号量-1之后>=0时，表示能继续执行。
			sem_wait(&chopsticks[left]);
			printf("哲学家%d拿起了%d号筷子,现在只有一支筷子,不能进餐\n", i, left);
			sem_wait(&chopsticks[right]);
			printf("哲学家%d拿起了%d号筷子, 现在有两支筷子,开始进餐\n", i, right);
			delay(60000);
			sem_post(&chopsticks[left]);
			printf("哲学家%d放下了%d号筷子\n", i, left);
			sem_post(&chopsticks[right]);
			printf("哲学家%d放下了%d号筷子\n", i, right);
		}
	}
}

int main(int argc, char** argv) {
	srand(time(NULL));
	pthread_t philo[N];

	// 信号量初始化
	for (int i = 0; i < N; i++) {
		sem_init(&chopsticks[i], 0, 1);
	}

	// 创建线程
	for (int i = 0; i < N; i++) {
		pthread_create(&philo[i], NULL, philosopher, &philosophers[i]);
	}

	// 挂起线程
	for (int i = 0; i < N; i++) {
		pthread_join(philo[i], NULL);
	}

	// 销毁信号量
	for (int i = 0; i < N; i++) {
		sem_destroy(&chopsticks[i]);
	}

	return 0;
}