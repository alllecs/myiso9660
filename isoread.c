#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2) {
		printf("Ошибка. Не указан файл.\n");
		return 2;
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("fopen()");
		return 3;
	}

	while (!feof(fp)) {
		char n, k;

		n = fscanf(fp, "%d", &k);
		if (n == EOF) {
			printf("EOF\n");
		}
		if (k != 32768)
		printf("%c\n", k);
	}

	return 0;
	fclose(fp);
}
