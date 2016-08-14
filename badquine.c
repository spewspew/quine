#include <stdio.h>
#include <stdlib.h>

char *prog = "int\nmain(void)\n{\n\tchar *c;\n\n\tprintf(\"#include <stdio.h>\\n#include <stdlib.h>\\n\\nchar *prog = \\\"\");\n\tfor(c = prog; *c != 0; c++) switch(*c) {\n\tdefault:\n\t\tputchar(*c);\n\t\tbreak;\n\tcase '\\\\':\n\t\tprintf(\"\\\\\\\\\");\n\t\tbreak;\n\tcase '\\n':\n\t\tprintf(\"\\\\n\");\n\t\tbreak;\n\tcase '\\t':\n\t\tprintf(\"\\\\t\");\n\t\tbreak;\n\tcase '\"':\n\t\tprintf(\"\\\\\\\"\");\n\t\tbreak;\n\t}\n\tprintf(\"\\\";\\n\\n%s\", prog);\n\texit(0);\n}\n";

int
main(void)
{
	char *c;

	printf("#include <stdio.h>\n#include <stdlib.h>\n\nchar *prog = \"");
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
	printf("\";\n\n%s", prog);
	exit(0);
}
