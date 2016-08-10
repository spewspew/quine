#include <stdio.h>
#include <stdlib.h>

extern char prog[];

int
main(void)
{
	unsigned char *c;

	printf("%s\n", prog);
	printf("char prog[] = {");
	for(c = (unsigned char *)prog; *c != 0; c++)
		printf(" %d,", *c + 128);
	printf("};\n");
	exit(0);
}

char prog[] = "#include <stdio.h>\n#include <stdlib.h>\n\nextern char prog[];\n\nint\nmain(void)\n{\n\tunsigned char *c;\n\n\tfor(c = (unsigned char *)prog; *c != 0; c++)\n\t\t*c += 128;\n\tprintf(\"%s\\n\", prog);\n\tprintf(\"char prog[] = {\");\n\tfor(c = (unsigned char *)prog; *c != 0; c++)\n\t\tprintf(\" %d,\", *c + 128);\n\tprintf(\"};\\n\");\n\texit(0);\n}\n";
