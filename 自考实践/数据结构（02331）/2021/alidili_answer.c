#include <stdio.h>

int main() {
	printf("ÇëÊäÈëÄãµÄ¿¼ºÅ£º");
	char code[13];
	scanf_s("%s", &code, 13);
	printf("\n4*3¾ØÕó£º\n");
	for (int i = 0; i < 13; i++) {
		printf("%c%s", code[i]," ");
		if (i % 3 == 2) {
			printf("\n");
		}
	}
	printf("\n3*4¾ØÕó£º\n");
	for (int i = 0; i < 13; i++) {
		printf("%c%s", code[i], " ");
		if (i % 4 == 3) {
			printf("\n");
		}
	}
	return 0;
}