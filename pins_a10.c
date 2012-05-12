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

static const char *port_b[][6] = {
	{"TWI0_SCK"},				/* PB0 */
	{"TWI0_SDA"},				/* PB1 */
	{"PWM0"},				/* PB2 */
	{"IR0_TX",     NULL,	 "NC"},		/* PB3 */
	{"IR0_RX"},				/* PB4 */
	{"I2S_MCLK",  "AC97_MCLK"},		/* PB5 */
	{"I2S_BCLK",  "AC97_BCLK"},		/* PB6 */
	{"I2S_LRCK",  "AC97_SYNC"},		/* PB7 */
	{"I2S_DO0",   "AC97_DO"},		/* PB8 */
	{"I2S_DO1"},				/* PB9 */
	{"I2S_DO2"},				/* PB10 */
	{"I2S_DO3"},				/* PB11 */
	{"I2S_DI",    "AC97_DI", "NC"},		/* PB12 */
	{"SPI2_CS1",   NULL,	 "NC"},		/* PB13 */
	{"SPI2_CS0",  "JTAG_MS0"},		/* PB14 */
	{"SPI2_CLK",  "JTAG_CK0"},		/* PB15 */
	{"SPI2_MOSI", "JTAG_DO0"},		/* PB16 */
	{"SPI2_MISO", "JTAG_DI0"},		/* PB17 */
	{"TWI1_SCK"},				/* PB18 */
	{"TWI1_SDA"},				/* PB19 */
	{"TWI2_SCK"},				/* PB20 */
	{"TWI2_SDA"},				/* PB21 */
	{"UART0_TX", "IR1_TX"},			/* PB22 */
	{"UART0_RX", "IR1_RX"},			/* PB23 */
};

static const char *port_c[][6] = {
	{"NWE#", "SPI0_MOSI"},			/* PC0 */
	{"NALE", "SPI0_MISO"},			/* PC1 */
	{"NCLE", "SPI0_CLK"},			/* PC2 */
	{"NCE1"},				/* PC3 */
	{"NCE0"},				/* PC4 */
	{"NRE#"},				/* PC5 */
	{"NRB0", "SDC2_CMD"},			/* PC6 */
	{"NRB1", "SDC2_CLK"},			/* PC7 */
	{"NDQ0", "SDC2_D0"},			/* PC8 */
	{"NDQ1", "SDC2_D1"},			/* PC9 */
	{"NDQ2", "SDC2_D2"},			/* PC10 */
	{"NDQ3", "SDC2_D3"},			/* PC11 */
	{"NDQ4"},				/* PC12 */
	{"NDQ5"},				/* PC13 */
	{"NDQ6"},				/* PC14 */
	{"NDQ7"},				/* PC15 */
	{"NWP"},				/* PC16 */
	{"NCE2"},				/* PC17 */
	{"NCE3"},				/* PC18 */
	{"NCE4", "SPI2_CS0"},			/* PC19 */
	{"NCE5", "SPI2_CLK"},			/* PC20 */
	{"NCE6", "SPI2_MOSI"},			/* PC21 */
	{"NCE7", "SPI2_MISO"},			/* PC22 */
	{"SPI0_CS0"},				/* PC23 */
};

static const char *port_d[][6] = {
	{"LCD0_D0",  "LVDS0_VP0"},		/* PD0 */
	{"LCD0_D1",  "LVDS0_VN0"},		/* PD1 */
	{"LCD0_D2",  "LVDS0_VP1"},		/* PD2 */
	{"LCD0_D3",  "LVDS0_VN1"},		/* PD3 */
	{"LCD0_D4",  "LVDS0_VP2"},		/* PD4 */
	{"LCD0_D5",  "LVDS0_VN2"},		/* PD5 */
	{"LCD0_D6",  "LVDS0_VPC"},		/* PD6 */
	{"LCD0_D7",  "LVDS0_VNC"},		/* PD7 */
	{"LCD0_D8",  "LVDS0_VP3"},		/* PD8 */
	{"LCD0_D9",  "LVDS0_VN3"},		/* PD9 */
	{"LCD0_D10", "LVDS1_VP0"},		/* PD10 */
	{"LCD0_D11", "LVDS1_VN0"},		/* PD11 */
	{"LCD0_D12", "LVDS1_VP1"},		/* PD12 */
	{"LCD0_D13", "LVDS1_VN1"},		/* PD13 */
	{"LCD0_D14", "LVDS1_VP2"},		/* PD14 */
	{"LCD0_D15", "LVDS1_VN2"},		/* PD15 */
	{"LCD0_D16", "LVDS1_VPC"},		/* PD16 */
	{"LCD0_D17", "LVDS1_VNC"},		/* PD17 */
	{"LCD0_D18", "LVDS1_VP3"},		/* PD18 */
	{"LCD0_D19", "LVDS1_VN3"},		/* PD19 */
	{"LCD0_D20", "CSI1_MCLK"},		/* PD20 */
	{"LCD0_D21", "SMC_VPPEN"},		/* PD21 */
	{"LCD0_D22", "SMC_VPPPP"},		/* PD22 */
	{"LCD0_D23", "SMC_DET"},		/* PD23 */
	{"LCD0_CLK", "SMC_VCCEN"},		/* PD24 */
	{"LCD0_DE",  "SMC_RST"},		/* PD25 */
	{"LCD0_HSYNC", "SMC_SLK"},		/* PD26 */
	{"LCD0_VSYNC", "SMC_SDA"},		/* PD27 */
};

