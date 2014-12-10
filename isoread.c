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
	CdioList_t *entlist;
	iso9660_t *p_iso;

	if (argc < 2) {
		printf("Ошибка. Не указан файл.\n");
		return 2;
	}

	p_iso = iso9660_open(argv[1]);

	if (p_iso == NULL) {
		perror("Ошибка при работе с файлом\n");
		iso9660_close(p_iso);
		return 3;
	}

	p_outfd = fopen(argv[1], "r");
	if (p_outfd == NULL) {
		perror("fopen()");
		iso9660_close(p_iso);
		return 4;
	}

	entlist = iso9660_ifs_readdir(p_iso, "/");

	if (entlist) {
		char filename[4096];
		iso9660_stat_t *p_statbuf = (iso9660_stat_t *) _cdio_list_node_data;
		iso9660_name_translate(p_statbuf->filename, filename);
		printf ("-- /%s\n", filename);
	}
	return 0;
	iso9660_close(p_iso);
}
