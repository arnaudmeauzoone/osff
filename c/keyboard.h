#ifndef keyboard_h
#define keyboard_h

void outb(uint16_t port, uint8_t val);

uint8_t inb(uint16_t port);

uint8_t getScancode();

#endif