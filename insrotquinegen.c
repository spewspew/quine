#include <stdio.h>
#include <stdlib.h>

char *prog = "#include <stdio.h>\n"
	"#include <stdlib.h>\n"
	"\n"
	"char prog[] = {@};\n"
	"\n"
	"int\n"
	"main(int argc, char **argv)\n"
	"{\n"
	"\tint once;\n"
	"\tunsigned char *c, *d;\n"
	"\n"
	"\tonce = 0;\n"
	"\tfor(c = (unsigned char *)prog; *c != '\\0'; c++) switch(*c - 128) {\n"
	"\tdefault:\n"
	"\t\tputchar(*c - 128);\n"
	"\t\tbreak;\n"
	"\tcase '@':\n"
	"\t\tif(once) {\n"
	"\t\t\tputchar('@');\n"
	"\t\t\tbreak;\n"
	"\t\t}\n"
	"\t\tfor(d = (unsigned char *)prog; *d != '\\0'; d++)\n"
	"\t\t\tprintf(\" %d,\", *d);\n"
	"\t\tprintf(\" 0 \");\n"
	"\t\tonce++;\n"
	"\t\tbreak;\n"
	"\t}\n"
	"\texit(0);\n"
	"}\n";

int
main(int argc, char **argv)
{
	int once;
	unsigned char *c, *d;

	once = 0;
	for(c = (unsigned char *)prog; *c != '\0'; c++) switch(*c) {
	default:
		putchar(*c);
		break;
	case '@':
		if(once) {
			putchar('@');
			break;
		}
		for(d = (unsigned char *)prog; *d != '\0'; d++)
			printf(" %d,", *d + 128);
		printf(" 0 ");
		once++;
		break;
	}
	exit(0);
}
