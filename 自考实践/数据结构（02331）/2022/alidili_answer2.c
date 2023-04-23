#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct word {
	char ch;
	struct word* next;
} word;

word* sort(word* w);
void printSortWord(word* w);
void printCharCount(word* w, char c);

int main() {
	printf("����������ַ�\n");
	word* wo, * sortWord;
	wo = malloc(sizeof(word));
	assert(wo);
	wo->next = NULL;
	sortWord = sort(wo);
	printSortWord(sortWord);
	printCharCount(sortWord, 'l');
	return 0;
}

word* sort(word* w) {
	char ch;
	word* p, * q;
	for (int i = 0; i < 5; i++) {
		printf("�������%dλ�ַ���", i + 1);
		scanf_s(" %c", &ch, 1);
		p = malloc(sizeof(word));
		assert(p);
		p->ch = ch;
		q = w;
		while (q->next != NULL) {
			if (q->next->ch < p->ch) {
				break;
			}
			q = q->next;
		}
		p->next = q->next;
		q->next = p;
	}
	return w;
}

void printSortWord(word* w) {
	printf("\n���ַ�����Ӹߵ��͵Ĵ�������:");
	word* p = w->next;
	while (p != NULL) {
		printf("%c  ", p->ch);
		p = p->next;
	}
}

void printCharCount(word* w, char c) {
	printf("\n%c �ַ��ڸ����ַ��г��ֵĴ���Ϊ��", c);
	int count = 0;
	word* p = w->next;
	while (p != NULL) {
		if (p->ch == c) {
			count++;
		}
		p = p->next;
	}
	printf("%d", count);
}