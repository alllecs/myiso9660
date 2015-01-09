#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_SIZE 1024

int dump_buffer(void *buf, int buf_size)
{
        int i;

        for (i = 0; i < buf_size; ++i)
                printf("%c", ((char *) buf) [i]);

        return 0;
}


int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[MAX_SIZE];
	unsigned long fileLen;

	if (argc < 2) {
		printf("Error. No find file.\n");
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

	if (buf[MAX_SIZE] == (char)malloc(MAX_SIZE *fileLen))
	printf("%c", buf[MAX_SIZE]);

	if (buf == NULL) {
		printf("Memory allocation error!");
		fclose(fp);
		return 4;
	}

	fread(buf, fileLen, 1, fp);

	printf("value is %s\n", buf);
	dump_buffer(&buf, fileLen);

        fclose(fp);
        return 0;
}

//	free(buf);

/*
	while (!feof(fp)) {
		char n, k;

		n = fscanf(fp, "%c", &k);
		printf("%c %c\n", n, k);
		n++;
	}

	printf("\n");
	fclose(fp);
	return 0;
}
*/

