/*
  Copyright (C) 2004, 2005, 2006, 2007, 2008, 2011
   Rocky Bernstein <rocky@gnu.org>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* Simple program to show using libiso9660 to list files in a directory of
   an ISO-9660 image and give some iso9660 information. See the code
   to iso-info for a more complete example.

   If a single argument is given, it is used as the ISO 9660 image to
   use in the listing. Otherwise a compiled-in default ISO 9660 image
   name (that comes with the libcdio distribution) will be used.
 */

/* Set up a CD-DA image to test on which is in the libcdio distribution. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#include <cdio/cdio.h>
#include <cdio/iso9660.h>

int main(int argc, const char *argv[])
{
	char const *psz_fname;
	iso9660_t *p_iso;

	if (argc > 1)
		psz_fname = argv[1];
	else
		psz_fname = ISO9660_IMAGE;

	p_iso = iso9660_open (psz_fname);

	if (NULL == p_iso) {
		printf("Sorry, couldn't open %s as an ISO-9660 image\n", psz_fname);
		return 1;
	}

	iso9660_close(p_iso);
	return 0;
}

