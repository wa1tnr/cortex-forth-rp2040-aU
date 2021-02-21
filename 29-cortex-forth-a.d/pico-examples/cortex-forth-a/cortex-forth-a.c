// Mon Feb 15 18:55:13 UTC 2021
// wa1tnr
// cortex-forth for RP2040

/**
 * template is Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

/// \tag::hello_uart[]

#define UART_ID uart0
#define BAUD_RATE 115200

#define UART_TX_PIN 0
#define UART_RX_PIN 1
extern void interpreter(void);
// extern int _pico_LED(void);

// void interpreter(void) { }

extern void _OK(void);

int main() {
    sleep_ms(1800);
    uart_init(UART_ID, BAUD_RATE);

    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    stdio_init_all();

    // uart_putc_raw(UART_ID, 'A');

    sleep_ms(4800);
    // for (int i=3;i>0;i--) _pico_LED();
    // uart_puts(UART_ID, "\r\n\r\n   cortex-forth-rp2040-aU r0.1.0-pre-alpha\r\n\r\n");
    //      0.1.0-pre-alpha  checked carefully - available and appropriate
    _OK(); // Cortex-Forth.c
    uart_puts(UART_ID, "\r\n\r\n   cortex-forth-rp2040-a r0.1.0-pre-alpha\r\n\r\n");
    putchar(' ');
    putchar(' ');
    putchar('C');
    putchar('o');
    putchar('r');
    putchar('t');
    putchar('e');
    putchar('x');
    putchar(' ');
    putchar(' ');
    putchar('F');
    putchar('o');
    putchar('r');
    putchar('t');
    putchar('h');
    putchar(' ');
    putchar('\r');
    putchar('\n');
    // printf("%s" "printf here\r\n\r\n   cortex-forth-rp2040-a r0.1.0-pre-alpha\r\n\r\n");

    while(1) {
        // _pico_LED(); // test using GPIO hardware to blink Pi Pico onboard LED
        interpreter(); // camelforth
    }
}

/// \end::hello_uart[]
