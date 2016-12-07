
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>c

struct phone                 //struct phone is a structure which can
{                            //save data as name,number and occupation.
  char name[30];
  char number[12];
  char occupation[20];
};

struct phone e,ee;           //structure variables for struct telephone

struct telephone            //struct telephone is a structure which can
{                           //save data as name,number and occupation.
 char namer[30];
 char numberer[12];
 char occupationer[20];
};

struct telephone ta[11],q[11];         //array of structures declared for
				     //struct telephone.
struct telephone t,v;

void add_record();                   // To add details of a person
void find_record_given_name();       // To find a name in the record
void find_record_given_number();     // To find a no. in the record
void delete_r();                     // To delete details of a person
void display();                      // To display the record
void modify_number();                // To modify a number
void modify_name();                  // To modify the existing name
void sort_by_name();                 // To sort the records by name
void sort_by_stdcodes();             // To sort records by std code
FILE *fp,*ft;
int gd=DETECT,gm;

int main()
{

   int choice;
   clrscr();
   while(1)                        //this while loop is to generate options
   {                               //again for user after he has completed one of the options.
      printf("\n");
      printf("WELCOME TO TELEPHONE DIRECTORY:- \n");
      printf("1.Add record.\n");
      printf("2.Find record based on number.\n");
      printf("3.Find record based on name.\n");
      printf("4.Display all records.\n");
      printf("5.Delete record.\n");
      printf("6.Modify number.\n");
      printf("7.Modify name.\n");
      printf("8.Sort records by names.\n");
      printf("9.Sort records by S.T.D. codes.\n");
      printf("10.Show contact list record limit.\n");
      printf("11.Exit.\n");
      printf("\n");
      printf("Your choice?\n");
      scanf("%d",&choice);

      switch(choice)
      {
	 case 1:{  add_record();                   }
	 break;
	 case 2:{  find_record_given_number();     }
	 break;
	 case 3:{  find_record_given_name();       }
	 break;
	 case 4:{  display();                      }
	 break;
	 case 5:{  delete_r();                     }
	 break;
	 case 6:{  modify_number();                }
	 break;
	 case 7:{  modify_name();                  }
	 break;
	 case 8:{  sort_by_name();                 }
	 break;
	 case 9:{  sort_by_stdcodes();             }
	 break;
	 case 10:{ printf("RECORD LIMIT = 10 \n"); }
	 break;
	 case 11:{ printf("Thank You\n");          }
	 delay(1000);
	 goto down;
	 default:{ printf("Wrong Entry!!!\n");     }
     }
   }
  down:
  return 0;
 }

