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

static const char *port_a[][6] = {
	{"ERXD3",  "SPI1_CS0",	"UART2_RTS"},	/* PA0 */
	{"ERXD2",  "SPI1_CLK",	"UART2_CTS"},	/* PA1 */
	{"ERXD1",  "SPI1_MOSI",	"UART2_TX"},	/* PA2 */
	{"ERXD0",  "SPI1_MOSO",	"UART2_RX"},	/* PA3 */
	{"ETXD3",  "SPI1_CS1"},			/* PA4 */
	{"ETXD2",  "SPI3_CS0"},			/* PA5 */
	{"ETXD1",  "SPI3_CLK"},			/* PA6 */
	{"ETXD0",  "SPI3_MOSI"},		/* PA7 */
	{"ERXCK",  "SPI3_MOSO"},		/* PA8 */
	{"ERXERR", "SPI3_CS1"},			/* PA9 */
	{"ERXDV",   NULL,	"UART1_TX"},	/* PA10 */
	{"ERXDV",   NULL,	"UART1_RX"},	/* PA11 */
	{"EMDIO",  "UART6_TX",	"UART1_RTS"},	/* PA12 */
	{"ETXEN",  "UART6_RX",	"UART1_CTS"},	/* PA13 */
	{"ETXCK",  "UART7_TX",	"UART1_DTR"},	/* PA14 */
	{"ECRS",   "UART7_RX",	"UART1_DSR"},	/* PA15 */
	{"ECOL",   "CAN_TX",	"UART1_DCD"},	/* PA16 */
	{"ETXERR", "CAN_RX",	"UART1_RING"},	/* PA17 */
};

static struct ports a10_ports[] = {
	{ARRAY_SIZE(port_a), port_a},
};

void register_a10(void)
{
	register_pins("a10", a10_ports, ARRAY_SIZE(a10_ports));
}
