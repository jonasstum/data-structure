#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

struct QueueData
{
	char name[50];
	char time[6]; 
};  

struct QueueControl
{
	struct QueueData data[MAX_SIZE];
	unsigned short int begin;
	unsigned short int end; 
};

struct QueueControl g_Queue;

void queue_menu();
void push_back();
void pop();
void show_clients();

int main() 
{
	g_Queue.begin = 0;
	g_Queue.end = 0;
	
	queue_menu();
	
	return 0;
}

void queue_menu()
{
	system("cls");
	
	unsigned short int opt;
	
	printf("\n ********** CHOOSE AN OPTION **********\n");
	printf(" 1 - Add client to queue\n");
	printf(" 2 - Remove client from queue\n");
	printf(" 3 - Show clients in the queue\n");
	printf(" 0 - Exit the program\n");
	printf(" **************************************\n");
	scanf("%d", &opt);
	
	switch (opt)
	{
		case 0:
			printf("\n Program Finished!\n");
			exit(0);
			
		case 1:
			push_back();
			break;
			
		case 2:
			pop();
			break;
			
		case 3:
			show_clients();
			break;
			
		default:
			printf("\n Invalid Option! Try Again!\n\n");
			system("pause");
			queue_menu();
			break;
	}
}

void push_back()
{
	system("cls");
	
	if (g_Queue.end == MAX_SIZE)
	{
		printf("\n Operation denied! The queue is full!\n\n");
    
		system("pause");
		
		queue_menu();
	}
	else
	{
		printf("\n *************** CLIENT DATA ***************\n");
		printf(" Name: ");
		fflush(stdin);
		scanf("%50[^\n]s", g_Queue.data[g_Queue.end].name);
		fflush(stdin);
		printf(" Arrival Time [HH:MM]: ");
		scanf("%6[^\n]s", g_Queue.data[g_Queue.end].time);
		fflush(stdin);
		printf(" *******************************************\n");
		
		g_Queue.end++;
		
		printf("\n Client successfully added to the queue!\n\n");
		
		system("pause");
		
		queue_menu();
	}
}

void pop()
{
	if (g_Queue.end == g_Queue.begin)
	{
		printf("\n Operation denied! The queue is empty!\n\n");
		
		system("pause");
		
		queue_menu();
	}
	else
	{
		strcpy(g_Queue.data[g_Queue.begin].name, "");
		strcpy(g_Queue.data[g_Queue.begin].time, "");
		
		for (unsigned short int i = 0; i < g_Queue.end; ++i)
		{
			g_Queue.data[i] = g_Queue.data[i + 1];
		}
		
		g_Queue.end--;
		
		printf("\n Client %d successfully removed from the queue!\n\n", 1);
		
		system("pause");
		
		queue_menu();
	}
}

void show_clients()
{
	system("cls");
	
	printf("\n *************** CLIENTS IN THE QUEUE ***************\n");
	
	for (unsigned short int i = 0; i < g_Queue.end; ++i)
	{
		printf("\n ****** CLIENT %d ******\n", i + 1);
		printf(" Name: %s\n", g_Queue.data[i].name);
		printf(" Arrival Time: %s\n", g_Queue.data[i].time);
		printf(" **********************\n");
	}
	
	printf("\n ****************************************************\n\n");
	
	system("pause");
		
	queue_menu();
}