void add_record()                   //the function add_record() will take
{                                   //information such as name,number and
    int h,p,t=0,w=0,b;                //occupation by the user.

    clrscr();
    fp=fopen("tel.dat","r");

    while(fread(&e,sizeof(e),1,fp)) //this loop reads number of records
    {                               //which already exist in the file.
     t++;
    }

    fclose(fp);

    if(t>=10)
    { initgraph(&gd,&gm,"C:\\TC\\BGI");
      outtextxy(1,200,"Record limit (10)  is exceeded no more records can be entered.\n");
      delay(5000);
      closegraph();
      goto y;
    }




    printf("Enter the name of the person.\n");
    getchar();
    scanf("%[^\n]s",e.name);

    for(h=0;h<strlen(e.name);h++)  //this loop is to check whether given name
    {                              //contains other character.

	 if(((e.name[h]>='a')&&(e.name[h]<='z'))||((e.name[h]>='A')&&(e.name[h]<='Z'))||(e.name[h]==' '))
	 continue;

	 else
	  { initgraph(&gd,&gm,"C:\\TC\\BGI");
	     outtextxy(1,200,"The following name contains characters other than normal alphabets\n");
	     outtextxy(1,220,"hence it can't be included in the directory.\n");
	     delay(5000);
	     closegraph();
	     goto kl;
	 }

    }
    fp=fopen("tel.dat","r");          //file "tel.dat" opened in reading mode.

    while(fread(&ee,sizeof(ee),1,fp)) //loop to check whether given name
    {                                 //already exist in the record.
       if(strcmpi(e.name,ee.name)==0)
       {
	  printf("You are including a name which already exist in the directory with number %s \n",ee.number);


       }

    }

    fclose(fp);
    printf("Enter the occupation of the person. \n");
    getchar();
    scanf("%[^\n]s",e.occupation);


    printf("Enter the phone number with a 4 digit S.T.D. code before the telephone number.\n");
    scanf("%s",e.number);

    if((strlen(e.number)<11)||(strlen(e.number)>11))   //To check the number is of count 11 or not.
    {
       printf("Inserted number is not valid.Number with S.T.D. code should count 11 and should not contain the characters other than the digits.\n");
       while(1)
       {
	   printf("Please enter a valid number\n");
	   scanf("%s",e.number);
	   if((strlen(e.number)==11))
	   break;
       }
    }

    while(1)    // To check the number contains characters other than digit or not.
    {
       b=0;
       for(h=0;h<strlen(e.number);h++)
       {
	   if((e.number[h]>='0')&&(e.number[h]<='9'))
	   b++;
       }
       if(b==11)
       goto eee;
       else
       {  initgraph(&gd,&gm,"C:\\TC\\BGI");
	  outtextxy(1,200,"Inserted number contains characters other than digits also.\n");
	  delay(5000);
	  closegraph();
	  printf("Please enter a valid number \n");

	  scanf("%s",e.number);          //To reenter the number if it contains special character.

       }

}
    eee:
    while(fread(&ee,sizeof(ee),1,fp))//loop to read records from file and
    {                                //check whether entered number already
	if(strcmp(ee.number,e.number)==0)//in the loop.
	     { initgraph(&gd,&gm,"C:\\TC\\BGI");
	       outtextxy(1,200,"The following number is already in the list.\n");
	       outtextxy(1,220,"hence it can't be included in the directory.\n");
	       delay(5000);
	       closegraph();
	       goto qqq;
	     }

	if(strcmp(ee.number,e.number)!=0)
	     {
	       w++;
	     }

    }

    if(w==t)
    printf("This number is not in the directory hence it is included.\n");
    printf("\n");


    fclose(fp);

    fp=fopen("tel.dat","a"); //file "tel.dat" opened in append mode to add the record if it is valid or not.

    fwrite(&e,sizeof(e),1,fp);        //To write in file named tel.dat

	   y:
	   qqq:
	   kl:

    fclose(fp);                     // To close the file tel.dat

}

 void find_record_given_name()  //this function gives full record if name is entered.
 {
    int counter=0,d;
    char str[30];

    clrscr();

    printf("enter the name.\n");
    getchar();
    scanf("%[^\n]s",str);

    for(d=0;d<strlen(str);d++)//loop to check whether entered name contains special characters or not.
      {
	if((((str[d]>='a')&&(str[d]<='z'))||((str[d]>='A')&&(str[d]<='Z')))||(str[d]==' '))
	continue;

	else

	{ initgraph(&gd,&gm,"C:\\TC\\BGI");
	 outtextxy(1,200,"The following name contains characters other than normal alphabets\n");
	  outtextxy(1,220,",please enter the number composed of alphabets only.\n");
	  delay(5000);
	  closegraph();
	  goto o;
	}

      }

    fp=fopen("tel.dat","r");        //file "tel.dat" in reading mode.
    while(fread(&e,sizeof(e),1,fp)) //this loop is to check whether entered number exist in the list or not.
    {
       if(strcmpi(str,e.name)==0)   // compares two strings and this function ignores the case.
       {
	   printf("name:%s\n",e.name);
	   printf("number=%s\n",e.number);
	   printf("occupation:%s\n",e.occupation);
	   counter++;
       }
    }
    if(counter==0)
    printf("no record found\n");

    o:
    fclose(fp);
}

   void find_record_given_number()    //this function gives record if name is given.
   {
     int b,h;
     char k[11];
     int count=0,x;

     clrscr();
      printf("Enter the phone number with a 4 digit S.T.D. code before the telephone number.\n");
    scanf("%s",k);

    if((strlen(k)<11)||(strlen(k)>11))      //To check whether count of inserted number is 11 or not.
    {
      printf("Inserted number is not valid.Number with S.T.D. code should count 11 and should not contain the characters other than the digits.\n");
      while(1)
      {
	   printf("Please enter a valid number\n");
	   scanf("%s",k);
	   if((strlen(k)==11))
	   break;
      }
    }

    while(1)
    {
      b=0;
      for(h=0;h<strlen(k);h++)
      {
	 if((k[h]>='0')&&(k[h]<='9'))
	 b++;
      }
      if(b==11)
      goto eee;
      else
      {  initgraph(&gd,&gm,"C:\\TC\\BGI");
	 outtextxy(1,200,"Inserted number contains characters other than digits also");
	 delay(5000);
	 closegraph();
	 printf("Please enter a valid number \n");
	 scanf("%s",k);
      }

    }
    eee:

     fp=fopen("tel.dat","r");         //file "tel.dat" opened in reading mode.
     while(fread(&e,sizeof(e),1,fp))  //loop to check wheather enterd nimber exist in the list.
     {
	  if(strcmp(k,e.number)==0)
	  {
	    printf("name=%s\n",e.name);
	    printf("number=%s\n",e.number);
	    printf("occupation=%s\n",e.occupation);
	    count++;
	  }
     }
     if(count==0)
     printf("no record found\n");
     f:
     q:
     fclose(fp);
  }

