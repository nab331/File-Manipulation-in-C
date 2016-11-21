#include <stdio.h>
#include <dirent.h> //For listing Directories

struct Book
{
	char name[100];
	int price;
	char id[10];
};


struct Book input_book_values(struct Book book)
{

	printf("Enter Book Name : ");
	scanf("%[^\n]", book.name); //To include spaces

	printf("Enter Book Price : ");
	scanf("%d", &book.price );

	printf("Enter Book ID : ");
	scanf( "%s", book.id );

	return book;
}

void print_book(struct Book book)
{
	printf("\nDETAILS\n");
	printf("Name = %s\n", book.name);
	printf("Price = %d\n", book.price);
	printf("ID = %s\n", book.id);
}

int book_operations()
{
	int opt;

	printf("\t\t*OPERATIONS*");
	printf("\n\t\t1. View the list of Books");
	printf("\n\t\t2. Add Books");
	printf("\n\t\t3. Delete a Book");
	printf("\n\t\t4. Quit\n\t\t:");
	scanf("%d",&opt);

	return opt;
}


int file_operations(){
	int opt;

	printf("\t\t*OPERATIONS*");
	printf("\n\t\t1. View the list of Files");
	printf("\n\t\t2. Read file");
	printf("\n\t\t3. Write into a file");
	printf("\n\t\t4. Create new record");
	printf("\n\t\t5. Quit\n\t\t:");
	scanf("%d",&opt);
	printf("\n");

	DIR *d;
    struct dirent *dir;
    d = opendir("data");

    if (d)
    {
        while ( (dir = readdir(d)) != NULL)
        {	
        	char file_name = dir->d_name;

        	if ( strcmp(dir->d_name,".") != 0 )  //if file name and . are not the same
        		printf("%s\n", dir->d_name);
        }

        closedir(d);
    }

}



void main(){

	file_operations();

}