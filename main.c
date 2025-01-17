#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clrscr(){
system("cls");
}

int  SR=10,DR=20,TR=30,totres=0;
FILE *fichier;
typedef struct{
char custname[50],roomtype;
int rD,rM,rY,perday,numofper,resid,numofr;
float billamt;
}res;
res reservation[60];

void headerfooter(){
gotoxy(30,2);
printf("+===============================================================+\n");
gotoxy(30,3);
printf("|                      CHICRAM'S HOTEL                          |\n");
gotoxy(30,4);
printf("+===============================================================+\n");
gotoxy(1,24);
printf("______________________________________________________________________________________________________________________\n");
gotoxy(1,25);
printf("visit us at:http://www.chicramshotel.com");
}

char menu(){
clrscr();
headerfooter();
gotoxy(47,8);
printf("+-------------------------------+");
gotoxy(47,9);
printf("|            D:DATA             |");
gotoxy(47,10);
printf("|-------------------------------|");
gotoxy(47,11);
printf("|      H:HOTEL INFORMATION      |");
gotoxy(47,12);
printf("|-------------------------------|");
gotoxy(47,13);
printf("|         A:availability        |");
gotoxy(47,14);
printf("|-------------------------------|");
gotoxy(47,15);
printf("|         R:RESERVATION         |");
gotoxy(47,16);
printf("|-------------------------------|");
gotoxy(47,17);
printf("|             E:EXIT            |");
gotoxy(47,18);
printf("|-------------------------------|");
gotoxy(47,20);
printf("ENTER THE CHOICE : ");
gotoxy(65,20);
return(getche());
}

void report(){
fopen("file.txt","a+");
int i;
clrscr();
headerfooter();
srand(time(NULL));
reservation[totres].resid=rand()%1000;
gotoxy(10,5);
int c=0;
rewind(fichier);
c=getc(fichier);
if(c==EOF){
totres=0;
}else{
fseek(fichier,0,SEEK_END);
fscanf(fichier,"%d",totres);
rewind(fichier);
int i;
for(i=0;i<totres;i++){
fscanf(fichier,"%s%c%d%d%d%d%d%d%d%f%d",reservation[i].custname,reservation[i].roomtype,reservation[i].rD,reservation[i].rM,reservation[i].rY,reservation[i].perday,reservation[i].numofper,reservation[i].resid,reservation[i].numofr,reservation[i].billamt,c);
}}

if(totres==0)
{
    printf("\n No info to display");
}
else{
    for(i=0;i<totres;i++){
        printf("\n ID:%.4d      Name:%s",reservation[i].resid,reservation[i].custname);
        printf("\n Date:%d-%d-%d     Days:%s     Room:%c",reservation[i].rD,reservation[i].rM,reservation[i].rY,reservation[i].perday,reservation[i].roomtype);
        printf("\n Person:%d     Number of rooms:%s     Bill:%6.0f",reservation[i].numofper,reservation[i].numofr,reservation[i].billamt);
        printf("\n +---------------------------------------------------------------------------------------------------------------------------------------+");
        }
        }
fclose(fichier);
}

void roomavl(){
clrscr();
headerfooter();
gotoxy(5,5);
printf("room information:");
gotoxy(7,7);
printf("Single:   total=%d",SR);
gotoxy(7,8);
printf("Double:   total=%d",DR);
gotoxy(7,9);
printf("Triple:   total=%d",TR);
}

void hotelinfo(){
clrscr();
headerfooter();
gotoxy(3,6);
printf("AMENITIES : Our luxury hotel offers exceptional service and amenities to its guests. From the moment guests enter \n");
printf("the lobby, they are greeted with elegant decor, plush furnishings, and personalized attention from the staff. It offers\n");
printf("spacious guest rooms and suites that are exquisitely decorated with high-quality linens, comfortable bedding, and \n");
printf("state-of-the-art technology. These rooms often feature spectacular views and may include private balconies or terraces.\n");
printf("In addition , CHICRAM'S HOTEL offers an array of world-class amenities such as fine dining restaurants, children's \n");
printf("playground ,a high speed internet, lounges, spas, fitness centers, swimming pools and personalized service to their \n");
printf("guests .\n");
printf("LOCATION: 13 Route Nationale Oued Negro - BP 526, Fnideq 93100 Morocco.\n ");
printf("         Come to discover more about CHICRAM'S HOTEL and enjoy our accommodation in a dreamlife.");

gotoxy(1,15);
printf("Room Information :");
gotoxy(1,16);
printf("+-----------+-----------------------------------------------------------------------+----------+");
gotoxy(1,17);
printf("| Room Type |                             Information                               |   Price  |");
gotoxy(1,18);
printf("+-----------+-----------------------------------------------------------------------+----------+");
gotoxy(1,19);
printf("| Single    | One high quality bed , sitting area (sofa,desk and ergonomic chair),  | 1590 MAD |");
gotoxy(1,20);
printf("|           | large flat-screen TV , luxury bathroom , air conditioner  .           |          |");
gotoxy(1,21);
printf("+-----------+-----------------------------------------------------------------------+----------+");
gotoxy(1,22);
printf("|           | Twin or two separated high quality bed , sitting area (sofa,desk and  |          |");
gotoxy(1,23);
printf("|  Double   | ergonomic chair), large flat-screen TV , two luxury bathrooms         | 2830 MAD |");
gotoxy(1,24);
printf("|           | ,air conditioner .                                                    |          |");
gotoxy(1,25);
printf("+-----------+-----------------------------------------------------------------------+----------+");
gotoxy(1,26);
printf("|           | High quality beds by your choice , sitting area (sofa,desk and        |          |");
gotoxy(1,27);
printf("|  Triple   | ergonomic chair), large flat-screen TV, two luxury bathroom ,         | 3616 MAD |");
gotoxy(1,28);
printf("|           | ,air conditioner .                                                    |          |");
gotoxy(1,29);
printf("________________________________________________________________________________________________");
}