void delete_r()   //function to delete record.
{
   char del[30];
   int counter2=0,f;

   clrscr();

   printf("enter the name of the person.\n");
   getchar();
   scanf("%[^\n]s",del);

   for(f=0;f<strlen(del);f++) //loop to check whether entered number contains character other than digits or not.
   {
	if((((del[f]>='a')&&(del[f]<='z'))||((del[f]>='A')&&(del[f]<='Z')))||(del[f]==' '))
	continue;

	else
	{  initgraph(&gd,&gm,"C:\\TC\\BGI");
	   outtextxy(1,200,"The following name contains characters other than normal alphabets.\n");
	   outtextxy(1,220,"please enter the name composed of pure alphabets only.\n");
	   delay(5000);
	   closegraph();
	   goto omr;
       }

   }

  fp=fopen("tel.dat","r");     //file "tel.dat" opened in reading mode.
  ft=fopen("temp.dat","w");    //file "temp.dat" opened in writing mode.

  while(fread(&e,sizeof(e),1,fp))//loop to read records and delete specific records.
  {
     if(strcmpi(del,e.name)==0)
     {
	printf("record deleted\n");
	counter2++;
     }
     else
     fwrite(&e,sizeof(e),1,ft);
  }
  if(counter2==0)
  {
     printf("No such record found to be Deleted\n");
  }
  fclose(fp);
  fclose(ft);

  remove("tel.dat");

  rename("temp.dat","tel.dat");
  omr:

}

void display()  //function to display all records.
{
    clrscr();
    fp=fopen("tel.dat","r");
    printf("TELEPHONE DIRECTORY:-\n");
    printf("               Name                 Number                   Occupation\n");
    printf("________________________________________________________________________________\n");
    while(fread(&e,sizeof(e),1,fp))
    {
       printf(" %20s %25s %24s\n",e.name,e.number,e.occupation);

    }
    printf("________________________________________________________________________________\n");
    fclose(fp);
}

void modify_number()  //function to modify number.
{
    int b,h;
    char s[30];
    int counter1=0,dd;

    clrscr();

    printf("enter the name of the person for the number modification.\n");
    getchar();
    scanf("%[^\n]s",s);

    for(dd=0;dd<strlen(s);dd++) //loop to check whether entered number contains character other than digits or not.
    {
	if((((s[dd]>='a')&&(s[dd]<='z'))||((s[dd]>='A')&&(s[dd]<='Z')))||(s[dd]==' '))
	continue;

	else
	{  initgraph(&gd,&gm,"C:\\TC\\BGI");
	   outtextxy(1,200,"The following name contains characters other than normal alphabets,\n");
	   outtextxy(1,220,"please enter the number composed of alphabets only.\n");
	   delay(1000);
	   closegraph();
	   goto om;
	}

    }
    fp=fopen("tel.dat","r");        //file "tel.dat" opened in reading mode.
    ft=fopen("temp.dat","a");       //file "temp.dat" opened in append mode.


    while(fread(&e,sizeof(e),1,fp)) //loop to modify number.
    {
       if(strcmpi(e.name,s)==0)
       {

	    printf("Enter the new  phone number with a 4 digit S.T.D. code before the telephone number.\n");
	    scanf("%s",e.number);

	    if((strlen(e.number)<11)||(strlen(e.number)>11))
	    {
	       printf("Inserted number is not valid.Number with S.T.D. code should count 11 and should not contain the characters other than the digits.\n");
	       while(1)
	       {
		  printf("Please enter a valid number\n");
		  scanf("%s",e.number);
		  if((strlen(e.number)==11))
		  break;
		}
	     }

	   while(1)
	  {
	     b=0;
	     for(h=0;h<strlen(e.number);h++)
	     {
		if((e.number[h]>='0')&&(e.number[h]<='9'))
		b++;
	     }
	     if(b==11)
	     goto eee;
	     else
	     { initgraph(&gd,&gm,"C:\\TC\\BGI");
	       outtextxy(1,220,"Inserted number contains characters other than digits also");
	       delay(5000);
	       closegraph();
	       printf("Please enter a valid number \n");
	       scanf("%s",e.number);
	     }
	   }
	   eee:
	   fwrite(&e,sizeof(e),1,ft);
	   printf("Record Modified\n");
	   counter1++;
      }
     else
     fwrite(&e,sizeof(e),1,ft);
  }
	if (counter1==0)
	{
		printf("No such record found to modify\n");
	}

	fclose(fp);
	fclose(ft);

	remove("tel.dat");
	rename("temp.dat","tel.dat");

	f:
	fclose(fp);
	fclose(ft);
	remove("temp.dat");
	om:

}

