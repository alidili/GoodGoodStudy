#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct student {
	int score;
	struct student* next;
} student;

student* input(student* stu);
void output(student* s);
void pass_score(student* s);

int main() {
	printf("������һ��5��ѧ���ɼ����ɼ�>0���ɼ�<=100��\n");
	student* sortStu, * stu;
	stu = malloc(sizeof(student));
	assert(stu);
	stu->next = NULL;
	sortStu = input(stu);

	// �������
	printf("\nѧ���ɼ��Ӹߵ��������Ľ��Ϊ��");
	output(sortStu);

	// ͳ�Ʋ����������
	pass_score(sortStu);
	return 0;
}

student* input(student* stu) {
	int score;
	student* p, * q;
	for (int i = 0; i < 5; i++) {
		printf("�������%dλѧ������:", i + 1);
		scanf_s("%d", &score);
		q = stu;
		p = malloc(sizeof(student));
		assert(p);
		p->score = score;
		while (q->next != NULL) {
			if (q->next->score < p->score) {
				break;
			}
			q = q->next;
		}
		p->next = q->next;
		q->next = p;
	}
	return stu;
}

void output(student* s) {
	student* p = s->next;
	while (p != NULL) {
		printf("%d   ", p->score);
		p = p->next;
	}
}

void pass_score(student* s) {
	student* p = s->next;
	int sum = 0;
	while (p != NULL) {
		if (p->score < 60) {
			sum += 1;
		}
		p = p->next;
	}
	printf("\nͳ�Ʋ�����<60���ɼ��ĸ��� = %d\n", sum);
}