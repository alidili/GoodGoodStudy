#include <stdio.h>

int main() {
	printf("��������Ŀ��ţ�");
	char code[13];
	scanf_s("%s", &code, 13);
	printf("\n4*3����\n");
	for (int i = 0; i < 13; i++) {
		printf("%c%s", code[i]," ");
		if (i % 3 == 2) {
			printf("\n");
		}
	}
	printf("\n3*4����\n");
	for (int i = 0; i < 13; i++) {
		printf("%c%s", code[i], " ");
		if (i % 4 == 3) {
			printf("\n");
		}
	}
	return 0;
}