#include <stdio.h>
#include <stdlib.h>

char prog[] = { 163, 233, 238, 227, 236, 245, 228, 229, 160, 188, 243, 244, 228, 233, 239, 174, 232, 190, 138, 163, 233, 238, 227, 236, 245, 228, 229, 160, 188, 243, 244, 228, 236, 233, 226, 174, 232, 190, 138, 138, 227, 232, 225, 242, 160, 240, 242, 239, 231, 219, 221, 160, 189, 160, 251, 192, 253, 187, 138, 138, 233, 238, 244, 138, 237, 225, 233, 238, 168, 233, 238, 244, 160, 225, 242, 231, 227, 172, 160, 227, 232, 225, 242, 160, 170, 170, 225, 242, 231, 246, 169, 138, 251, 138, 137, 233, 238, 244, 160, 239, 238, 227, 229, 187, 138, 137, 245, 238, 243, 233, 231, 238, 229, 228, 160, 227, 232, 225, 242, 160, 170, 227, 172, 160, 170, 228, 187, 138, 138, 137, 239, 238, 227, 229, 160, 189, 160, 176, 187, 138, 137, 230, 239, 242, 168, 227, 160, 189, 160, 168, 245, 238, 243, 233, 231, 238, 229, 228, 160, 227, 232, 225, 242, 160, 170, 169, 240, 242, 239, 231, 187, 160, 170, 227, 160, 161, 189, 160, 167, 220, 176, 167, 187, 160, 227, 171, 171, 169, 160, 243, 247, 233, 244, 227, 232, 168, 170, 227, 160, 173, 160, 177, 178, 184, 169, 160, 251, 138, 137, 228, 229, 230, 225, 245, 236, 244, 186, 138, 137, 137, 240, 245, 244, 227, 232, 225, 242, 168, 170, 227, 160, 173, 160, 177, 178, 184, 169, 187, 138, 137, 137, 226, 242, 229, 225, 235, 187, 138, 137, 227, 225, 243, 229, 160, 167, 192, 167, 186, 138, 137, 137, 233, 230, 168, 239, 238, 227, 229, 169, 160, 251, 138, 137, 137, 137, 240, 245, 244, 227, 232, 225, 242, 168, 167, 192, 167, 169, 187, 138, 137, 137, 137, 226, 242, 229, 225, 235, 187, 138, 137, 137, 253, 138, 137, 137, 230, 239, 242, 168, 228, 160, 189, 160, 168, 245, 238, 243, 233, 231, 238, 229, 228, 160, 227, 232, 225, 242, 160, 170, 169, 240, 242, 239, 231, 187, 160, 170, 228, 160, 161, 189, 160, 167, 220, 176, 167, 187, 160, 228, 171, 171, 169, 138, 137, 137, 137, 240, 242, 233, 238, 244, 230, 168, 162, 160, 165, 228, 172, 162, 172, 160, 170, 228, 169, 187, 138, 137, 137, 240, 242, 233, 238, 244, 230, 168, 162, 160, 176, 160, 162, 169, 187, 138, 137, 137, 239, 238, 227, 229, 171, 171, 187, 138, 137, 137, 226, 242, 229, 225, 235, 187, 138, 137, 253, 138, 137, 229, 248, 233, 244, 168, 176, 169, 187, 138, 253, 138, 0 };

int
main(int argc, char **argv)
{
	int once;
	unsigned char *c, *d;

	once = 0;
	for(c = (unsigned char *)prog; *c != '\0'; c++) switch(*c - 128) {
	default:
		putchar(*c - 128);
		break;
	case '@':
		if(once) {
			putchar('@');
			break;
		}
		for(d = (unsigned char *)prog; *d != '\0'; d++)
			printf(" %d,", *d);
		printf(" 0 ");
		once++;
		break;
	}
	exit(0);
}
