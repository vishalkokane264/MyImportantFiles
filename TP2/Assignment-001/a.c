#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"include/addition.h"
#include"include/subtraction.h"
#include"include/multiplication.h"
#include"include/division.h"
#define SIZE 50

char expression[10][20] = { 0 };
char op[10] = { 0 };
int numArr[SIZE] = { 0 };

int count = 0;

void
seperate_tok (char *expression)
{
  char p[20] = { 0 };
  int k = 0;
  int i = 0;
  int st = 0, end = 0;
  for (i = 0; i < strlen (expression); i++)
    {
      if (!ispunct (expression[i]) || expression[i]=='.')
	{
	  end++;
	}
      else
	{
	  for (int j = st, k = 0; j < end; j++, k++)
	    {
	      p[k] = expression[j];
	    }
	  numArr[count] = atoi (p);
	  if (op[count - 1] == '*' || op[count - 1] == '/')
	    {
	      if (op[count - 1] == '*')
		{
		  count--;
		  numArr[count] =
		    multFunction (numArr[count], numArr[count + 1]);
		}
	      if (op[count - 1] == '/')
		{
		  count--;
		  numArr[count] =
		    divFunction (numArr[count], numArr[count + 1]);
		}
	    }
	  op[count] = expression[end];
	  end++;
	  st = end;
	  count++;
	  for (int j = 0; j < 20; j++)
	    {
	      p[j] = 0;
	    }
	}
    }
  for (int j = st, k = 0; j < end; j++, k++)
    {
      p[k] = expression[j];
    }
  numArr[count] = atoi (p);
  if (op[count - 1] == '*' || op[count - 1] == '/')
    {
      if (op[count - 1] == '*')
	{
	  count--;
	  numArr[count] = multFunction (numArr[count], numArr[count + 1]);
	}
      if (op[count - 1] == '/')
	{
	  count--;
	  numArr[count] = divFunction (numArr[count], numArr[count + 1]);
	}
    }
}

void
solve ()
{
  int st = 0;
  count;
  while (st != count)
    {
      if (op[count - 1] == '+')
	{
	  numArr[count - 1] = addFunction (numArr[count - 1], numArr[count]);
	  count--;
	}
      if (op[count - 1] == '-')
	{
	  numArr[count - 1] = subFunction (numArr[count - 1], numArr[count]);
	  count--;
	}

    }
  printf ("Ans: %d", numArr[0]);
}

void
main ()
{
  char expression[50];
  printf ("Input the expression:(Only 2 oprand and 1 operator):");
  gets (expression);
  seperate_tok (expression);
  solve ();
}