static const char *port_e[][6] = {
	{"TS0_CLK",	"CSI0_PCLK"},	/* PE0 */
	{"TS0_ERR",	"CSI0_MCLK"},	/* PE1 */
	{"TS0_SYNC",	"CSI0_HSYNC"},	/* PE2 */
	{"TS0_DVLD",	"CSI0_VSYNC"},	/* PE3 */
	{"TS0_D0",	"CSI0_D0"},	/* PE4 */
	{"TS0_D1",	"CSI0_D1"},	/* PE5 */
	{"TS0_D2",	"CSI0_D2"},	/* PE6 */
	{"TS0_D3",	"CSI0_D3"},	/* PE7 */
	{"TS0_D4",	"CSI0_D4"},	/* PE8 */
	{"TS0_D5",	"CSI0_D5"},	/* PE9 */
	{"TS0_D6",	"CSI0_D6"},	/* PE10 */
	{"TS0_D7",	"CSI0_D7"},	/* PE11 */
	{"TS0_CLK",	"CSI0_PCLK"},	/* PE12 */
	{"TS0_ERR",	"CSI0_MCLK"},	/* PE13 */
	{"TS0_SYNC",	"CSI0_HSYNC"},	/* PE14 */
	{"TS0_DVLD",	"CSI0_VSYNC"},	/* PE15 */
	{"TS0_D0",	"CSI0_D0"},	/* PE16 */
	{"TS0_D1",	"CSI0_D1"},	/* PE17 */
	{"TS0_D2",	"CSI0_D2"},	/* PE18 */
	{"TS0_D3",	"CSI0_D3"},	/* PE19 */
	{"TS0_D4",	"CSI0_D4"},	/* PE20 */
	{"TS0_D5",	"CSI0_D5"},	/* PE21 */
	{"TS0_D6",	"CSI0_D6"},	/* PE22 */
	{"TS0_D7",	"CSI0_D7"},	/* PE23 */
	{"TS0_CLK",	"CSI0_PCLK"},	/* PE24 */
	{"TS0_ERR",	"CSI0_MCLK"},	/* PE25 */
	{"TS0_SYNC",	"CSI0_HSYNC"},	/* PE26 */
	{"TS0_DVLD",	"CSI0_VSYNC"},	/* PE27 */
	{"TS0_D0",	"CSI0_D0"},	/* PE28 */
	{"TS0_D1",	"CSI0_D1"},	/* PE29 */
	{"TS0_D2",	"CSI0_D2"},	/* PE30 */
	{"TS0_D3",	"CSI0_D3"},	/* PE31 */
};

static const char *port_f[][6] = {
	{"SDC0_D1",  NULL, "JTAG_MS1"},	/* PF0 */
	{"SDC0_D0",  NULL, "JTAG_DI1"},	/* PF1 */
	{"SDC0_CLK", NULL, "UART0_TX"},	/* PF2 */
	{"SDC0_CMD", NULL, "JTAG_DO1"},	/* PF3 */
	{"SDC0_D3",  NULL, "UART0_RX"},	/* PF4 */
	{"SDC0_D2",  NULL, "JTAG_CK1"},	/* PF5 */
};

static struct ports a10_ports[] = {
	{ARRAY_SIZE(port_a), port_a},
	{ARRAY_SIZE(port_b), port_b},
	{ARRAY_SIZE(port_c), port_c},
	{ARRAY_SIZE(port_d), port_d},
	{ARRAY_SIZE(port_e), port_e},
	{ARRAY_SIZE(port_f), port_f},
};

void register_a10(void)
{
	register_pins("a10", a10_ports, ARRAY_SIZE(a10_ports));
}
