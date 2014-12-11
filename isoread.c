#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char *buf;
	unsigned long fileLen;

	if (argc < 2) {
		printf("Ошибка. Не указан файл.\n");
		return 2;
	}

	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		perror("fopen()");
		return 3;
	}

	fseek(fp, 0, SEEK_END);
	fileLen = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	buf = (char *) malloc(fileLen + 1);
	if (buf == NULL) {
		fprintf(stderr, "Memory error!");
			fclose(fp);
		return 4;
	}

	fread(buf, fileLen, 1, fp);
	fclose(fp);

	free(buf);
	return 0;
}

/*	while (!feof(fp)) {
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
*/

