#include<stdio.h>
int main()
{
	char ch;
	FILE *fp, *sp;
fopen_s(&fp, "first.txt", "r+");
	fopen_s(&sp, "first1.txt", "r+");
	
	getchar();

	while (!feof(fp))
	{
		
		ch = fgetc(fp);
		if (ch!=' ')
		{
			ch = ch - 32;
		}
		
		fputc(ch, sp);
	}
	
	fseek(fp, SEEK_SET, 4);
	int k=ftell(fp);
	printf("%d", k);
	fclose(fp);
	fclose(sp);
	return 0;
}