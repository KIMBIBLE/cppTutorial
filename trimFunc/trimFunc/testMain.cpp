#include "trim.h"

int main() {
	char stringAry[] = " asdf  ";
	char *string = "   vvddeeff   ";
	char buf[TRIM_BUF_SIZE];
	char noWhiteSpaceString[] = "aavv";

	// trim string array
	puts("trim string array");
	printf("lTrim : [%s]\n", lTrim(stringAry));
	printf("rTrim : [%s]\n", rTrim(stringAry));
	printf("trim  : [%s]\n", trim(stringAry));
	puts("");

	// trim string(R.O data)
	puts("trim string(R.O data)");
	memcpy(buf, string, strlen(string) + 1);
	printf("lTrim : [%s]\n", lTrim(buf));
	printf("rTrim : [%s]\n", rTrim(buf));
	printf("trim  : [%s]\n", trim(buf));
	puts("");

	// no change
	puts("no whitespace");
	printf("lTrim : [%s]\n", lTrim(noWhiteSpaceString));
	printf("rTrim : [%s]\n", rTrim(noWhiteSpaceString));
	printf("trim  : [%s]\n", trim(noWhiteSpaceString));
	puts("");

	return 0;
}