void modify_name()        //function to modify name.
{
   char a[30],h;
   int counter2=0;

   clrscr();

   printf("Enter the name you want to modify\n");
   getchar();
   scanf("%[^\n]s",a);

    for(h=0;h<strlen(a);h++) //loop to check whether entered name contains other characters.

    {
	if((((a[h]>='a')&&(a[h]<='z'))||((a[h]>='A')&&(a[h]<='Z')))||(a[h]==' '))
	continue;

	else
	{initgraph(&gd,&gm,"C:\\TC\\BGI");
	outtextxy(1,200,"The following name contains characters other than normal alphabets \n");
	outtextxy(1,220,"please enter a number composed of pure alphabets only.\n");
	delay(5000);
	closegraph();
	goto is;
	}
     }
   fp=fopen("tel.dat","r");          //file "tel.dat" opened in reading mode.

   ft=fopen("temp.dat","w");        //file "temp.dat" opened in writing mode.

   while(fread(&e,sizeof(e),1,fp))  //loop to read record from file and modify number.
   {
      if(strcmpi(e.name,a)==0)

      {
	 printf("Enter the new name for %s\n",e.name);
	 getchar();
	 scanf("%[^\n]s",e.name);
	 fwrite(&e,sizeof(e),1,ft);
	 printf("Name Modified\n");
	 counter2++;

      }
      else
      fwrite(&e,sizeof(e),1,ft);
    }

   if(counter2==0)
      {
	 printf("No such record found to modify\n");
   }
   fclose(fp);
   fclose(ft);
   remove("tel.dat");
   rename("temp.dat","tel.dat");
   is:
}

  void sort_by_name()     //function to sort records by name.
  {
   int i,j,a=0;
   fp=fopen("tel.dat","r");

	while(fread(&ta[a],sizeof(ta[a]),1,fp))   //loop which counts total records.
	  {
	     a++;
	  }
	  fclose(fp);
	  for(i=1;i<a;i++)          //loop to sort records by name.
	  {
		for(j=0;j<a-i;j++)
		{
		   if(strcmpi(ta[j].namer,ta[j+1].namer)>0)   // strcmpi compares the string without being case sensitive.
		   {
		      t= ta[j];
		      ta[j]=ta[j+1];
		      ta[j+1]= t;
		   }
		}
	  }

   printf("the names in the sorted order are:-\n");
   printf("                Name                   Number                Occupation\n");
   printf("_______________________________________________________________________________\n");
   printf("\n");
   for(i=0;i<a;i++)
   {
     printf("%20s %25s %24s\n",ta[i].namer,ta[i].numberer,ta[i].occupationer);}
     printf("_______________________________________________________________________________\n");
   }

   void sort_by_stdcodes()
   {
     int i,j,a=0;
     fp=fopen("tel.dat","r");  //file "tel.dat" opened in reading mode.

     while(fread(&q[a],sizeof(q[a]),1,fp)) //loop to read total records .c
     {
       a++;
     }
     fclose(fp);
     for(i=1;i<a;i++)        //loops to sort records by S.T.D. codes.
     {
	for(j=0;j<a-i;j++)
	{
	    if(strncmp(q[j].numberer,q[j+1].numberer,4)>0)   // strncmp compares the first n characters of the string.
	    {
	       v=q[j];
	       q[j]=q[j+1];
	       q[j+1]=v;
	  }
	}
   }
   printf("The Records sorted in S.T.D. codes are:-\n");
   printf("              Name                 Number                    Occupation\n");
   printf("__________________________________________________________________c_____________\n");
   printf("\n");
   for(i=0;i<a;i++)
   {
      printf("%20s %25s %24s\n",q[i].namer,q[i].numberer,q[i].occupationer);}
      printf("_______________________________________________________________________________\n");
   }





