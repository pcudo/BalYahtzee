#include "printRoll.h"
#include "balyahtzee.h"

void printRoll (int * roll){
    int size = 8;
	int pos = 0;
	int line = 1;

	while (line <= 5)
	{
		switch (line)
		{
		case 1:
			while(pos<size)
			{
				switch(roll[pos])
				{
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
						printf("+---+	");
						break;
				}
				pos++;
			}
			printf("\n");
			line++;
			pos = 0;
			break;
		case 2:
			while(pos<size)
			{
				switch(roll[pos])
				{
					case 1:
						printf("|   |	");
						break;
					case 2:
						printf("|o  |	");
						break;
					case 3:
						printf("|o  |	");
						break;
					case 4:
						printf("|o o|	");
						break;
					case 5:
						printf("|o o|	");
						break;
					case 6:
						printf("|o o|	");
						break;
				}
				pos++;
			}
			printf("\n");
			line++;
			pos = 0;
			break;
		case 3:
			while(pos<size)
			{
				switch(roll[pos])
				{
					case 1:
						printf("| o |	");
						break;
					case 2:
						printf("|   |	");
						break;
					case 3:
						printf("| o |	");
						break;
					case 4:
						printf("|   |	");
						break;
					case 5:
						printf("| o |	");
						break;
					case 6:
						printf("|o o|	");
						break;
				}
				pos++;
			}
			printf("\n");
			line++;
			pos = 0;
			break;
		case 4:
			while(pos<size)
			{
				switch(roll[pos])
				{
					case 1:
						printf("|   |	");
						break;
					case 2:
						printf("|  o|	");
						break;
					case 3:
						printf("|  o|	");
						break;
					case 4:
						printf("|o o|	");
						break;
					case 5:
						printf("|o o|	");
						break;
					case 6:
						printf("|o o|	");
						break;
				}
				pos++;
			}
			printf("\n");
			line++;
			pos = 0;
			break;
		case 5:
			while(pos<size)
			{
				switch(roll[pos])
				{
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
						printf("+---+	");
						break;
				}
				pos++;
			}
			printf("\n");
			line++;
			break;
		}
	}
}
