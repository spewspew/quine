#include <stdio.h>
#include <stdlib.h>

extern char prog[];

int
main(void)
{
	unsigned char *c;

	printf("%s", prog);
	for(c = (unsigned char *)prog; *c != 0; c++)
		printf(" %d,", *c + 128);
	printf(" 0 };\n");
	exit(0);
}

char prog[] = "#include <stdio.h>\n#include <stdlib.h>\n\nextern char prog[];\n\nint\nmain(void)\n{\n\tunsigned char *c;\n\n\tfor(c = (unsigned char *)prog; *c != 0; c++)\n\t\t*c -= 128;\n\tprintf(\"%s\", prog);\n\tfor(c = (unsigned char *)prog; *c != 0; c++)\n\t\tprintf(\" %d,\", *c + 128);\n\tprintf(\" 0 };\\n\");\n\texit(0);\n}\n\nchar prog[] = {";
