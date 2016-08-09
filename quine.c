#include <stdio.h>
#include <stdlib.h>

char *prog = "#include <stdio.h>\n"
	"#include <stdlib.h>\n"
	"\n"
	"char *prog = \"@\n"
	"void\n"
	"printq(void)\n"
	"{\n"
	"\tchar *c;\n"
	"\n"
	"\tfor(c = prog; *c != '\\0'; c++) switch(*c) {\n"
	"\tdefault:\n"
	"\t\tputchar(*c);\n"
	"\t\tbreak;\n"
	"\tcase '\\n':\n"
	"\t\tif(c[1] == '\\0')\n"
	"\t\t\tprintf(\"\\\\n\\\";\\n\");\n"
	"\t\telse\n"
	"\t\t\tprintf(\"\\\\n\\\"\\n\\t\\\"\");\n"
	"\t\tbreak;\n"
	"\tcase '\\t':\n"
	"\t\tprintf(\"\\\\t\");\n"
	"\t\tbreak;\n"
	"\tcase '\\\\':\n"
	"\t\tprintf(\"\\\\\\\\\");\n"
	"\t\tbreak;\n"
	"\tcase '\\\"':\n"
	"\t\tprintf(\"\\\\\\\"\");\n"
	"\t\tbreak;\n"
	"\t}\n"
	"}\n"
	"\n"
	"int\n"
	"main(int argc, char **argv)\n"
	"{\n"
	"\tint once;\n"
	"\tchar *c;\n"
	"\n"
	"\tonce = 0;\n"
	"\tfor(c = prog; *c != '\\0'; c++) switch(*c) {\n"
	"\tdefault:\n"
	"\t\tputchar(*c);\n"
	"\t\tbreak;\n"
	"\tcase '@':\n"
	"\t\tif(once) {\n"
	"\t\t\tputchar('@');\n"
	"\t\t\tbreak;\n"
	"\t\t}\n"
	"\t\tprintq();\n"
	"\t\tonce++;\n"
	"\t\tbreak;\n"
	"\t}\n"
	"\texit(0);\n"
	"}\n";

void
printq(void)
{
	char *c;

	for(c = prog; *c != '\0'; c++) switch(*c) {
	default:
		putchar(*c);
		break;
	case '\n':
		if(c[1] == '\0')
			printf("\\n\";\n");
		else
			printf("\\n\"\n\t\"");
		break;
	case '\t':
		printf("\\t");
		break;
	case '\\':
		printf("\\\\");
		break;
	case '\"':
		printf("\\\"");
		break;
	}
}

int
main(int argc, char **argv)
{
	int once;
	char *c;

	once = 0;
	for(c = prog; *c != '\0'; c++) switch(*c) {
	default:
		putchar(*c);
		break;
	case '@':
		if(once) {
			putchar('@');
			break;
		}
		printq();
		once++;
		break;
	}
	exit(0);
}
