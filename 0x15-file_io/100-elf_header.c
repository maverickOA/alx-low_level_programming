#include "main.h"

/**
 * main - Print the header for an ELF file.
 *
 * @argc: The number of arguments given.
 * @argv: The arguments given.
 *
 * Return: 0 success exit code
 *
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *elf_header64;
	int file_descriptor, bytes_read;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf-file\n", argv[0]);
		exit(98);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		_close(file_descriptor);
		exit(98);
	}
	elf_header64 = malloc(sizeof(Elf64_Ehdr));
	if (elf_header64 == NULL)
	{
		_close(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	bytes_read = read(file_descriptor, elf_header64, sizeof(Elf64_Ehdr));
	if (bytes_read == -1)
	{
		free(elf_header64);
		dprintf(STDERR_FILENO, "Error: `%s` No such file\n", argv[1]);
		_close(file_descriptor);
		exit(98);
	}
	execute(*elf_header64);
	free(elf_header64);
	_close(file_descriptor);
	return (0);
}

/**
 * execute - Call the functions to display
 * details for the elf file.
 *
 * @elf_header64: The elf header file
 *
 */
void execute(Elf64_Ehdr elf_header64)
{
	start_read(elf_header64.e_ident);
	print_magicnumber(elf_header64.e_ident);
	print_class(elf_header64.e_ident);
	print_data(elf_header64.e_ident);
	print_version(elf_header64.e_ident);
	print_os(elf_header64.e_ident);
	print_abiversion(elf_header64.e_ident);
	print_type(elf_header64.e_type, elf_header64.e_ident);
	print_record(elf_header64.e_entry, elf_header64.e_ident);
}

/**
 * _close - Close a file
 *
 * @file_descriptor: The file descriptor
 *
 */
void _close(int file_descriptor)
{
	if (close(file_descriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
		exit(98);
	}
}

/**
 * start_read - Attempt to read from an ELF file.
 *
 * @e_ident: The elf header file details
 *
 */
void start_read(unsigned char *e_ident)
{
	int e_identpos = 0;

	while (e_identpos < 4)
	{
		if (e_ident[e_identpos] != 127 &&
			e_ident[e_identpos] != 'E' &&
			e_ident[e_identpos] != 'L' &&
			e_ident[e_identpos] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
		e_identpos++;
	}
	printf("ELF Header:\n");
}

/**
 * print_magicnumber - Display the magic numbers for
 * an elf file.
 *
 * @e_ident: The elf header file details
 *
 */
void print_magicnumber(unsigned char *e_ident)
{
	int einident_index = 0;

	printf("  Magic:   ");
	while (einident_index < EI_NIDENT)
	{
		printf("%02x", e_ident[einident_index]);
		if (einident_index < (EI_NIDENT - 1))
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
		einident_index++;
	}
}

/**
 * print_class - Display the architecture for
 * the elf file.
 *
 * @e_ident: The elf header file details
 *
 */
void print_class(unsigned char *e_ident)
{
	int class = e_ident[EI_CLASS];

	printf("  Class:                             ");
	switch (class)
	{
		case ELFCLASSNONE:
			printf("none");
			break;
		case ELFCLASS32:
			printf("ELF32");
			break;
		case ELFCLASS64:
			printf("ELF64");
			break;
		default:
			printf("<unknown %x>", class);
			break;
	}
	printf("\n");
}

/**
 * print_data - Display the data for the elf file.
 *
 * @e_ident: The elf header file details
 *
 */
void print_data(unsigned char *e_ident)
{
	int data = e_ident[EI_DATA];

	printf("  Data:                              ");
	switch (data)
	{
		case ELFDATANONE:
			printf("none");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian");
			break;
		default:
			printf("<unknown %x>", data);
			break;
	}
	printf("\n");
}

/**
 * print_version - Display the version for the elf file.
 *
 * @e_ident: The elf header file details
 *
 */
void print_version(unsigned char *e_ident)
{
	int version = e_ident[EI_VERSION];

	printf("  Version:                           %d", version);
	switch (version)
	{
		case EV_CURRENT:
			printf(" (current)");
			break;
	}
	printf("\n");
}

/**
 * print_os - Display the OS the elf file targets.
 *
 * @e_ident: The elf header file details
 *
 */
void print_os(unsigned char *e_ident)
{
	int os_abi = e_ident[EI_OSABI];

	printf("  OS/ABI:                            ");
	switch (os_abi)
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App");
			break;
		default:
			printf("<unknown %x>", os_abi);
			break;
	}
	printf("\n");
}

/**
 * print_abiversion - Display the ABI version for the elf
 * header file.
 *
 * @e_ident: The elf header file details
 *
 */
void print_abiversion(unsigned char *e_ident)
{
	int abi_version = e_ident[EI_ABIVERSION];

	printf("  ABI Version:                       %d\n", abi_version);
}

/**
 * print_type - Identify the object file type.
 *
 * @e_type: The object file type.
 * @e_ident: The elf header file details.
 *
 */
void print_type(uint16_t e_type, unsigned char *e_ident)
{
	int data = e_ident[EI_DATA];

	if (data == ELFDATA2MSB)
	{
		e_type >>= 8;
	}
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown %x>", e_type);
			break;
	}
	printf("\n");
}

/**
 * print_record - Display the memory entry address to the
 * elf file.
 *
 * @e_entry: The memory address to the elf entry point.
 * @e_ident: The elf header file details.
 *
 */
void print_record(unsigned long int e_entry, unsigned char *e_ident)
{
	int class = e_ident[EI_CLASS];

	printf("  Entry point address:               ");
	if (class == ELFCLASS32)
	{
		printf("%#x", (unsigned int)e_entry);
	}
	else
	{
		printf("%#lx", e_entry);
	}
	printf("\n");
}
