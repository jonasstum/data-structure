#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 3

struct BookData
{
	char code[15];
	char name[50];
	char author[50];
};

struct BookStack
{
	struct BookData data[MAX_SIZE];
	unsigned short int begin;
	unsigned short int end;	
};

void stack_menu();
void push();
void pop();
void show_stack();

struct BookStack g_Books;

int main() 
{
	g_Books.begin = 0;
	g_Books.end = 0;
	
	stack_menu();
	
	return 0;
}

void stack_menu()
{
	system("cls");
	
	unsigned short int opt;
	
	printf("\n ******** CHOOSE AN OPTION ******** \n");
	printf(" 1 - Add book to stack\n");
	printf(" 2 - Remove a book from stack\n");
	printf(" 3 - Show stack\n");
	printf(" 0 - Exit program\n");
	printf(" ********************************** \n");
	scanf("%d", &opt);
	
	switch (opt) 
	{
		case 0:
			printf("\n Program Finished!\n");
			exit(0);
			break;
			
		case 1:
			push();
			break;
			
		case 2:
			pop();
			break;
			
		case 3:
			show_stack();
			break;
			
		default:
			printf("\n Invalid option! Try Again!\n\n");
			system("pause");
			stack_menu();
			break;
	}
}

void push()
{
	system("cls");
	
	if (g_Books.end == MAX_SIZE)
	{
		printf("\n Operation denied! The stack is full!\n\n");
		
		system("pause");
	}
	else
	{
		printf("\n *************** ADD BOOK ***************\n");
		fflush(stdin);
		printf(" Code: ");
		scanf("%15[^\n]s", g_Books.data[g_Books.end].code);
		fflush(stdin);
		printf(" Title: ");
		scanf("%50[^\n]s", g_Books.data[g_Books.end].name);
		fflush(stdin);
		printf(" Author: ");
		scanf("%50[^\n]s", g_Books.data[g_Books.end].author);
		fflush(stdin);
		printf(" ****************************************\n");
		
		g_Books.end++;
		
		printf("\n Book successfully added to stack!\n\n");
		
		system("pause");
	}
	
	stack_menu();
}

void pop()
{
	system("cls");
	
	if (g_Books.begin == g_Books.end)
	{
		printf("\n Operation denied! The stack is empty!\n\n");
		
		system("pause");
	}
	else
	{
		strcpy(g_Books.data[g_Books.end - 1].code, "");
		strcpy(g_Books.data[g_Books.end - 1].name, "");
		strcpy(g_Books.data[g_Books.end - 1].author, "");
		
		g_Books.end--;
		
		printf("\n Book %d successfully removed from stack!\n\n", g_Books.end + 1);
		
		system("pause");
	}
	
	stack_menu();
}

void show_stack()
{   
	system("cls");
	
	printf("\n ******************** BOOK STACK ********************\n");
	
    for (unsigned int i = 0; i < g_Books.end; i++) 
    {
      printf("\n ********* BOOK %d *********\n", i + 1);
      printf(" Code: %s\n", g_Books.data[i].code);
      printf(" Title: %s\n", g_Books.data[i].name);
      printf(" Author: %s\n", g_Books.data[i].author); 
      printf(" **************************\n");
    }
    
    printf("\n ****************************************************\n\n");
    
    system("pause");
    
    stack_menu();  
}
