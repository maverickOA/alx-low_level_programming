#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <elf.h>

int _putchar(char c);
int _strlen(char *str);

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

void from_error(char *str);
void to_error(char *str);
void close_error(int file_descriptor);

void start_read(unsigned char *e_ident);
void print_magicnumber(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_os(unsigned char *e_ident);
void print_abiversion(unsigned char *e_ident);
void print_type(uint16_t e_type, unsigned char *e_ident);
void print_record(unsigned long int e_entry, unsigned char *i_ident);
void execute(Elf64_Ehdr elf_header64);
void _close(int file_descriptor);

#endif
