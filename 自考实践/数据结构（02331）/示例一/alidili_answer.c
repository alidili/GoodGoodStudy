#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct intarray {
	int value;
	struct intarray* next;
} intarray;

intarray* input(intarray* array);
void print(intarray* array);
intarray* insertSort(intarray* head);
intarray* selectSort(intarray* head);
intarray* bubbleSort(intarray* head);
void search(intarray* array);

int main() {
	printf("请输入一组正整数：\n");
	intarray* arr, * sortArr;
	arr = malloc(sizeof(intarray));
	assert(arr);
	arr->next = NULL;
	arr = input(arr);
	printf("\n输入的正整数为：");
	print(arr);

	sortArr = selectSort(arr);
	printf("\n排序后的正整数为：");
	print(sortArr);

	search(sortArr);
	return 0;
}

intarray* input(intarray* array) {
	int i = 1;
	int input;
	intarray* p, * q;
	do {
		printf("请输入第%d位整数：", i);
		scanf_s("%d", &input);
		if (input == -1) {
			break;
		}
		p = malloc(sizeof(intarray));
		q = array;
		assert(p);
		p->value = input;
		p->next = q->next;
		q->next = p;
		i++;
	} while (input != -1);
	return array;
}

void print(intarray* array) {
	intarray* p = array->next;
	while (p != NULL)
	{
		printf("%d  ", p->value);
		p = p->next;
	}
}

intarray* insertSort(intarray* head) {
	if (head == NULL) {
		return head;
	}
	intarray* dummyHead = malloc(sizeof(intarray));
	dummyHead->value = 0;
	dummyHead->next = head;
	intarray* lastSorted = head;
	intarray* curr = head->next;
	while (curr != NULL) {
		if (lastSorted->value <= curr->value) {
			lastSorted = lastSorted->next;
		}
		else {
			intarray* prev = dummyHead;
			while (prev->next->value <= curr->value) {
				prev = prev->next;
			}
			lastSorted->next = curr->next;
			curr->next = prev->next;
			prev->next = curr;
		}
		curr = lastSorted->next;
	}
	return head;
}

intarray* selectSort(intarray* head) {
	intarray* p, * q, * small;
	int temp;

	for (p = head->next; p->next != NULL; p = p->next) {
		small = p;
		for (q = p->next; q; q = q->next)
		{
			if (q->value < small->value)
				small = q;
		}
		if (small != p)
		{
			temp = p->value;
			p->value = small->value;
			small->value = temp;
		}
	}
	return head;
}

intarray* bubbleSort(intarray* head) {
	struct intarray* p, * q;
	int flag;

	p = head;
	q = head->next;
	flag = 1;

	while (q != NULL && flag == 1) {
		flag = 0;
		while (q != NULL) {
			if (p->value > q->value) {
				int temp = p->value;
				p->value = q->value;
				q->value = temp;
				flag = 1;
			}
			p = q;
			q = q->next;
		}
		p = head;
		q = head->next;
	}
	return head;
}

void search(intarray* array) {
	printf("\n请输入一个位整数：");
	int k;
	scanf_s("%d", &k);
	intarray* p = array->next;
	int i = 0;
	while (p != NULL)
	{
		if (p->value == k) {
			printf("查找成功，位置：%d", i);
			return;
		}
		p = p->next;
		i++;
	}
	printf("查找失败：-1");
}