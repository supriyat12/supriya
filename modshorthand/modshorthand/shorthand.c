#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void ExpandShorthand(char *p)//function to expand short hand notation
{
	printf("string after expanding shorthand notation is\n");

	int iterator1 = 0, start_char, end_char;

	while (*(p +iterator1) != '\0')

	{

		if (p[iterator1] != '-')				//printing characters till'-'

			printf("%c", p[iterator1]);

		else

		{

			if (isalpha(*(p + (iterator1 - 1))))   //to check if an alphabet is given as input

			{

				start_char = (int)(*(p + (iterator1 - 1)));		//asci values of alphabets is considered.

				 end_char = (int)(*(p + (iterator1 + 1)));

				start_char++;

				while (start_char<end_char)						//loop for printing expanded shorthand notation.

					printf("%c", start_char++);

			}

			else

			{

				start_char = (*(p + (iterator1 - 1)));

				 end_char= (*(p + (iterator1 + 1)));

				start_char++;

				while (start_char< end_char)				//loop for printing expanded shorthand notation.

					printf("%c", start_char++);

			}

		}

		iterator1++;

	}

	getchar();

}

int main()

{

	char *string1;

	int i = 0, length, flag = 0;

	string1 = NULL;

	printf("enter the length of the string \n");

	scanf("%d", &length);

	string1 = (char *)malloc(sizeof(char)*(length + 1)); // dynamic memory allocation for the pointer

	if (string1 == NULL)

	{

		printf("memory not allocated\n");	//failed memory allocation

		return 0;

	}

	else

	{

		printf("enter string of size %d\n", length);
		scanf("%s",string1);
		if (!isalpha(string1[0]) && !isdigit(string1[0]))	//if 1st character is invalid
		{
		printf("invalid input....please enter the string properly \n");

			getchar();

		}

		if (!isalpha(string1[length - 1]) && !isdigit(string1[length - 1]))   //last character is invalid

		{

			printf("invalid input....please enter the string properly\n");

			getchar();

		}




		while (string1[i] != '\0')

		{

			if (string1[i] == '-')

			{

				if ((isdigit(string1[i - 1]) && !isdigit(string1[i + 1])) || (!isdigit(string1[i - 1]) && isdigit(string1[i + 1])))

				{

					flag = 1;
					printf("in debug1");
					printf("invalid input....please enter the string properly\n");        //when a combination of alpabet and number is given 

																						  //as input

				}

				if ((isalpha(string1[i - 1]) && !isalpha(string1[i + 1])) || (!isalpha(string1[i - 1]) && isalpha(string1[i + 1])))

				{

					flag = 1;
					printf("in debug2");

					printf("invalid input\n");

				}

				if (string1[i + 1] == '-')

				{
					printf("in debug3");

					printf("invalid input\n");

					flag = 1;

				}

				if ((islower(string1[i - 1]) && !islower(string1[i + 1])) || (isupper(string1[i - 1]) && !isupper(string1[i + 1])))

				{

					flag = 1;
					printf("in debug4");

					printf("invalid input\n");

				}

				if (string1[i - 1] > string1[i + 1])

				{

					flag = 1;

					printf("invalid input\n");

				}

			}

			else if (isalpha(string1[i]) ||isdigit(string1[i]))

			{
				i++;
				continue;

			}
			else
				break;
			
			if (flag == 1)

				break;
i++;

		}

		if (flag == 0)

			expand(string1); //call the expand function when a valid input is entered

		getchar();

		return 0;

	}

}
