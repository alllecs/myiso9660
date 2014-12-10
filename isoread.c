#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#include <cdio/cdio.h>
#include <cdio/iso9660.h>

int main(int argc, char *argv[])
{
	FILE *p_outfd;
	iso9660_t *p_iso;

	if (argc < 2) {
		printf("Ошибка. Не указан файл.\n");
		return 2;
	}

	p_iso = iso9660_open(argv[1]);

	if (p_iso == NULL) {
		perror("Ошибка при работе с фалом\n");
		iso9660_close(p_iso);
		return 3;
	}

	if (!(p_outfd = fopen(argv[1], "wb"))) {
		perror("fopen()");
		iso9660_close(p_iso);
		return 4;
	}

}
