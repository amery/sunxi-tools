/*
 * Copyright (C) 2012  Alejandro Mery <amery@geeks.cl>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "pins.h"

#include <stdio.h>

static void print_pins(const char *soc, char port,
		       const char *multi[][6], size_t len)
{
	unsigned j, k;

	for (j=0; j<len; j++) {
		errf("%s: P%c%d\n", soc, port, j);
		for (k=0; k<6; k++) if (multi[j][k]) {
			errf("%s: P%c%d<%u> %s\n", soc, port,
			     j, k+2, multi[j][k]);
		}
	}
}

void register_pins(const char *soc, struct ports *ports, size_t len)
{
	struct ports *p = ports;

	for (unsigned i=0; i<len; i++, p++)
		print_pins(soc, 'A'+i, p->multi, p->len);
}

int main(int UNUSED(argc), char *UNUSED(argv[]))
{
	return 0;
}
