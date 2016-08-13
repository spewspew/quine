#include <stdio.h>
#include <stdlib.h>

extern char *prog;

int
main(void)
{
	char *c;

	printf("%s", prog);
	for(c = prog; *c != 0; c++) switch(*c) {
	default:
		putchar(*c);
		break;
	case '\\':
		printf("\\\\");
		break;
	case '\n':
		printf("\\n");
		break;
	case '\t':
		printf("\\t");
		break;
	case '"':
		printf("\\\"");
		break;
	}
	printf("\";\n");
	exit(0);
}

char *prog = "#include <stdio.h>\n#include <stdlib.h>\n\nextern char *prog;\n\nint\nmain(void)\n{\n\tchar *c;\n\n\tprintf(\"%s\", prog);\n\tfor(c = prog; *c != 0; c++) switch(*c) {\n\tdefault:\n\t\tputchar(*c);\n\t\tbreak;\n\tcase '\\\\':\n\t\tprintf(\"\\\\\\\\\");\n\t\tbreak;\n\tcase '\\n':\n\t\tprintf(\"\\\\n\");\n\t\tbreak;\n\tcase '\\t':\n\t\tprintf(\"\\\\t\");\n\t\tbreak;\n\tcase '\"':\n\t\tprintf(\"\\\\\\\"\");\n\t\tbreak;\n\t}\n\tprintf(\"\\\";\\n\");\n\texit(0);\n}\n\nchar *prog = \"";