void reshotel(){
fopen("file.txt","a+");
clrscr();
headerfooter();
gotoxy(3,6);
printf("Enter Your Name : ");
gets(reservation[totres].custname);
fflush(stdin);
printf("\nEnter Date :\n");
printf("\t\t\tDay : ");
scanf("%d",&reservation[totres].rD);
fflush(stdin);
printf("\n\t\t\tMonth : ");
scanf("%d",&reservation[totres].rM);
printf("\n\t\t\tYear : ");
scanf("%d",&reservation[totres].rY);
fflush(stdin);
printf("\nEnter number of days : ");
scanf("%d",&reservation[totres].perday);
fflush(stdin);
printf("\nEnter Room Type(S/D/T) : ");
scanf("%c",&reservation[totres].roomtype);
fflush(stdin);
printf("\nEnter number of Person : ");
scanf("%d",&reservation[totres].numofper);
fflush(stdin);
int nperson=reservation[totres].numofper;
reservation[totres].numofr=1;
if((reservation[totres].roomtype=='S'||reservation[totres].roomtype=='s')&&nperson>1){
    while(nperson>1){
        nperson--;
        reservation[totres].numofr++;
    }
SR=SR-reservation[totres].numofr;
        }
if((reservation[totres].roomtype=='D'||reservation[totres].roomtype=='d')&&nperson>2){
    while(nperson>2){
        nperson--;
        reservation[totres].numofr++;
        }
DR=DR-reservation[totres].numofr;
        }
if((reservation[totres].roomtype=='T'||reservation[totres].roomtype=='t')&&nperson>3){
    while(nperson>3){
        nperson--;
        reservation[totres].numofr++;
        }
TR=TR-reservation[totres].numofr;
        }
clrscr();
headerfooter();
gotoxy(3,6);
printf("Bill:");
float price;
if(reservation[totres].roomtype=='S'||reservation[totres].roomtype=='s'){
price=1590;
reservation[totres].billamt=price*reservation[totres].perday*reservation[totres].numofr;
gotoxy(3,7);
printf("+------------+------------+---------------+------------------+---------------------+");
gotoxy(3,8);
printf("| Room Type  | Total days |    Pernight   | Number of rooms  |        Price        |");
gotoxy(3,9);
printf("+------------+------------+---------------+------------------+---------------------+");
gotoxy(3,10);
printf("| Single     |    %d       |   %.2f MAD |    %d             |    %.2f MAD      |",reservation[totres].perday,price,reservation[totres].numofr,reservation[totres].billamt);
gotoxy(3,11);
printf("+------------+------------+---------------+------------------+---------------------+");
}
else {
        if(reservation[totres].roomtype=='D'||reservation[totres].roomtype=='d'){
price=2830;
reservation[totres].billamt=price*reservation[totres].perday*reservation[totres].numofr;
gotoxy(3,7);
printf("+------------+------------+---------------+------------------+---------------------+");
gotoxy(3,8);
printf("| Room Type  | Total days |    Pernight   | Number of rooms  |        Price        |");
gotoxy(3,9);
printf("+------------+------------+---------------+------------------+---------------------+");
gotoxy(3,10);
printf("| Single     |    %d       |   %.2f MAD |    %d             |    %.2f MAD      |",reservation[totres].perday,price,reservation[totres].numofr,reservation[totres].billamt);
gotoxy(3,11);
printf("+------------+------------+---------------+------------------+---------------------+");
}
        else {
price=3616;
reservation[totres].billamt=price*reservation[totres].perday*reservation[totres].numofr;
gotoxy(3,7);
printf("+------------+------------+---------------+------------------+---------------------+");
gotoxy(3,8);
printf("| Room Type  | Total days |    Pernight   | Number of rooms  |        Price        |");
gotoxy(3,9);
printf("+------------+------------+---------------+------------------+---------------------+");
gotoxy(3,10);
printf("| Single     |    %d       |   %.2f MAD |    %d             |    %.2f MAD       |",reservation[totres].perday,price,reservation[totres].numofr,reservation[totres].billamt);
gotoxy(3,11);
printf("+------------+------------+---------------+------------------+---------------------+");
}}
totres++;
fprintf(fichier,"%s%c%d%d%d%d%d%d%d%f",reservation[totres-1].custname,reservation[totres-1].roomtype,reservation[totres-1].rD,reservation[totres-1].rM,reservation[totres-1].rY,reservation[totres-1].perday,reservation[totres-1].numofper,reservation[totres-1].resid,reservation[totres-1].numofr,reservation[totres-1].billamt);
fprintf(fichier,"%d",totres);
fclose(fichier);
}


void exist(){
gotoxy(20,22);
printf("Thank You...Visit Again...%c",2);
}
void autreChoix(){
gotoxy(20,22);
printf("Choix errone , Veuillez reessayez !!");
}
int main(){
headerfooter();
menu();
char option;
    option=menu();
    switch(option){
case 'D':case 'd':
    report();
    break;
case 'H':case 'h':
    hotelinfo();
    break;
case 'A':case 'a':
    roomavl();
    break;
case 'R':case 'r':
    reshotel();
    break;
case 'E':case 'e':
    exist();
    break;
default:autreChoix();}
return 0;}

