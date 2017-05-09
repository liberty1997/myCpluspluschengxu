#define __STDC_WANT_LIB_EXT__ 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void) {
	char str[]="ghghghghghghghghghghghghghghgh";
	puts(str);
	memset(str,'a',5);
	puts(str);

#ifdef __STDC_LIB_EXT1__
	set_constraint_handler_s(ignore_handler_s);
	int r;
	r = memset_s(str,sizeof str, 'b', 5);
	printf("str = \"%s\", r = %d\n", str, r);
	r = memset_s(str,5,'c',10); // count is greater than destsz
	printf("str = \"%s\", r = %d\n", str, r);
#endif
}
