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

	if (argc < 2) {
		printf("Ошибка. Не указан файл.\n");
		return 3;
	}


