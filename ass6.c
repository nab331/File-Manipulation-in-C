#include <stdio.h>

struct date 
{

	int d, m, y ; 

};


struct employee
{
 	//int empcode[2];
 	struct date join_date;
 	float salary;

 };


 struct date input_date(struct date the_date){

 	printf("Day = ");
 	scanf("%d",&the_date.d);

 	printf("Month = ");
 	scanf("%d",&the_date.m);

  	printf("Year = ");
 	scanf("%d",&the_date.y);

 }



void main(){

	struct employee Nabeel ;


	Nabeel.join_date.d = 12;
	Nabeel.join_date.m = 2;
	Nabeel.join_date.y = 2016;
	Nabeel.salary = 45603.90;

	FILE * file;

	file= fopen("Output", "w");

	if (file != NULL) {
	    fwrite( &Nabeel , sizeof(struct employee), 1, file);
	    fclose(file);
	}

	file= fopen("Output", "r");


	while (fread (&Nabeel, sizeof(struct employee), 1, file))
	      printf ("Day : %d\nMonth : %d\nYear : %d\nSalary : %f\n", Nabeel.join_date.d, Nabeel.join_date.m, Nabeel.join_date.y, Nabeel.salary );
	





}