#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#include <cdio/cdio.h>
#include <cdio/iso9660.h>

int main(int argc, char *argv[])
{
	iso9660_t *p_iso;

	if (argc != 2) {
		printf("Отсутствует или указано больше 1 агрумента\n");
		return 3;
	}

	p_iso = iso9660_open(argv[1]);

	if (p_iso == NULL) {
		perror("Ошибка при работе с фалом\n");
		return 1;
	} else
		return 0;

	iso9660_close(p_iso);
}
