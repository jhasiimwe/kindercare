#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <mysqld_error.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <dos.h>
float timefloat;
int timearr[8];
int markA();
int markB();
int markC();
int markD();
int markE();
int markF();
int markG();
int markH();
int markI();
int markJ();
int markK();
int markL();
int markM();
int markN();
int markO();
int markP();
int markQ();
int markR();
int markS();
int markT();
int markU();
int markV();
int markW();
int markX();
int markY();
int markZ();
int attempt(char *assignment);
int calculateScore(int correctPositions);
int errors();
void printchar(char *assignment);
void printing(char *letter[7][5]);
int checking_usercode(char* Usercode);
void display_instructionsActivated();
void display_instructionsDeactivated();
void requestActivation(char* Usercode);
int checking_status(char* usercode);
char* getMonth(char *month);
char* getDate(char *str);
char* getTime(char *system_time);
char* getSelectedAssign(int assignmentId);
void insertScore(char* usercode,int assignmentId,int score,float time);
void view_open_assignment(char* usercode);
void assignments_in_range();
void Checkstatus(char* usercode);
int getAttempted(char* usercode);
void getAVG(char* usercode);
void unAttempted_assignments(char *user_code);
void Viewall(char *usercode);
void Viewassignment();
char* getRemainingDays(char* date, char* expiryDate);
void viewComments(char* usercode);
int attemptable_assignments(char* usercode);   //returns number of assignments 
int Assignments();
//int missedAssignments(char* usercode);
    int main() {
	char usercode[6];
    SetConsoleTitle("KINDERCARE SYSTEM | ");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_INTENSITY);
	printf("\n\n\t==========================  WELCOME TO THE KINDERCARE E-LEARNING SYSTEM  ===============================\n\n");
	A:printf("\t\t\t\t\t Please enter your usercode to login:\n\t\t\t\t\t\t\t");
	gets(usercode);
	Sleep(1000);
     if(checking_usercode(usercode) == 0){
     	goto A;	
	 }
	 Sleep(1000);
 	if(checking_status(usercode) == 1) {
  	    display_instructionsDeactivated();	
  	    char command[100];
       E: printf("\n   Enter command to request activation:");
	    gets(command);
	     if(strcmp(command,"RequestActivation") == 0)
	     {
	    	requestActivation(usercode);
         	exit(0);
	    	}
	    	else{
	    		printf("\nInvalid command, try again");
	    		goto E;
			}		
	}
   	else {	
	    char command[100];
	    C:display_instructionsActivated();	
        printf("\n    Enter a commmand to continue: ");
	    gets(command);
	    if(strcmp(command,"Viewcomments") == 0){
		    viewComments(usercode);
		    Sleep(3000);
		    goto C;
	   }
	    else if(strcmp(command,"Attemptassignment") == 0){
	   	    view_open_assignment(usercode);
	   	    Sleep(2500);
	   	    goto C;
	   }
	    else if(strcmp(command,"Viewall") == 0){
        Viewall(usercode);
        Sleep(2500);
        goto C;
	   }
	    else if(strcmp(command,"Checkstatus") == 0){
	    Checkstatus(usercode);
	    Sleep(1000);
	    goto C;
	   }
	    else if(strcmp(command,"Viewassignment") == 0){
	    	Viewassignment();
	    	Sleep(3000);
	    	goto C;
    	}
        else if(strcmp(command,"Checkdates") == 0){
		    assignments_in_range();
		    Sleep(3000);
		    goto C;
	   }
	   else if(strcmp(command,"Exit") == 0){
	   	   Sleep(1000);
	   	   printf("Good bye\nExiting Application");
	   	    Sleep(1000);
	   	    printf(".");
	   	    Sleep(1000);
	   	    printf(".");
	   	     Sleep(1000);
	   	    printf(".");
	   	    goto D;
	   }
        else{
	   	printf("Invalid command,please check your command and try again\n");
	   	goto C;
	   }	
 }
      D:return 0;
}
    int errors(MYSQL* conn) {
	fprintf(stderr, "%s\n",mysql_error(conn));
	printf("\nUnknown error, shutting down");
	mysql_close(conn);
	exit(1);
}
//void check() {
    int markA(int timetaken[],int timeindex){
    printf("\nCharacter number %d is A\n",(timeindex+1));
    time_t begin = time(NULL);
	//letter A
	char *A[7][5];
	A[0][0] = " ";
	A[0][1] = " ";
	A[0][2] = "*";
	A[0][3] = " ";
	A[0][4] = " ";
	A[1][0] = " ";
	A[1][1] = "*";
	A[1][2] = " ";
	A[1][3] = "*";
	A[1][4] = " ";
	A[2][0] = "*";
	A[2][1] = " ";
	A[2][2] = " ";
	A[2][3] = " ";
	A[2][4] = "*";
	A[3][0] = "*";
	A[3][1] = "*";
	A[3][2] = "*";
	A[3][3] = "*";
	A[3][4] = "*";
	A[4][0] = "*";
	A[4][1] = " ";
	A[4][2] = " ";
	A[4][3] = " ";
	A[4][4] = "*";
	A[5][0] = "*";
	A[5][1] = " ";
	A[5][2] = " ";
	A[5][3] = " ";
	A[5][4] = "*";
	A[6][0] = "*";
	A[6][1] = " ";
	A[6][2] = " ";
	A[6][3] = " ";
	A[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && A[i][j] == "*") || (input[i][j] == 0 && A[i][j] == " ")){
				correct++;
			}

		}
	}
	time_t end = time(NULL);
	timearr[timeindex] = end - begin;
	return(calculateScore(correct));
}
	 
	 //======================================================================================================================
	//	Letter B
	int markB(int timetaken[],int timeindex) {
		printf("\nCharacter number %d is B\n",(timeindex+1));
	time_t begin = time(NULL);
	char *B[7][5];
	B[0][0] = "*";
	B[0][1] = "*";
	B[0][2] = "*";
	B[0][3] = "*";
	B[0][4] = " ";
	B[1][0] = "*";
	B[1][1] = " ";
	B[1][2] = " ";
	B[1][3] = " ";
	B[1][4] = "*";
	B[2][0] = "*";
	B[2][1] = " ";
	B[2][2] = " ";
	B[2][3] = " ";
	B[2][4] = "*";
	B[3][0] = "*";
	B[3][1] = "*";
	B[3][2] = "*";
	B[3][3] = "*";
	B[3][4] = " ";
	B[4][0] = "*";
	B[4][1] = " ";
	B[4][2] = " ";
	B[4][3] = " ";
	B[4][4] = "*";
	B[5][0] = "*";
	B[5][1] = " ";
	B[5][2] = " ";	
	B[5][3] = " ";
	B[5][4] = "*";
	B[6][0] = "*";
	B[6][1] = "*";
	B[6][2] = "*";
	B[6][3] = "*";
	B[6][4] = " ";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && B[i][j] == "*") || (input[i][j] == 0 && B[i][j] == " ")){
				correct++;
			}

		}
	}
       time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
	return(calculateScore(correct));
}
 //======================================================================================================================
	//	Letter C
	int markC(int timetaken[], int timeindex) {
		printf("\nCharacter number %d is C\n",(timeindex+1));
	time_t begin = time(NULL);
	char *C[7][5];
	C[0][0] = " ";
	C[0][1] = " ";
	C[0][2] = "*";
	C[0][3] = "*";
	C[0][4] = "*";
	C[1][0] = " ";
	C[1][1] = "*";
	C[1][2] = " ";
	C[1][3] = " ";
	C[1][4] = " ";
	C[2][0] = "*";
	C[2][1] = " ";
	C[2][2] = " ";
	C[2][3] = " ";
	C[2][4] = " ";
	C[3][0] = "*";
	C[3][1] = " ";
	C[3][2] = " ";
	C[3][3] = " ";
	C[3][4] = " ";
	C[4][0] = "*";
	C[4][1] = " ";
	C[4][2] = " ";
	C[4][3] = " ";
	C[4][4] = " ";
	C[5][0] = " ";
	C[5][1] = "*";
	C[5][2] = " ";
	C[5][3] = " ";
	C[5][4] = " ";
	C[6][0] = " ";
	C[6][1] = " ";
	C[6][2] = "*";
	C[6][3] = "*";
	C[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && C[i][j] == "*") || (input[i][j] == 0 && C[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
       return(calculateScore(correct));
}
	//======================================================================================================================
	int markD(int timetaken[],int timeindex) {
		printf("\nCharacter number %d is D\n",(timeindex+1));
	time_t begin = time(NULL);
	char *D[7][5];
	D[0][0] = "*";
	D[0][1] = "*";
	D[0][2] = "*";
	D[0][3] = " ";
	D[0][4] = " ";
	D[1][0] = "*";
	D[1][1] = " ";
	D[1][2] = " ";
	D[1][3] = "*";
	D[1][4] = " ";
	D[2][0] = "*";
	D[2][1] = " ";
	D[2][2] = " ";
	D[2][3] = " ";
	D[2][4] = "*";
	D[3][0] = "*";
	D[3][1] = " ";
	D[3][2] = " ";
	D[3][3] = " ";
	D[3][4] = "*";
	D[4][0] = "*";
	D[4][1] = " ";
	D[4][2] = " ";
	D[4][3] = " ";
	D[4][4] = "*";
	D[5][0] = "*";
	D[5][1] = " ";
	D[5][2] = " ";
	D[5][3] = "*";
	D[5][4] = " ";
	D[6][0] = "*";
	D[6][1] = "*";
	D[6][2] = "*";
	D[6][3] = " ";
	D[6][4] = " ";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && D[i][j] == "*") || (input[i][j] == 0 && D[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
     return(calculateScore(correct));
}
//======================================================================================================================
	//letter E
	int markE(int timetaken[],int timeindex) {
		printf("\nCharacter number %d is E\n",(timeindex+1));
	time_t begin = time(NULL);
	char *E[7][5];
	E[0][0] = "*";
	E[0][1] = "*";
	E[0][2] = "*";
	E[0][3] = "*";
	E[0][4] = "*";
	E[1][0] = "*";
	E[1][1] = " ";
	E[1][2] = " ";
	E[1][3] = " ";
	E[1][4] = " ";
	E[2][0] = "*";
	E[2][1] = " ";
	E[2][2] = " ";
	E[2][3] = " ";
	E[2][4] = " ";
	E[3][0] = "*";
	E[3][1] = "*";
	E[3][2] = "*";
	E[3][3] = "*";
	E[3][4] = "*";
	E[4][0] = "*";
	E[4][1] = " ";
	E[4][2] = " ";
	E[4][3] = " ";
	E[4][4] = " ";
	E[5][0] = "*";
	E[5][1] = " ";
	E[5][2] = " ";
	E[5][3] = " ";
	E[5][4] = " ";
	E[6][0] = "*";
	E[6][1] = "*";
	E[6][2] = "*";
	E[6][3] = "*";
	E[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && E[i][j] == "*") || (input[i][j] == 0 && E[i][j] == " ")){
				correct++;
			}

		}
	}
    	time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
     return(calculateScore(correct));
	}
//======================================================================================================================
   int markF(int timetaken[],int timeindex) {
   	printf("\nCharacter number %d is F\n",(timeindex+1));
   	time_t begin = time(NULL);
	//letter F
	char *F[7][5];
	F[0][0] = "*";
	F[0][1] = "*";
	F[0][2] = "*";
	F[0][3] = "*";
	F[0][4] = "*";
	F[1][0] = "*";
	F[1][1] = " ";
	F[1][2] = " ";
	F[1][3] = " ";
	F[1][4] = " ";
	F[2][0] = "*";
	F[2][1] = " ";
	F[2][2] = " ";
	F[2][3] = " ";
	F[2][4] = " ";
	F[3][0] = "*";
	F[3][1] = "*";
	F[3][2] = "*";
	F[3][3] = "*";
	F[3][4] = "*";
	F[4][0] = "*";
	F[4][1] = " ";
	F[4][2] = " ";
	F[4][3] = " ";
	F[4][4] = " ";
	F[5][0] = "*";
	F[5][1] = " ";
	F[5][2] = " ";
	F[5][3] = " ";
	F[5][4] = " ";
	F[6][0] = "*";
	F[6][1] = " ";
	F[6][2] = " ";
	F[6][3] = " ";
	F[6][4] = " ";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && F[i][j] == "*") || (input[i][j] == 0 && F[i][j] == " ")){
				correct++;
			}

		}
	}
	   time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
     return(calculateScore(correct));
}
	//======================================================================================================================
	int markG(int timetaken[],int timeindex) {
		printf("\nCharacter number %d is G\n",(timeindex+1));
	time_t begin = time(NULL);
	//	Letter G
	char *G[7][5];
	G[0][0] = " ";
	G[0][1] = " ";
	G[0][2] = "*";
	G[0][3] = "*";
	G[0][4] = "*";
	G[1][0] = " ";
	G[1][1] = "*";
	G[1][2] = " ";
	G[1][3] = " ";
	G[1][4] = " ";
	G[2][0] = "*";
	G[2][1] = " ";
	G[2][2] = " ";
	G[2][3] = " ";
	G[2][4] = " ";
	G[3][0] = "*";
	G[3][1] = " ";
	G[3][2] = " ";
	G[3][3] = " ";
	G[3][4] = " ";
	G[4][0] = "*";
	G[4][1] = " ";
	G[4][2] = " ";
	G[4][3] = "*";
	G[4][4] = "*";
	G[5][0] = " ";
	G[5][1] = "*";
	G[5][2] = " ";
	G[5][3] = " ";
	G[5][4] = "*";
	G[6][0] = " ";
	G[6][1] = " ";
	G[6][2] = "*";
	G[6][3] = "*";
	G[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && G[i][j] == "*") || (input[i][j] == 0 && G[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
       return(calculateScore(correct));
}
	//======================================================================================================================
	int markH(int timetaken[],int timeindex) {
		printf("\nCharacter number %d is H\n",(timeindex+1));
	time_t begin = time(NULL);
  //	Letter H
	char *H[7][5];
	H[0][0] = "*";
	H[0][1] = " ";
	H[0][2] = " ";
	H[0][3] = " ";
	H[0][4] = "*";
	H[1][0] = "*";
	H[1][1] = " ";
	H[1][2] = " ";
	H[1][3] = " ";
	H[1][4] = "*";
	H[2][0] = "*";
	H[2][1] = " ";
	H[2][2] = " ";
	H[2][3] = " ";
	H[2][4] = "*";
	H[3][0] = "*";
	H[3][1] = "*";
	H[3][2] = "*";
	H[3][3] = "*";
	H[3][4] = "*";
	H[4][0] = "*";
	H[4][1] = " ";
	H[4][2] = " ";
	H[4][3] = " ";
	H[4][4] = "*";
	H[5][0] = "*";
	H[5][1] = " ";
	H[5][2] = " ";
	H[5][3] = " ";
	H[5][4] = "*";
	H[6][0] = "*";
	H[6][1] = " ";
	H[6][2] = " ";
	H[6][3] = " ";
	H[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && H[i][j] == "*") || (input[i][j] == 0 && H[i][j] == " ")){
				correct++;
			}

		}
	}
	    time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
        return(calculateScore(correct));
}
	//=====================================================================================================================
	//	Letter I
	int markI(int timetaken[],int timeindex) {
		printf("\nCharacter number %d is I\n",(timeindex+1));
	time_t begin = time(NULL);
	char *I[7][5];
	I[0][0] = "*";
	I[0][1] = "*";
	I[0][2] = "*";
	I[0][3] = "*";
	I[0][4] = "*";
	I[1][0] = " ";
	I[1][1] = " ";
	I[1][2] = "*";
	I[1][3] = " ";
	I[1][4] = " ";
	I[2][0] = " ";
	I[2][1] = " ";
	I[2][2] = "*";
	I[2][3] = " ";
	I[2][4] = " ";
	I[3][0] = " ";
	I[3][1] = " ";
	I[3][2] = "*";
	I[3][3] = " ";
	I[3][4] = " ";
	I[4][0] = " ";
	I[4][1] = " ";
	I[4][2] = "*";
	I[4][3] = " ";
	I[4][4] = " ";
	I[5][0] = " ";
	I[5][1] = " ";
	I[5][2] = "*";
	I[5][3] = " ";
	I[5][4] = " ";
	I[6][0] = "*";
	I[6][1] = "*";
	I[6][2] = "*";
	I[6][3] = "*";
	I[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && I[i][j] == "*") || (input[i][j] == 0 && I[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
       return(calculateScore(correct));
}
		//======================================================================================================================
	int markJ(int timetaken[],int timeindex) {
		printf("\nCharacter number %d is J\n",(timeindex+1));
	time_t begin = time(NULL);
     	//	Letter J
	char *J[7][5];
	J[0][0] = "*";
	J[0][1] = "*";
	J[0][2] = "*";
	J[0][3] = "*";
	J[0][4] = "*";
	J[1][0] = " ";
	J[1][1] = " ";
	J[1][2] = " ";
	J[1][3] = " ";
	J[1][4] = "*";
	J[2][0] = " ";
	J[2][1] = " ";
	J[2][2] = " ";
	J[2][3] = " ";
	J[2][4] = "*";
	J[3][0] = " ";
	J[3][1] = " ";
	J[3][2] = " ";
	J[3][3] = " ";
	J[3][4] = "*";
	J[4][0] = " ";
	J[4][1] = " ";
	J[4][2] = " ";
	J[4][3] = " ";
	J[4][4] = "*";
	J[5][0] = "*";
	J[5][1] = " ";
	J[5][2] = " ";
	J[5][3] = " ";
	J[5][4] = "*";
	J[6][0] = " ";
	J[6][1] = "*";
	J[6][2] = "*";
	J[6][3] = "*";
	J[6][4] = " ";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && J[i][j] == "*") || (input[i][j] == 0 && J[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
       return(calculateScore(correct));
}
	//======================================================================================================================
	int markK(int timetaken[],int timeindex) {
		printf("\nCharacter number %d is K\n",(timeindex+1));
	time_t begin = time(NULL);
	//letter K
	char *K[7][5];
	K[0][0] = "*";
	K[0][1] = " ";
	K[0][2] = " ";
	K[0][3] = " ";
	K[0][4] = "*";
	K[1][0] = "*";
	K[1][1] = " ";
	K[1][2] = " ";
	K[1][3] = "*";
	K[1][4] = " ";
	K[2][0] = "*";
	K[2][1] = " ";
	K[2][2] = "*";
	K[2][3] = " ";
	K[2][4] = " ";
	K[3][0] = "*";
	K[3][1] = "*";
	K[3][2] = " ";
	K[3][3] = " ";
	K[3][4] = " ";
	K[4][0] = "*";
	K[4][1] = " ";
	K[4][2] = "*";
	K[4][3] = " ";
	K[4][4] = " ";
	K[5][0] = "*";
	K[5][1] = " ";
	K[5][2] = " ";
	K[5][3] = "*";
	K[5][4] = " ";
	K[6][0] = "*";
	K[6][1] = " ";
	K[6][2] = " ";
	K[6][3] = " ";
	K[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && K[i][j] == "*") || (input[i][j] == 0 && K[i][j] == " ")){
				correct++;
			}

		}
	} 
	   time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
        return(calculateScore(correct));;
}
//======================================================================================================================
   int markL(int timetaken[],int timeindex) {
   	printf("\nCharacter number %d is L\n",(timeindex+1));
   	time_t begin = time(NULL);
//	Letter L
	char *L[7][5];
	L[0][0] = "*";
	L[0][1] = " ";
	L[0][2] = " ";
	L[0][3] = " ";
	L[0][4] = " ";
	L[1][0] = "*";
	L[1][1] = " ";
	L[1][2] = " ";
	L[1][3] = " ";
	L[1][4] = " ";
	L[2][0] = "*";
	L[2][1] = " ";
	L[2][2] = " ";
	L[2][3] = " ";
	L[2][4] = " ";
	L[3][0] = "*";
	L[3][1] = " ";
	L[3][2] = " ";
	L[3][3] = " ";
	L[3][4] = " ";
	L[4][0] = "*";
	L[4][1] = " ";
	L[4][2] = " ";
	L[4][3] = " ";
	L[4][4] = " ";
	L[5][0] = "*";
	L[5][1] = " ";
	L[5][2] = " ";
	L[5][3] = " ";
	L[5][4] = " ";
	L[6][0] = "*";
	L[6][1] = "*";
	L[6][2] = "*";
	L[6][3] = "*";
	L[6][4] = "*"; 
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && L[i][j] == "*") || (input[i][j] == 0 && L[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
       return(calculateScore(correct));
}
//======================================================================================================================
	//letter M
	int markM(int timetaken[],int timeindex) {
		printf("\nCharacter number %d is M\n",(timeindex+1));
	time_t begin = time(NULL);
	char *M[7][5];
	M[0][0] = "*";
	M[0][1] = " ";
	M[0][2] = " ";
	M[0][3] = " ";
	M[0][4] = "*";
	M[1][0] = "*";
	M[1][1] = "*";
	M[1][2] = " ";
	M[1][3] = "*";
	M[1][4] = "*";
	M[2][0] = "*";
	M[2][1] = " ";
	M[2][2] = "*";
	M[2][3] = " ";
	M[2][4] = "*";
	M[3][0] = "*";
	M[3][1] = " ";
	M[3][2] = " ";
	M[3][3] = " ";
	M[3][4] = "*";
	M[4][0] = "*";
	M[4][1] = " ";
	M[4][2] = " ";
	M[4][3] = " ";
	M[4][4] = "*";
	M[5][0] = "*";
	M[5][1] = " ";
	M[5][2] = " ";
	M[5][3] = " ";
	M[5][4] = "*";
	M[6][0] = "*";
	M[6][1] = " ";
	M[6][2] = " ";
	M[6][3] = " ";
	M[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && M[i][j] == "*") || (input[i][j] == 0 && M[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	    timearr[timeindex] = end - begin;
        return(calculateScore(correct));
}
    //======================================================================================================================
    int markN(int timetaken[],int timeindex) {
    	printf("\nCharacter number %d is N\n",(timeindex+1));
    	time_t begin = time(NULL);
	//letter N
	char *N[7][5];
	N[0][0] = "*";
	N[0][1] = " ";
	N[0][2] = " ";
	N[0][3] = " ";
	N[0][4] = "*";
	N[1][0] = "*";
	N[1][1] = "*";
	N[1][2] = " ";
	N[1][3] = " ";
	N[1][4] = "*";
	N[2][0] = "*";
	N[2][1] = " ";
	N[2][2] = "*";
	N[2][3] = " ";
	N[2][4] = "*";
	N[3][0] = "*";
	N[3][1] = " ";
	N[3][2] = "*";
	N[3][3] = " ";
	N[3][4] = "*";
	N[4][0] = "*";
	N[4][1] = " ";
	N[4][2] = "*";
	N[4][3] = " ";
	N[4][4] = "*";
	N[5][0] = "*";
	N[5][1] = " ";
	N[5][2] = " ";
	N[5][3] = "*";
	N[5][4] = "*";
	N[6][0] = "*";
	N[6][1] = " ";
	N[6][2] = " ";
	N[6][3] = " ";
	N[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && N[i][j] == "*") || (input[i][j] == 0 && N[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	    timearr[timeindex] = end - begin;
        return(calculateScore(correct));
}
	//======================================================================================================================
	int markO(int timetaken[],int timeindex) {
		printf("\nCharacter number %d is O\n",(timeindex+1));
		time_t begin = time(NULL);
	//	Letter O
	char *O[7][5];
	O[0][0] = " ";
	O[0][1] = "*";
	O[0][2] = "*";
	O[0][3] = "*";
	O[0][4] = " ";
	O[1][0] = "*";
	O[1][1] = " ";
	O[1][2] = " ";
	O[1][3] = " ";
	O[1][4] = "*";
	O[2][0] = "*";
	O[2][1] = " ";
	O[2][2] = " ";
	O[2][3] = " ";
	O[2][4] = "*";
	O[3][0] = "*";
	O[3][1] = " ";
	O[3][2] = " ";
	O[3][3] = " ";
	O[3][4] = "*";
	O[4][0] = "*";
	O[4][1] = " ";
	O[4][2] = " ";
	O[4][3] = " ";
	O[4][4] = "*";
	O[5][0] = "*";
	O[5][1] = " ";
	O[5][2] = " ";
	O[5][3] = " ";
	O[5][4] = "*";
	O[6][0] = " ";
	O[6][1] = "*";
	O[6][2] = "*";
	O[6][3] = "*";
	O[6][4] = " ";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && O[i][j] == "*") || (input[i][j] == 0 && O[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	    timearr[timeindex] = end - begin;
        return(calculateScore(correct));
}
//======================================================================================================================
   int markP(int timetaken[],int timeindex) {
   	printf("\nCharacter number %d is P\n",(timeindex+1));
   	time_t begin = time(NULL);
	//	Letter P
	char *P[7][5];
	P[0][0] = "*";
	P[0][1] = "*";
	P[0][2] = "*";
	P[0][3] = "*";
	P[0][4] = " ";
	P[1][0] = "*";
	P[1][1] = " ";
	P[1][2] = " ";
	P[1][3] = " ";
	P[1][4] = "*";
	P[2][0] = "*";
	P[2][1] = " ";
	P[2][2] = " ";
	P[2][3] = " ";
	P[2][4] = "*";
	P[3][0] = "*";
	P[3][1] = "*";
	P[3][2] = "*";
	P[3][3] = "*";
	P[3][4] = " ";
	P[4][0] = "*";
	P[4][1] = " ";
	P[4][2] = " ";
	P[4][3] = " ";
	P[4][4] = " ";
	P[5][0] = "*";
	P[5][1] = " ";
	P[5][2] = " ";
	P[5][3] = " ";
	P[5][4] = " ";
	P[6][0] = "*";
	P[6][1] = " ";
	P[6][2] = " ";
	P[6][3] = " ";
	P[6][4] = " ";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && P[i][j] == "*") || (input[i][j] == 0 && P[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	    timearr[timeindex] = end - begin;
        return(calculateScore(correct));
}
 //======================================================================================================================
	//	Letter Q
     int markQ(int timetaken[],int timeindex) {
     	printf("\nCharacter number %d is Q\n",(timeindex+1));
     	time_t begin = time(NULL);
	char *Q[7][5];
	Q[0][0] = " ";
	Q[0][1] = "*";
	Q[0][2] = "*";
	Q[0][3] = "*";
	Q[0][4] = " ";
	Q[1][0] = "*";
	Q[1][1] = " ";
	Q[1][3] = " ";
	Q[1][4] = "*";
	Q[2][0] = "*";
	Q[2][1] = " ";
	Q[2][2] = " ";
	Q[2][3] = " ";
	Q[2][4] = "*";
	Q[3][0] = "*";
	Q[3][1] = " ";
	Q[3][2] = " ";
	Q[3][3] = " ";
	Q[3][4] = "*";
	Q[4][0] = "*";
	Q[4][1] = " ";
	Q[4][2] = "*";
	Q[4][3] = " ";
	Q[4][4] = "*";
	Q[5][0] = " ";
	Q[5][1] = "*";
	Q[5][2] = "*";
	Q[5][3] = "*";
	Q[5][4] = " ";
	Q[6][0] = " ";
	Q[6][1] = " ";
	Q[6][2] = " ";
	Q[6][3] = " ";
	Q[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && Q[i][j] == "*") || (input[i][j] == 0 && Q[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	    timearr[timeindex] = end - begin;
        return(calculateScore(correct));
}
	//======================================================================================================================
	int markR(int timetaken[],int timeindex) {
		printf("\nCharacter number %d is R\n",(timeindex+1));
		time_t begin = time(NULL);
	//	Letter R
	char *R[7][5];
	R[0][0] = "*";
	R[0][1] = "*";
	R[0][2] = "*";
	R[0][3] = "*";
	R[0][4] = " ";
	R[1][0] = "*";
	R[1][1] = " ";
	R[1][2] = " ";
	R[1][3] = " ";
	R[1][4] = "*";
	R[2][0] = "*";
	R[2][1] = " ";
	R[2][2] = " ";
	R[2][3] = " ";
	R[2][4] = "*";
	R[3][0] = "*";
	R[3][1] = "*";
	R[3][2] = "*";
	R[3][3] = "*";
	R[3][4] = " ";
	R[4][0] = "*";
	R[4][1] = " ";
	R[4][2] = " ";
	R[4][3] = "*";
	R[4][4] = " ";
	R[5][0] = "*";
	R[5][1] = " ";
	R[5][2] = " ";
	R[5][3] = " ";
	R[5][4] = "*";
	R[6][0] = " ";
	R[6][1] = " ";
	R[6][2] = " ";
	R[6][3] = " ";
	R[6][4] = " ";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && R[i][j] == "*") || (input[i][j] == 0 && R[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	    timearr[timeindex] = end - begin;
        return(calculateScore(correct));
}
//======================================================================================================================
     int markS(int timetaken[],int timeindex) {
     	printf("\nCharacter number %d is S\n",(timeindex+1));
     	time_t begin = time(NULL);
	//	Letter S
	char *S[7][5];
	S[0][0] = " ";
	S[0][1] = "*";
	S[0][2] = "*";
	S[0][3] = "*";
	S[0][4] = "*";
	S[1][0] = "*";
	S[1][1] = " ";
	S[1][2] = " ";
	S[1][3] = " ";
	S[1][4] = " ";
	S[2][0] = "*";
	S[2][1] = " ";
	S[2][2] = " ";
	S[2][3] = " ";
	S[2][4] = " ";
	S[3][0] = " ";
	S[3][1] = "*";
	S[3][2] = "*";
	S[3][3] = "*";
	S[3][4] = " ";
	S[4][0] = " ";
	S[4][1] = " ";
	S[4][2] = " ";
	S[4][3] = " ";
	S[4][4] = "*";
	S[5][0] = " ";
	S[5][1] = " ";
	S[5][2] = " ";
	S[5][3] = " ";
	S[5][4] = "*";
	S[6][0] = "*";
	S[6][1] = "*";
	S[6][2] = "*";
	S[6][3] = "*";
	S[6][4] = " ";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && S[i][j] == "*") || (input[i][j] == 0 && S[i][j] == " ")){
				correct++;
			}

		}
	}	
	time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
        return(calculateScore(correct));
}
//======================================================================================================================
   int markT(int timetaken[],int timeindex) {
   	printf("\nCharacter number %d is T\n",(timeindex+1));
   	time_t begin = time(NULL);
	//	Letter T
	char *T[7][5];
	T[0][0] = "*";
	T[0][1] = "*";
	T[0][2] = "*";
	T[0][3] = "*";
	T[0][4] = "*";
	T[1][0] = " ";
	T[1][1] = " ";
	T[1][2] = "*";
	T[1][3] = " ";
	T[1][4] = " ";
	T[2][0] = " ";
	T[2][1] = " ";
	T[2][2] = "*";
	T[2][3] = " ";
	T[2][4] = " ";
	T[3][0] = " ";
	T[3][1] = " ";
	T[3][2] = "*";
	T[3][3] = " ";
	T[3][4] = " ";
	T[4][0] = " ";
	T[4][1] = " ";
	T[4][2] = "*";
	T[4][3] = " ";
	T[4][4] = " ";
	T[5][0] = " ";
	T[5][1] = " ";
	T[5][2] = "*";
	T[5][3] = " ";
	T[5][4] = " ";
	T[6][0] = " ";
	T[6][1] = " ";
	T[6][2] = "*";
	T[6][3] = " ";
	T[6][4] = " ";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && T[i][j] == "*") || (input[i][j] == 0 && T[i][j] == " ")){
				correct++;
			}

		}
	}
		time_t end = time(NULL);
	    timearr[timeindex] = end - begin;
        return(calculateScore(correct));
}
//======================================================================================================================
   int markU(int timetaken[],int timeindex) {
   	printf("\nCharacter number %d is U\n",(timeindex+1));
   	time_t begin = time(NULL);
	//	Letter U
	char *U[7][5];
	U[0][0] = "*";
	U[0][1] = " ";
	U[0][2] = " ";
	U[0][3] = " ";
	U[0][4] = "*";
	U[1][0] = "*";
	U[1][1] = " ";
	U[1][2] = " ";
	U[1][3] = " ";
	U[1][4] = "*";
	U[2][0] = "*";
	U[2][1] = " ";
	U[2][2] = " ";
	U[2][3] = " ";
	U[2][4] = "*";
	U[3][0] = "*";
	U[3][1] = " ";
	U[3][2] = " ";
	U[3][3] = " ";
	U[3][4] = "*";
	U[4][0] = "*";
	U[4][1] = " ";
	U[4][2] = " ";
	U[4][3] = " ";
	U[4][4] = "*";
	U[5][0] = "*";
	U[5][1] = " ";
	U[5][2] = " ";
	U[5][3] = " ";
	U[5][4] = "*";
	U[6][0] = " ";
	U[6][1] = "*";
	U[6][2] = "*";
	U[6][3] = "*";
	U[6][4] = " ";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && U[i][j] == "*") || (input[i][j] == 0 && U[i][j] == " ")){
				correct++;
			}

		}
	}
	   time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
       return(calculateScore(correct));
}
//======================================================================================================================
     int markV(int timetaken[],int timeindex) {
     	printf("\nCharacter number %d is V\n",(timeindex+1));
     	time_t begin = time(NULL);
	//letter V
	char *V[7][5];
	V[0][0] = "*";
	V[0][1] = " ";
	V[0][2] = " ";
	V[0][3] = " ";
	V[0][4] = "*";
	V[1][0] = "*";
	V[1][1] = " ";
	V[1][2] = " ";
	V[1][3] = " ";
	V[1][4] = "*";
	V[2][0] = "*";
	V[2][1] = " ";
	V[2][2] = " ";
	V[2][3] = " ";
	V[2][4] = "*";
	V[3][0] = "*";
	V[3][1] = " ";
	V[3][2] = " ";
	V[3][3] = " ";
	V[3][4] = "*";
	V[4][0] = "*";
	V[4][1] = " ";
	V[4][2] = " ";
	V[4][3] = " ";
	V[4][4] = "*";
	V[5][0] = " ";
	V[5][1] = "*";
	V[5][2] = " ";
	V[5][3] = "*";
	V[5][4] = " ";
	V[6][0] = " ";
	V[6][1] = " ";
	V[6][2] = "*";
	V[6][3] = " ";
	V[6][4] = " ";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && V[i][j] == "*") || (input[i][j] == 0 && V[i][j] == " ")){
				correct++;
			}

		}
	}
    	time_t end = time(NULL);
	    timearr[timeindex] = end - begin;
        return(calculateScore(correct));
}
//======================================================================================================================
    int markW(int timetaken[],int timeindex) {
    	printf("\nCharacter number %d is W\n",(timeindex+1));
    	time_t begin = time(NULL);
	//letter N
	char *W[7][5];
	W[0][0] = "*";
	W[0][1] = " ";
	W[0][2] = " ";
	W[0][3] = " ";
	W[0][4] = "*";
	W[1][0] = "*";
	W[1][1] = " ";
	W[1][2] = " ";
	W[1][3] = " ";
	W[1][4] = "*";
	W[2][0] = "*";
	W[2][1] = " ";
	W[2][2] = " ";
	W[2][3] = " ";
	W[2][4] = "*";
	W[3][0] = "*";
	W[3][1] = " ";
	W[3][2] = " ";
	W[3][3] = " ";
	W[3][4] = "*";
	W[4][0] = "*";
	W[4][1] = " ";
	W[4][2] = "*";
	W[4][3] = " ";
	W[4][4] = "*";
	W[5][0] = "*";
	W[5][1] = "*";
	W[5][2] = " ";
	W[5][3] = "*";
	W[5][4] = "*";
	W[6][0] = "*";
	W[6][1] = " ";
	W[6][2] = " ";
	W[6][3] = " ";
	W[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && W[i][j] == "*") || (input[i][j] == 0 && W[i][j] == " ")){
				correct++;
			}

		}
	}
     	time_t end = time(NULL);
	    timearr[timeindex] = end - begin;
		return(calculateScore(correct));
}
//======================================================================================================================
    int markX(int timetaken[],int timeindex) {
    	printf("\nCharacter number %d is X\n",(timeindex+1));
    	time_t begin = time(NULL);
	//letter X
	char *X[7][5];
	X[0][0] = "*";
	X[0][1] = " ";
	X[0][2] = " ";
	X[0][3] = " ";
	X[0][4] = "*";
	X[1][0] = "*";
	X[1][1] = " ";
	X[1][2] = " ";
	X[1][3] = " ";
	X[1][4] = "*";
	X[2][0] = " ";
	X[2][1] = "*";
	X[2][2] = " ";
	X[2][3] = "*";
	X[2][4] = " ";
	X[3][0] = " ";
	X[3][1] = " ";
	X[3][2] = "*";
	X[3][3] = " ";
	X[3][4] = " ";
	X[4][0] = " ";
	X[4][1] = "*";
	X[4][2] = " ";
	X[4][3] = "*";
	X[4][4] = " ";
	X[5][0] = "*";
	X[5][1] = " ";
	X[5][2] = " ";
	X[5][3] = " ";
	X[5][4] = "*";
	X[6][0] = "*";
	X[6][1] = " ";
	X[6][2] = " ";
	X[6][3] = " ";
	X[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && X[i][j] == "*") || (input[i][j] == 0 && X[i][j] == " ")){
				correct++;
			}

		}
	}  
	   time_t end = time(NULL);
	   timearr[timeindex] = end - begin;
       return(calculateScore(correct));
}
	//======================================================================================================================
	 int markY(int timetaken[],int timeindex) {
	 	printf("\nCharacter number %d is Y\n",(timeindex+1));
	 	time_t begin = time(NULL);
//		Letter Y
	char *Y[7][5];
	Y[0][0] = "*";
	Y[0][1] = " ";
	Y[0][2] = " ";
	Y[0][3] = " ";
	Y[0][4] = "*";
	Y[1][0] = "*";
	Y[1][1] = " ";
	Y[1][2] = " ";
	Y[1][3] = " ";
	Y[1][4] = "*";
	Y[2][0] = " ";
	Y[2][1] = "*";
	Y[2][2] = " ";
	Y[2][3] = "*";
	Y[2][4] = " ";
	Y[3][0] = " ";
	Y[3][1] = " ";
	Y[3][2] = "*";
	Y[3][3] = " ";
	Y[3][4] = " ";
	Y[4][0] = " ";
	Y[4][1] = " ";
	Y[4][2] = "*";
	Y[4][3] = " ";
	Y[4][4] = " ";
	Y[5][0] = " ";
	Y[5][1] = " ";
	Y[5][2] = "*";
	Y[5][3] = " ";
	Y[5][4] = " ";
	Y[6][0] = " ";
	Y[6][1] = " ";
	Y[6][2] = "*";
	Y[6][3] = " ";
	Y[6][4] = " ";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && Y[i][j] == "*") || (input[i][j] == 0 && Y[i][j] == " ")){
				correct++;
			}

		}
	}
	    time_t end = time(NULL);
	    timearr[timeindex] = end - begin;
  	    return(calculateScore(correct));
  	
}
//======================================================================================================================
    int markZ(int timetaken[],int timeindex) {
    	printf("\nCharacter number %d is Z\n",(timeindex+1));
    time_t begin = time(NULL);
	//letter Z
	char *Z[7][5];
	Z[0][0] = "*";
	Z[0][1] = "*";
	Z[0][2] = "*";
	Z[0][3] = "*";
	Z[0][4] = "*";
	Z[1][0] = " ";
	Z[1][1] = " ";
	Z[1][2] = " ";
	Z[1][3] = " ";
	Z[1][4] = "*";
	Z[2][0] = " ";
	Z[2][1] = " ";
	Z[2][2] = " ";
	Z[2][3] = "*";
	Z[2][4] = " ";
	Z[3][0] = " ";
	Z[3][1] = " ";
	Z[3][2] = "*";
	Z[3][3] = " ";
	Z[3][4] = " ";
	Z[4][0] = " ";
	Z[4][1] = "*";
	Z[4][2] = " ";
	Z[4][3] = " ";
	Z[4][4] = " ";
	Z[5][0] = "*";
	Z[5][1] = " ";
	Z[5][2] = " ";
	Z[5][3] = " ";
	Z[5][4] = " ";
	Z[6][0] = "*";
	Z[6][1] = "*";
	Z[6][2] = "*";
	Z[6][3] = "*";
	Z[6][4] = "*";
	int correct = 0;
	int input[7][5];
	int position = 1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for(int i = 0; i<7; i++){
			for(int j = 0; j<5; j++){
				printf("Enter position %2d;",position);
				printf("Cell position: [%d][%d]:",(i+1),(j+1));
				int entered_digit;
				while(1){
				scanf("%d",&entered_digit);
				if(entered_digit == 0 || entered_digit == 1){
					input[i][j] = entered_digit;
					break;
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("Please enter valid input, 0 or 1:");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				position++;
			}
		}
		printf("\n=====================================================================================\n");
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<5; j++){
			if((input[i][j] == 1 && Z[i][j] == "*") || (input[i][j] == 0 && Z[i][j] == " ")){
				correct++;
			}

		}
	}	
		  time_t end = time(NULL);
	      timearr[timeindex] = end - begin;
          return(calculateScore(correct));
}

       int checking_usercode(char *Usercode){
    	MYSQL_ROW record;
    	MYSQL *conn = mysql_init(NULL);
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
        char query[300];
		sprintf(query,"SELECT * FROM pupilsdetails WHERE userCode = '%s'",Usercode);
		if(mysql_query(conn,query)){
			errors(conn);
		}
	    MYSQL_RES* rs = mysql_store_result(conn);
	    if(rs == NULL){
	      errors(conn);
		}
		int num_rows = mysql_num_rows(rs);
//		printf("%d",num_rows);
		int return_id;
		if(num_rows == 0) {
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED| FOREGROUND_INTENSITY);
			printf("\n\t\t\t\t\t\tInvalid usercode\n\n");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_INTENSITY);
			return_id = 0;
		}
		else{
			record = mysql_fetch_row(rs);
          if(strcmp(Usercode, record[3])==0){
          printf("\n\t\t\t\t\t\t**Welcome %s %s**\n", record[0], record[1]);
          return_id = 1;
          } 
		}
         mysql_free_result(rs);
         mysql_close(conn);
         return return_id;
}
                  
		void display_instructionsActivated() {
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_INTENSITY);
		printf("\n\t\t\t\t\t    KINDERCARE EL-SYSTEM COMMANDS LIST\t\t\t\t\t\n");
		printf("\t\t-------------------------------------------------------------------------------------------------\n"); 
		printf("\t\t|\tViewcomments - for displaying comments about your attempted assignments\t\t\t|\n\n");
		printf("\t\t|\tAttemptassignment - To start attempting open assignments\t\t\t\t|\n\n");   
		printf("\t\t|\tViewall - Displays assignment number and date , showing if attempted or not\t\t|\n\n");
		printf("\t\t|\tCheckstatus - Displays the status report of the pupil summarizing all assignments\t|\n\n");
		printf("\t\t|\tViewassignment - to see details of a specified assignment \t\t\t\t|\n\n");
		printf("\t\t|\tCheckdates - shows if there is an assignment in a specific [datefrom][dateto] date range|\n\n");
		printf("\t\t|\tExit - to quit the application\t\t\t\t\t\t\t\t|\n");
		printf("\t\t-------------------------------------------------------------------------------------------------\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN| FOREGROUND_INTENSITY);
		}    
	    int checking_status(char* Usercode) {
    	MYSQL_ROW record;
    	MYSQL *conn = mysql_init(NULL);
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
        char query[300] = "SELECT * FROM pupilsdetails WHERE userCode = '";
		strcat(query,Usercode);
		strcat(query,"' LIMIT 1");
		if(mysql_query(conn,query)){
			errors(conn);
		}
	    MYSQL_RES* rs = mysql_store_result(conn);
	    if(rs == NULL){
	      errors(conn);
		}
		record = mysql_fetch_row(rs);
		if(strcmp(record[4],"Activated")== 0){
		printf("\n\t\t\t\t\t\t  **You are activated**\n");
		mysql_free_result(rs);
		mysql_close(conn);	
        return 0;
		}
	    if(strcmp(record[4],"Deactivated")== 0) {
		printf("\n\t\t\t\t\t  **You are currently deactivated**\n");
		mysql_free_result(rs);
		mysql_close(conn);	
        return 1;
		}                      
	}
	void display_instructionsDeactivated() {
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_INTENSITY);
		printf("\n\t\t\t\t\t    KINDERCARE EL-SYSTEM COMMANDS LIST\t\t\t\t\t\n");
		printf("\t\t-------------------------------------------------------------------------------------------------\n"); 
		printf("\t\t|\tRequestActivation - used for pupil to request teacher to activate him or her \t\t|\n");
		printf("\t\t-------------------------------------------------------------------------------------------------\n"); 
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN| FOREGROUND_INTENSITY);
	}
	 
	 void requestActivation(char* Usercode) {
	 	MYSQL_ROW record;
    	MYSQL *conn = mysql_init(NULL);
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
		char query[300] = "UPDATE pupilsdetails SET activationrequest = 'Requested' WHERE Usercode = '";
		strcat(query,Usercode);
		strcat(query,"';");
		if(mysql_query(conn,query)) {
         errors(conn);
        }
        printf("Your request has been submitted\n Try after sometime\n");
        Sleep(2000);
        printf("We are working on it");
        mysql_close(conn);
	 }
	 int calculateScore(int correctPositions) {
	 	int score = correctPositions*100/35;
	    return score;
	 }
	 
        void view_open_assignment(char* usercode){
    	MYSQL *conn = mysql_init(NULL);
    	MYSQL_ROW record;
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) { 
	    	errors(conn);
		}
		time_t t;
      	time(&t);
        char time_string[35];
        printf("-------------------\n");
        printf("|Date and time Now|\n");
        printf("-------------------\n");	
	    printf("%s\n",ctime(&t));
	    strcpy(time_string,ctime(&t));
	    char dateToday[15];
	    char timeNow[15];
	    strcpy(dateToday,getDate(time_string));
	    strcpy(timeNow,getTime(time_string));
	    char query[300];
	    sprintf(query,"SELECT * FROM asssignmentdetails WHERE (expiryDate >'%s' OR (expiryDate = '%s' AND expiryTime>'%s')) AND (assignmentId NOT IN (SELECT assignmentId FROM scores where userCode= '%s'));",dateToday,dateToday,timeNow,usercode);
		if(mysql_query(conn,query)){
			errors(conn);
		}
		MYSQL_RES* rs = mysql_store_result(conn);
		printf("------------------\n");
        printf("|Open assignments|\n");
        printf("------------------\n\n");	
		printf("Assignmentid   Characters\t\t Exp. date \t\tExp. time  Remaining days\n");
		int num_rows = mysql_num_rows(rs);
	    if(num_rows == 0) {
	     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_INTENSITY);
	    	printf("No assignments open unattempted assignments\n");
	    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_INTENSITY);
		}
		else {
			int attemptable = attemptable_assignments(usercode);
			int assignmentIds[attemptable];
			int i = 0;
		    while(record = mysql_fetch_row(rs)) {
			int characters = strlen(record[1]);
			printf("%s\t\t %d\t\t\t %s\t\t %s\t %s\n", record[0],characters,record[2],record[3],getRemainingDays(dateToday,record[2]));	
			assignmentIds[i] = atoi(record[0]);
		    i++;		
		}
		int assignmentId;
		printf("\n\nPlease enter the assignmentId to start attempting the assignment now:");
		while(1) {
		scanf("%d",&assignmentId);
		  for(int j = 0; j<attemptable; j++){
		  	if(assignmentIds[j] == assignmentId && assignmentId != 0) {
		  		goto T;
			  }
		}
			  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
			  printf("The entered assignment Id is invalid, expired or already attempted\n");
			  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			  printf("Please enter valid usercode:");
	    	}
		T:SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("\nEnter a '1' to represent a star and '0' to represent no star\n");
		printf("Each character has 7x5 fields to fill\n");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		int marks = attempt(getSelectedAssign(assignmentId));
		insertScore(usercode,assignmentId,marks,timefloat);
		timefloat = 0;
		for(int i = 0; i<8; i++) {
			timearr[i] = 0;
		}
   }
}
int attempt(char *assignment) {
	int assig_mark = 0;
	int assignment_characters = strlen(assignment);
	for(int i = 0; i<assignment_characters ;i++) {
		switch(assignment[i]){
		case 'A':
			assig_mark+=markA(timearr,i);
		break;
		case 'B':
			assig_mark+=markB(timearr,i);
		break;
		case 'C':
			assig_mark+=markC(timearr,i);
		break;
		case 'D':
			assig_mark+=markD(timearr,i);
		break;
		case 'E':
			assig_mark+=markE(timearr,i);
		break;
		case 'F':
			assig_mark+=markF(timearr,i);
		break;
		case 'G':
			assig_mark+=markG(timearr,i);
		break;
		case 'H':
			assig_mark+=markH(timearr,i);
		break;
		case 'I':
			assig_mark+=markI(timearr,i);
		break;
		case 'J':
			assig_mark+=markJ(timearr,i);
		break;
		case 'K':
			assig_mark+=markK(timearr,i);
		break;
		case 'L':
			assig_mark+=markL(timearr,i);
		break;
		case 'M':
			assig_mark+=markM(timearr,i);
		break;
		case 'N':
			assig_mark+=markN(timearr,i);
		break;
		case 'O':
			assig_mark+=markO(timearr,i);
		break;
		case 'P':
			assig_mark+=markP(timearr,i);
		break;
		case 'Q':
			assig_mark+=markQ(timearr,i);
		break;
		case 'R':
			assig_mark+=markR(timearr,i);
		break;
		case 'S':
			assig_mark+=markS(timearr,i);
		break;
		case 'T':
			assig_mark+=markT(timearr,i);
		break;
		case 'U':
			assig_mark+=markU(timearr,i);
		break;
		case 'V':
			assig_mark+=markV(timearr,i);
		break;
		case 'W':
			assig_mark+=markW(timearr,i);
		break;
		case 'X':
			assig_mark+=markX(timearr,i);
		break;
		case 'Y':
			assig_mark+=markY(timearr,i);
		break;
		case 'Z':
			assig_mark+=markZ(timearr,i);
		break;
		default:
		exit(1);
		}
	}
	int attempt_time = 0;
	for(int i = 0; i<assignment_characters; i++) {
	   attempt_time+=timearr[i];
	}
	 float minutes = attempt_time/60;
	 float seconds = (float)(attempt_time%60)/60;
	 timefloat = minutes + seconds;
	 //calling printchar method to print the right characters
	printchar(assignment);
	printf("The time taken is %f minutes\n\n",timefloat);
    int attemptScore = (assig_mark/assignment_characters);
    printf("Your score is %d\n\n",attemptScore);
    Sleep(1000);
    printf("Practice makes perfect\n");
	return attemptScore;  
}
    void printchar(char *assignment) {
	//letter A
	char *A[7][5];
	A[0][0] = " ";
	A[0][1] = " ";
	A[0][2] = "*";
	A[0][3] = " ";
	A[0][4] = " ";
	A[1][0] = " ";
	A[1][1] = "*";
	A[1][2] = " ";
	A[1][3] = "*";
	A[1][4] = " ";
	A[2][0] = "*";
	A[2][1] = " ";
	A[2][2] = " ";
	A[2][3] = " ";
	A[2][4] = "*";
	A[3][0] = "*";
	A[3][1] = "*";
	A[3][2] = "*";
	A[3][3] = "*";
	A[3][4] = "*";
	A[4][0] = "*";
	A[4][1] = " ";
	A[4][2] = " ";
	A[4][3] = " ";
	A[4][4] = "*";
	A[5][0] = "*";
	A[5][1] = " ";
	A[5][2] = " ";
	A[5][3] = " ";
	A[5][4] = "*";
	A[6][0] = "*";
	A[6][1] = " ";
	A[6][2] = " ";
	A[6][3] = " ";
	A[6][4] = "*";
	 //======================================================================================================================
	//	Letter B
	char *B[7][5];
	B[0][0] = "*";
	B[0][1] = "*";
	B[0][2] = "*";
	B[0][3] = "*";
	B[0][4] = " ";
	B[1][0] = "*";
	B[1][1] = " ";
	B[1][2] = " ";
	B[1][3] = " ";
	B[1][4] = "*";
	B[2][0] = "*";
	B[2][1] = " ";
	B[2][2] = " ";
	B[2][3] = " ";
	B[2][4] = "*";
	B[3][0] = "*";
	B[3][1] = "*";
	B[3][2] = "*";
	B[3][3] = "*";
	B[3][4] = " ";
	B[4][0] = "*";
	B[4][1] = " ";
	B[4][2] = " ";
	B[4][3] = " ";
	B[4][4] = "*";
	B[5][0] = "*";
	B[5][1] = " ";
	B[5][2] = " ";
	B[5][3] = " ";
	B[5][4] = "*";
	B[6][0] = "*";
	B[6][1] = "*";
	B[6][2] = "*";
	B[6][3] = "*";
	B[6][4] = " ";
 //======================================================================================================================
	//	Letter C
	char *C[7][5];
	C[0][0] = " ";
	C[0][1] = " ";
	C[0][2] = "*";
	C[0][3] = "*";
	C[0][4] = "*";
	C[1][0] = " ";
	C[1][1] = "*";
	C[1][2] = " ";
	C[1][3] = " ";
	C[1][4] = " ";
	C[2][0] = "*";
	C[2][1] = " ";
	C[2][2] = " ";
	C[2][3] = " ";
	C[2][4] = " ";
	C[3][0] = "*";
	C[3][1] = " ";
	C[3][2] = " ";
	C[3][3] = " ";
	C[3][4] = " ";
	C[4][0] = "*";
	C[4][1] = " ";
	C[4][2] = " ";
	C[4][3] = " ";
	C[4][4] = " ";
	C[5][0] = " ";
	C[5][1] = "*";
	C[5][2] = " ";
	C[5][3] = " ";
	C[5][4] = " ";
	C[6][0] = " ";
	C[6][1] = " ";
	C[6][2] = "*";
	C[6][3] = "*";
	C[6][4] = "*";
	//======================================================================================================================
	//	Letter D
	char *D[7][5];
	D[0][0] = "*";
	D[0][1] = "*";
	D[0][2] = "*";
	D[0][3] = " ";
	D[0][4] = " ";
	D[1][0] = "*";
	D[1][1] = " ";
	D[1][2] = " ";
	D[1][3] = "*";
	D[1][4] = " ";
	D[2][0] = "*";
	D[2][1] = " ";
	D[2][2] = " ";
	D[2][3] = " ";
	D[2][4] = "*";
	D[3][0] = "*";
	D[3][1] = " ";
	D[3][2] = " ";
	D[3][3] = " ";
	D[3][4] = "*";
	D[4][0] = "*";
	D[4][1] = " ";
	D[4][2] = " ";
	D[4][3] = " ";
	D[4][4] = "*";
	D[5][0] = "*";
	D[5][1] = " ";
	D[5][2] = " ";
	D[5][3] = "*";
	D[5][4] = " ";
	D[6][0] = "*";
	D[6][1] = "*";
	D[6][2] = "*";
	D[6][3] = " ";
	D[6][4] = " ";	
//======================================================================================================================
	//letter E
	char *E[7][5];
	E[0][0] = "*";
	E[0][1] = "*";
	E[0][2] = "*";
	E[0][3] = "*";
	E[0][4] = "*";
	E[1][0] = "*";
	E[1][1] = " ";
	E[1][2] = " ";
	E[1][3] = " ";
	E[1][4] = " ";
	E[2][0] = "*";
	E[2][1] = " ";
	E[2][2] = " ";
	E[2][3] = " ";
	E[2][4] = " ";
	E[3][0] = "*";
	E[3][1] = "*";
	E[3][2] = "*";
	E[3][3] = "*";
	E[3][4] = "*";
	E[4][0] = "*";
	E[4][1] = " ";
	E[4][2] = " ";
	E[4][3] = " ";
	E[4][4] = " ";
	E[5][0] = "*";
	E[5][1] = " ";
	E[5][2] = " ";
	E[5][3] = " ";
	E[5][4] = " ";
	E[6][0] = "*";
	E[6][1] = "*";
	E[6][2] = "*";
	E[6][3] = "*";
	E[6][4] = "*";
//======================================================================================================================
	//letter F
	char *F[7][5];
	F[0][0] = "*";
	F[0][1] = "*";
	F[0][2] = "*";
	F[0][3] = "*";
	F[0][4] = "*";
	F[1][0] = "*";
	F[1][1] = " ";
	F[1][2] = " ";
	F[1][3] = " ";
	F[1][4] = " ";
	F[2][0] = "*";
	F[2][1] = " ";
	F[2][2] = " ";
	F[2][3] = " ";
	F[2][4] = " ";
	F[3][0] = "*";
	F[3][1] = "*";
	F[3][2] = "*";
	F[3][3] = "*";
	F[3][4] = "*";
	F[4][0] = "*";
	F[4][1] = " ";
	F[4][2] = " ";
	F[4][3] = " ";
	F[4][4] = " ";
	F[5][0] = "*";
	F[5][1] = " ";
	F[5][2] = " ";
	F[5][3] = " ";
	F[5][4] = " ";
	F[6][0] = "*";
	F[6][1] = " ";
	F[6][2] = " ";
	F[6][3] = " ";
	F[6][4] = " ";
	//======================================================================================================================
	//	Letter G
	char *G[7][5];
	G[0][0] = " ";
	G[0][1] = " ";
	G[0][2] = "*";
	G[0][3] = "*";
	G[0][4] = "*";
	G[1][0] = " ";
	G[1][1] = "*";
	G[1][2] = " ";
	G[1][3] = " ";
	G[1][4] = " ";
	G[2][0] = "*";
	G[2][1] = " ";
	G[2][2] = " ";
	G[2][3] = " ";
	G[2][4] = " ";
	G[3][0] = "*";
	G[3][1] = " ";
	G[3][2] = " ";
	G[3][3] = " ";
	G[3][4] = " ";
	G[4][0] = "*";
	G[4][1] = " ";
	G[4][2] = " ";
	G[4][3] = "*";
	G[4][4] = "*";
	G[5][0] = " ";
	G[5][1] = "*";
	G[5][2] = " ";
	G[5][3] = " ";
	G[5][4] = "*";
	G[6][0] = " ";
	G[6][1] = " ";
	G[6][2] = "*";
	G[6][3] = "*";
	G[6][4] = "*";
	//======================================================================================================================
  //	Letter H
	char *H[7][5];
	H[0][0] = "*";
	H[0][1] = " ";
	H[0][2] = " ";
	H[0][3] = " ";
	H[0][4] = "*";
	H[1][0] = "*";
	H[1][1] = " ";
	H[1][2] = " ";
	H[1][3] = " ";
	H[1][4] = "*";
	H[2][0] = "*";
	H[2][1] = " ";
	H[2][2] = " ";
	H[2][3] = " ";
	H[2][4] = "*";
	H[3][0] = "*";
	H[3][1] = "*";
	H[3][2] = "*";
	H[3][3] = "*";
	H[3][4] = "*";
	H[4][0] = "*";
	H[4][1] = " ";
	H[4][2] = " ";
	H[4][3] = " ";
	H[4][4] = "*";
	H[5][0] = "*";
	H[5][1] = " ";
	H[5][2] = " ";
	H[5][3] = " ";
	H[5][4] = "*";
	H[6][0] = "*";
	H[6][1] = " ";
	H[6][2] = " ";
	H[6][3] = " ";
	H[6][4] = "*";
	//======================================================================================================================
	//	Letter I
	char *I[7][5];
	I[0][0] = "*";
	I[0][1] = "*";
	I[0][2] = "*";
	I[0][3] = "*";
	I[0][4] = "*";
	I[1][0] = " ";
	I[1][1] = " ";
	I[1][2] = "*";
	I[1][3] = " ";
	I[1][4] = " ";
	I[2][0] = " ";
	I[2][1] = " ";
	I[2][2] = "*";
	I[2][3] = " ";
	I[2][4] = " ";
	I[3][0] = " ";
	I[3][1] = " ";
	I[3][2] = "*";
	I[3][3] = " ";
	I[3][4] = " ";
	I[4][0] = " ";
	I[4][1] = " ";
	I[4][2] = "*";
	I[4][3] = " ";
	I[4][4] = " ";
	I[5][0] = " ";
	I[5][1] = " ";
	I[5][2] = "*";
	I[5][3] = " ";
	I[5][4] = " ";
	I[6][0] = "*";
	I[6][1] = "*";
	I[6][2] = "*";
	I[6][3] = "*";
	I[6][4] = "*";
		//======================================================================================================================
	//	Letter J
	char *J[7][5];
	J[0][0] = "*";
	J[0][1] = "*";
	J[0][2] = "*";
	J[0][3] = "*";
	J[0][4] = "*";
	J[1][0] = " ";
	J[1][1] = " ";
	J[1][2] = " ";
	J[1][3] = " ";
	J[1][4] = "*";
	J[2][0] = " ";
	J[2][1] = " ";
	J[2][2] = " ";
	J[2][3] = " ";
	J[2][4] = "*";
	J[3][0] = " ";
	J[3][1] = " ";
	J[3][2] = " ";
	J[3][3] = " ";
	J[3][4] = "*";
	J[4][0] = " ";
	J[4][1] = " ";
	J[4][2] = " ";
	J[4][3] = " ";
	J[4][4] = "*";
	J[5][0] = "*";
	J[5][1] = " ";
	J[5][2] = " ";
	J[5][3] = " ";
	J[5][4] = "*";
	J[6][0] = " ";
	J[6][1] = "*";
	J[6][2] = "*";
	J[6][3] = "*";
	J[6][4] = " ";
	//======================================================================================================================
	//letter K
	char *K[7][5];
	K[0][0] = "*";
	K[0][1] = " ";
	K[0][2] = " ";
	K[0][3] = " ";
	K[0][4] = "*";
	K[1][0] = "*";
	K[1][1] = " ";
	K[1][2] = " ";
	K[1][3] = "*";
	K[1][4] = " ";
	K[2][0] = "*";
	K[2][1] = " ";
	K[2][2] = "*";
	K[2][3] = " ";
	K[2][4] = " ";
	K[3][0] = "*";
	K[3][1] = "*";
	K[3][2] = " ";
	K[3][3] = " ";
	K[3][4] = " ";
	K[4][0] = "*";
	K[4][1] = " ";
	K[4][2] = "*";
	K[4][3] = " ";
	K[4][4] = " ";
	K[5][0] = "*";
	K[5][1] = " ";
	K[5][2] = " ";
	K[5][3] = "*";
	K[5][4] = " ";
	K[6][0] = "*";
	K[6][1] = " ";
	K[6][2] = " ";
	K[6][3] = " ";
	K[6][4] = "*";
//======================================================================================================================
//	Letter L
	char *L[7][5];
	L[0][0] = "*";
	L[0][1] = " ";
	L[0][2] = " ";
	L[0][3] = " ";
	L[0][4] = " ";
	L[1][0] = "*";
	L[1][1] = " ";
	L[1][2] = " ";
	L[1][3] = " ";
	L[1][4] = " ";
	L[2][0] = "*";
	L[2][1] = " ";
	L[2][2] = " ";
	L[2][3] = " ";
	L[2][4] = " ";
	L[3][0] = "*";
	L[3][1] = " ";
	L[3][2] = " ";
	L[3][3] = " ";
	L[3][4] = " ";
	L[4][0] = "*";
	L[4][1] = " ";
	L[4][2] = " ";
	L[4][3] = " ";
	L[4][4] = " ";
	L[5][0] = "*";
	L[5][1] = " ";
	L[5][2] = " ";
	L[5][3] = " ";
	L[5][4] = " ";
	L[6][0] = "*";
	L[6][1] = "*";
	L[6][2] = "*";
	L[6][3] = "*";
	L[6][4] = "*";
//======================================================================================================================
	//letter M
	char *M[7][5];
	M[0][0] = "*";
	M[0][1] = " ";
	M[0][2] = " ";
	M[0][3] = " ";
	M[0][4] = "*";
	M[1][0] = "*";
	M[1][1] = "*";
	M[1][2] = " ";
	M[1][3] = "*";
	M[1][4] = "*";
	M[2][0] = "*";
	M[2][1] = " ";
	M[2][2] = "*";
	M[2][3] = " ";
	M[2][4] = "*";
	M[3][0] = "*";
	M[3][1] = " ";
	M[3][2] = " ";
	M[3][3] = " ";
	M[3][4] = "*";
	M[4][0] = "*";
	M[4][1] = " ";
	M[4][2] = " ";
	M[4][3] = " ";
	M[4][4] = "*";
	M[5][0] = "*";
	M[5][1] = " ";
	M[5][2] = " ";
	M[5][3] = " ";
	M[5][4] = "*";
	M[6][0] = "*";
	M[6][1] = " ";
	M[6][2] = " ";
	M[6][3] = " ";
	M[6][4] = "*";
    //======================================================================================================================
	//letter N
	char *N[7][5];
	N[0][0] = "*";
	N[0][1] = " ";
	N[0][2] = " ";
	N[0][3] = " ";
	N[0][4] = "*";
	N[1][0] = "*";
	N[1][1] = "*";
	N[1][2] = " ";
	N[1][3] = " ";
	N[1][4] = "*";
	N[2][0] = "*";
	N[2][1] = " ";
	N[2][2] = "*";
	N[2][3] = " ";
	N[2][4] = "*";
	N[3][0] = "*";
	N[3][1] = " ";
	N[3][2] = "*";
	N[3][3] = " ";
	N[3][4] = "*";
	N[4][0] = "*";
	N[4][1] = " ";
	N[4][2] = "*";
	N[4][3] = " ";
	N[4][4] = "*";
	N[5][0] = "*";
	N[5][1] = " ";
	N[5][2] = " ";
	N[5][3] = "*";
	N[5][4] = "*";
	N[6][0] = "*";
	N[6][1] = " ";
	N[6][2] = " ";
	N[6][3] = " ";
	N[6][4] = "*";
	//======================================================================================================================
	//	Letter O
	char *O[7][5];	
	O[0][0] = " ";
	O[0][1] = "*";
	O[0][2] = "*";
	O[0][3] = "*";
	O[0][4] = " ";
	O[1][0] = "*";
	O[1][1] = " ";
	O[1][2] = " ";
	O[1][3] = " ";
	O[1][4] = "*";
	O[2][0] = "*";
	O[2][1] = " ";
	O[2][2] = " ";
	O[2][3] = " ";
	O[2][4] = "*";
	O[3][0] = "*";
	O[3][1] = " ";
	O[3][2] = " ";
	O[3][3] = " ";
	O[3][4] = "*";
	O[4][0] = "*";
	O[4][1] = " ";
	O[4][2] = " ";
	O[4][3] = " ";
	O[4][4] = "*";
	O[5][0] = "*";
	O[5][1] = " ";
	O[5][2] = " ";
	O[5][3] = " ";
	O[5][4] = "*";
	O[6][0] = " ";
	O[6][1] = "*";
	O[6][2] = "*";
	O[6][3] = "*";
	O[6][4] = " ";
//======================================================================================================================
	//	Letter P
	char *P[7][5];
	P[0][0] = "*";
	P[0][1] = "*";
	P[0][2] = "*";
	P[0][3] = "*";
	P[0][4] = " ";
	P[1][0] = "*";
	P[1][1] = " ";
	P[1][2] = " ";
	P[1][3] = " ";
	P[1][4] = "*";
	P[2][0] = "*";
	P[2][1] = " ";
	P[2][2] = " ";
	P[2][3] = " ";
	P[2][4] = "*";
	P[3][0] = "*";
	P[3][1] = "*";
	P[3][2] = "*";
	P[3][3] = "*";
	P[3][4] = " ";
	P[4][0] = "*";
	P[4][1] = " ";
	P[4][2] = " ";
	P[4][3] = " ";
	P[4][4] = " ";
	P[5][0] = "*";
	P[5][1] = " ";
	P[5][2] = " ";
	P[5][3] = " ";
	P[5][4] = " ";
	P[6][0] = "*";
	P[6][1] = " ";
	P[6][2] = " ";
	P[6][3] = " ";
	P[6][4] = " ";
 //======================================================================================================================
	//	Letter Q
	char *Q[7][5];
	Q[0][0] = " ";
	Q[0][1] = "*";
	Q[0][2] = "*";
	Q[0][3] = "*";
	Q[0][4] = " ";
	Q[1][0] = "*";
	Q[1][1] = " ";
	Q[1][2] = " ";
	Q[1][3] = " ";
	Q[1][4] = "*";
	Q[2][0] = "*";
	Q[2][1] = " ";
	Q[2][2] = " ";
	Q[2][3] = " ";
	Q[2][4] = "*";
	Q[3][0] = "*";
	Q[3][1] = " ";
	Q[3][2] = " ";
	Q[3][3] = " ";
	Q[3][4] = "*";
	Q[4][0] = "*";
	Q[4][1] = " ";
	Q[4][2] = "*";
	Q[4][3] = " ";
	Q[4][4] = "*";
	Q[5][0] = " ";
	Q[5][1] = "*";
	Q[5][2] = "*";
	Q[5][3] = "*";
	Q[5][4] = " ";
	Q[6][0] = " ";
	Q[6][1] = " ";
	Q[6][2] = " ";
	Q[6][3] = " ";
	Q[6][4] = "*";
	//======================================================================================================================
	//	Letter R
	char *R[7][5];
	R[0][0] = "*";
	R[0][1] = "*";
	R[0][2] = "*";
	R[0][3] = "*";
	R[0][4] = " ";
	R[1][0] = "*";
	R[1][1] = " ";
	R[1][2] = " ";
	R[1][3] = " ";
	R[1][4] = "*";
	R[2][0] = "*";
	R[2][1] = " ";
	R[2][2] = " ";
	R[2][3] = " ";
	R[2][4] = "*";
	R[3][0] = "*";
	R[3][1] = "*";
	R[3][2] = "*";
	R[3][3] = "*";
	R[3][4] = " ";
	R[4][0] = "*";
	R[4][1] = " ";
	R[4][2] = " ";
	R[4][3] = "*";
	R[4][4] = " ";
	R[5][0] = "*";
	R[5][1] = " ";
	R[5][2] = " ";
	R[5][3] = " ";
	R[5][4] = "*";
	R[6][0] = " ";
	R[6][1] = " ";
	R[6][2] = " ";
	R[6][3] = " ";
	R[6][4] = " ";
//======================================================================================================================	
	//	Letter S
	char *S[7][5];
	S[0][0] = " ";
	S[0][1] = "*";
	S[0][2] = "*";
	S[0][3] = "*";
	S[0][4] = "*";
	S[1][0] = "*";
	S[1][1] = " ";
	S[1][2] = " ";
	S[1][3] = " ";
	S[1][4] = " ";
	S[2][0] = "*";
	S[2][1] = " ";
	S[2][2] = " ";
	S[2][3] = " ";
	S[2][4] = " ";
	S[3][0] = " ";
	S[3][1] = "*";
	S[3][2] = "*";
	S[3][3] = "*";
	S[3][4] = " ";
	S[4][0] = " ";
	S[4][1] = " ";
	S[4][2] = " ";
	S[4][3] = " ";
	S[4][4] = "*";
	S[5][0] = " ";
	S[5][1] = " ";
	S[5][2] = " ";
	S[5][3] = " ";
	S[5][4] = "*";
	S[6][0] = "*";
	S[6][1] = "*";
	S[6][2] = "*";
	S[6][3] = "*";
	S[6][4] = " ";
//======================================================================================================================
	//	Letter T
	char *T[7][5];
	T[0][0] = "*";
	T[0][1] = "*";
	T[0][2] = "*";
	T[0][3] = "*";
	T[0][4] = "*";
	T[1][0] = " ";
	T[1][1] = " ";
	T[1][2] = "*";
	T[1][3] = " ";
	T[1][4] = " ";
	T[2][0] = " ";
	T[2][1] = " ";
	T[2][2] = "*";
	T[2][3] = " ";
	T[2][4] = " ";
	T[3][0] = " ";
	T[3][1] = " ";
	T[3][2] = "*";
	T[3][3] = " ";
	T[3][4] = " ";
	T[4][0] = " ";
	T[4][1] = " ";
	T[4][2] = "*";
	T[4][3] = " ";
	T[4][4] = " ";
	T[5][0] = " ";
	T[5][1] = " ";
	T[5][2] = "*";
	T[5][3] = " ";
	T[5][4] = " ";
	T[6][0] = " ";
	T[6][1] = " ";
	T[6][2] = "*";
	T[6][3] = " ";
	T[6][4] = " ";
//======================================================================================================================
	//	Letter U
	char *U[7][5];
	U[0][0] = "*";
	U[0][1] = " ";
	U[0][2] = " ";
	U[0][3] = " ";
	U[0][4] = "*";
	U[1][0] = "*";
	U[1][1] = " ";
	U[1][2] = " ";
	U[1][3] = " ";
	U[1][4] = "*";
	U[2][0] = "*";
	U[2][1] = " ";
	U[2][2] = " ";
	U[2][3] = " ";
	U[2][4] = "*";
	U[3][0] = "*";
	U[3][1] = " ";
	U[3][2] = " ";
	U[3][3] = " ";
	U[3][4] = "*";
	U[4][0] = "*";
	U[4][1] = " ";
	U[4][2] = " ";
	U[4][3] = " ";
	U[4][4] = "*";
	U[5][0] = "*";
	U[5][1] = " ";
	U[5][2] = " ";
	U[5][3] = " ";
	U[5][4] = "*";
	U[6][0] = " ";
	U[6][1] = "*";
	U[6][2] = "*";
	U[6][3] = "*";
	U[6][4] = " ";
//======================================================================================================================
	//letter V
	char *V[7][5];
	V[0][0] = "*";
	V[0][1] = " ";
	V[0][2] = " ";
	V[0][3] = " ";
	V[0][4] = "*";
	V[1][0] = "*";
	V[1][1] = " ";
	V[1][2] = " ";
	V[1][3] = " ";
	V[1][4] = "*";
	V[2][0] = "*";
	V[2][1] = " ";
	V[2][2] = " ";
	V[2][3] = " ";
	V[2][4] = "*";
	V[3][0] = "*";
	V[3][1] = " ";
	V[3][2] = " ";
	V[3][3] = " ";
	V[3][4] = "*";
	V[4][0] = "*";
	V[4][1] = " ";
	V[4][2] = " ";
	V[4][3] = " ";
	V[4][4] = "*";
	V[5][0] = " ";
	V[5][1] = "*";
	V[5][2] = " ";
	V[5][3] = "*";
	V[5][4] = " ";
	V[6][0] = " ";
	V[6][1] = " ";
	V[6][2] = "*";
	V[6][3] = " ";
	V[6][4] = " ";
//======================================================================================================================
	//letter N
	char *W[7][5];
	W[0][0] = "*";
	W[0][1] = " ";
	W[0][2] = " ";
	W[0][3] = " ";
	W[0][4] = "*";
	W[1][0] = "*";
	W[1][1] = " ";
	W[1][2] = " ";
	W[1][3] = " ";
	W[1][4] = "*";
	W[2][0] = "*";
	W[2][1] = " ";
	W[2][2] = " ";
	W[2][3] = " ";
	W[2][4] = "*";
	W[3][0] = "*";
	W[3][1] = " ";
	W[3][2] = " ";
	W[3][3] = " ";
	W[3][4] = "*";
	W[4][0] = "*";
	W[4][1] = " ";
	W[4][2] = "*";
	W[4][3] = " ";
	W[4][4] = "*";
	W[5][0] = "*";
	W[5][1] = "*";
	W[5][2] = " ";
	W[5][3] = "*";
	W[5][4] = "*";
	W[6][0] = "*";
	W[6][1] = " ";
	W[6][2] = " ";
	W[6][3] = " ";
	W[6][4] = "*";
//======================================================================================================================	
	//letter X
	char *X[7][5];
	X[0][0] = "*";
	X[0][1] = " ";
	X[0][2] = " ";
	X[0][3] = " ";
	X[0][4] = "*";
	X[1][0] = "*";
	X[1][1] = " ";
	X[1][2] = " ";
	X[1][3] = " ";
	X[1][4] = "*";
	X[2][0] = " ";
	X[2][1] = "*";
	X[2][2] = " ";
	X[2][3] = "*";
	X[2][4] = " ";
	X[3][0] = " ";
	X[3][1] = " ";
	X[3][2] = "*";
	X[3][3] = " ";
	X[3][4] = " ";
	X[4][0] = " ";
	X[4][1] = "*";
	X[4][2] = " ";
	X[4][3] = "*";
	X[4][4] = " ";
	X[5][0] = "*";
	X[5][1] = " ";
	X[5][2] = " ";
	X[5][3] = " ";
	X[5][4] = "*";
	X[6][0] = "*";
	X[6][1] = " ";
	X[6][2] = " ";
	X[6][3] = " ";
	X[6][4] = "*";
	//======================================================================================================================	
//Letter Y
	char *Y[7][5];
	Y[0][0] = "*";
	Y[0][1] = " ";
	Y[0][2] = " ";
	Y[0][3] = " ";
	Y[0][4] = "*";
	Y[1][0] = "*";
	Y[1][1] = " ";
	Y[1][2] = " ";
	Y[1][3] = " ";
	Y[1][4] = "*";
	Y[2][0] = " ";
	Y[2][1] = "*";
	Y[2][2] = " ";
	Y[2][3] = "*";
	Y[2][4] = " ";
	Y[3][0] = " ";
	Y[3][1] = " ";
	Y[3][2] = "*";
	Y[3][3] = " ";
	Y[3][4] = " ";
	Y[4][0] = " ";
	Y[4][1] = " ";
	Y[4][2] = "*";
	Y[4][3] = " ";
	Y[4][4] = " ";
	Y[5][0] = " ";
	Y[5][1] = " ";
	Y[5][2] = "*";
	Y[5][3] = " ";
	Y[5][4] = " ";
	Y[6][0] = " ";
	Y[6][1] = " ";
	Y[6][2] = "*";
	Y[6][3] = " ";
	Y[6][4] = " ";
//======================================================================================================================
	//letter Z
	char *Z[7][5];
	Z[0][0] = "*";
	Z[0][1] = "*";
	Z[0][2] = "*";
	Z[0][3] = "*";
	Z[0][4] = "*";
	Z[1][0] = " ";
	Z[1][1] = " ";
	Z[1][2] = " ";
	Z[1][3] = " ";
	Z[1][4] = "*";
	Z[2][0] = " ";
	Z[2][1] = " ";
	Z[2][2] = " ";
	Z[2][3] = "*";
	Z[2][4] = " ";
	Z[3][0] = " ";
	Z[3][1] = " ";
	Z[3][2] = "*";
	Z[3][3] = " ";
	Z[3][4] = " ";
	Z[4][0] = " ";
	Z[4][1] = "*";
	Z[4][2] = " ";
	Z[4][3] = " ";
	Z[4][4] = " ";
	Z[5][0] = "*";
	Z[5][1] = " ";
	Z[5][2] = " ";
	Z[5][3] = " ";
	Z[5][4] = " ";
	Z[6][0] = "*";
	Z[6][1] = "*";
	Z[6][2] = "*";
	Z[6][3] = "*";
	Z[6][4] = "*";
	for(int i = 0; i< strlen(assignment); i++) {
	 	switch(assignment[i]){
		 	case 'A':
	 	    Sleep(1000);
			printing(A);
		break;
		case 'B':
			Sleep(1000);
			printing(B);
		break;
		case 'C':
			Sleep(1000);
			printing(C);
		break;
		case 'D':
			Sleep(1000);
			printing(D);
		break;
		case 'E':
			Sleep(1000);
			printing(E);
		break;
		case 'F':
			Sleep(1000);
			printing(F);
		break;
		case 'G':
			Sleep(1000);
			printing(G);
		break;
		case 'H':
			Sleep(1000);
			printing(H);
		break;
		case 'I':
			Sleep(1000);
			printing(I);
		break;
		case 'J':
			Sleep(1000);
			printing(J);
		break;
		case 'K':
			Sleep(1000);
			printing(K);
		break;
		case 'L':
			Sleep(1000);	
			printing(L);
		break;
		case 'M':
			Sleep(1000);	
			printing(M);
		break;
		case 'N':
			Sleep(1000);
			printing(N);
		break;
		case 'O':
			Sleep(1000);
			printing(O);
		break;
		case 'P':
			Sleep(1000);
			printing(P);
		break;
		case 'Q':
			Sleep(1000);
			printing(Q);
		break;
		case 'R':
			Sleep(1000);
			printing(R);
		break;
		case 'S':
			Sleep(1000);
			printing(S);
		break;
		case 'T':
			Sleep(1000);
			printing(T);
		break;
		case 'U':
			Sleep(1000);
			printing(U);
		break;
		case 'V':
			Sleep(1000);
			printing(V);
		break;
		case 'W':
			Sleep(1000);
			printing(W);
		break;
		case 'X':
			Sleep(1000);
			printing(X);
		break;
		case 'Y':
			Sleep(1000);
			printing(Y);
		break;
		case 'Z':
			Sleep(1000);
			printing(Z);
		break;
		default:
			exit(1);
		}
	 }
	  printf("\n=====================================================================================\n");
}

//printing characters after assignment
      void printing(char *letter[7][5]) {
		for(int i = 0; i<7; i++) {
		for(int j = 0; j<5; j++) {
			printf("%s",letter[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
//getting month in number format
char* getMonth(char *month){	
    	if(strcmp(month,"Jan")==0){
			return "01";
	}
	else if(strcmp(month,"Feb")==0){
			return "02";
	}
	else if(strcmp(month,"Mar")==0){
			return "03";
	}
	else if(strcmp(month,"Apr")==0){
			return "04";
	}
	else if(strcmp(month,"May")==0){
			return "05";
	}
	else if(strcmp(month,"Jun")==0){
			return "06";
	}
	else if(strcmp(month,"Jul")==0){
			return "07";
	}
	else if(strcmp(month,"Aug")==0){
			return "08";
	}
	else if(strcmp(month,"Sep")==0){
			return "09";
	}
	else if(strcmp(month,"Oct")==0){
			return "10";
	}
	else if(strcmp(month,"Nov")==0){
			return "11";
	}
	else{
			return "12";
	}
}
//getting date in database format
char* getDate(char *str){
	char day[3];
   char month[10];
   char year[10];
   strncpy(day,str+8,2);
   strncpy(month,str+4,3);
   strncpy(year,str+20,4);
   char month_number[10];
   strcpy(month_number,getMonth(month));
   static char currentDate[15];
   strcat(currentDate,year);
   strcat(currentDate,"-");
   strcat(currentDate,month_number);
   strcat(currentDate,"-");
   strcat(currentDate,day);
   return currentDate;
}
//getting time in database format
char* getTime(char *str){
	static char currentTime[10];
	strncpy(currentTime,str+11,8);
	return currentTime;
}
//getting the assignment after entering assignmentId
char* getSelectedAssign(int assignmentId) {
	    MYSQL_ROW record;
    	MYSQL *conn = mysql_init(NULL);
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
	    char query2[300];
		sprintf(query2,"SELECT assignment FROM asssignmentdetails WHERE assignmentId = %d",assignmentId);
		if(mysql_query(conn,query2)){
			errors(conn);
		}
		MYSQL_RES* rs = mysql_store_result(conn);
		static char assignment_string[9];
		record = mysql_fetch_row(rs);
		strcpy(assignment_string,record[0]);
		mysql_free_result(rs);
		mysql_close(conn);	
		return assignment_string;
}
//inserting the score into scores table
        void insertScore(char* usercode,int assignmentId,int score,float time) {
		MYSQL_ROW record;
    	MYSQL *conn = mysql_init(NULL);
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
		char query3[300];
		sprintf(query3,"INSERT INTO scores (assignmentId,userCode,marks,timeTaken)  VALUES ('%d','%s',%d,%f)",assignmentId,usercode,score,time);
		if(mysql_query(conn,query3)){
			errors(conn);
		}  
		Sleep(1000); 
		puts("\nYour score has successfully been uploaded");
		mysql_close(conn);	
}
//getting assignments in a certain range of date
         void assignments_in_range() {
	        char toDate[10];
            char fromDate[15];
    	   	printf("Enter the 'from' date,format[(YYYY-MM-DD)]:"); 
    	   	scanf("%s",fromDate);
    	   	printf("Enter the 'to' date,format[(YYYY-MM-DD)]:"); 
    	   	scanf("%s",toDate);
		MYSQL *conn = mysql_init(NULL);
    	MYSQL_ROW record;
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
		char query[300];
        sprintf(query,"SELECT * FROM asssignmentDetails WHERE expiryDate BETWEEN '%s' AND '%s' ",fromDate,toDate);
		if(mysql_query(conn,query)){
			errors(conn);
		}
		printf("-----------------------------------------------\n");
        printf("|Assignments between %s and %s|\n",fromDate,toDate);
        printf("-----------------------------------------------\n");
		MYSQL_RES* rs = mysql_store_result(conn);	
	    printf("Assignmentid Characters\t\t\t Exp. date \t\tExp. time\n");
	    int num_rows = mysql_num_rows(rs);
	    if(num_rows == 0) {
	     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED| FOREGROUND_INTENSITY);
	    	printf("No assignments in the date range\n");
	    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_INTENSITY);
		}
		else {
			   while(record = mysql_fetch_row(rs)) {
			int characters = strlen(record[1]);
			printf("%s\t\t %d\t\t\t %s\t\t %s\n", record[0],characters,record[2],record[3]);			
		}
		}	 
		printf("\n\n");
}
//calling functions which implements the requirements of checkstatus command
     void Checkstatus(char* usercode) {
     int getAttempted_number =  getAttempted(usercode);
     int assignmentTotal = Assignments();
     Sleep(1000);
     getAVG(usercode);
     Sleep(1000);
     float percentageAttempted = (getAttempted_number*100)/assignmentTotal;
     printf("Percentage attempted:%.2f\n\n",percentageAttempted);
     Sleep(1000);
}
//getting attempted assignments from scores table and for returning attempted assignments as well
       int  getAttempted(char* usercode) {
		MYSQL_ROW record;
    	MYSQL *conn = mysql_init(NULL);
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
        char query1[300];
		sprintf(query1,"SELECT COUNT(*) FROM scores WHERE userCode = '%s'",usercode);
		if(mysql_query(conn,query1)){
			errors(conn);
		}	
	    MYSQL_RES* rs = mysql_store_result(conn);
	    if(rs == NULL){
	      errors(conn);
		}
		record = mysql_fetch_row(rs);
		printf("\nTotal attempted assignments:%s\n\n",record[0]);
		int attempted = atoi(record[0]);	
		mysql_free_result(rs);
		mysql_close(conn);
		return attempted;
}
void getAVG(char* usercode) {
	MYSQL_ROW record;
    	MYSQL *conn = mysql_init(NULL);
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
        char query1[300];
		sprintf(query1,"SELECT AVG(marks) FROM scores WHERE userCode = '%s'",usercode);
		if(mysql_query(conn,query1)){
			errors(conn);
		}	
	    MYSQL_RES* rs = mysql_store_result(conn);
	    if(rs == NULL){
	      errors(conn);
		}
		record = mysql_fetch_row(rs);
		printf("Your average marks from attempted assignments:%s\n\n",record[0]);	
		mysql_free_result(rs);
		mysql_close(conn);
}
     void unAttempted_assignments(char *usercode){
     MYSQL *conn = mysql_init(NULL);
     MYSQL_ROW record;
      if (conn == NULL)
     {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
     }
       conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
     char query[300];
     sprintf(query,"SELECT * FROM asssignmentdetails WHERE assignmentId NOT IN(SELECT assignmentId  FROM scores where userCode= '%s')",usercode);
     if (mysql_query(conn, query))
     {
      errors(conn);
   }
   MYSQL_RES *rs = mysql_store_result(conn);
    if (rs == NULL)
  {
      errors(conn);
  }
//  printf("-----------------------------\n");
//  printf("|The Unattempted assignments|\n");
//  printf("-----------------------------\n\n");
  Sleep(1000);
  printf("Assignmentid Characters\t\t\t date \t\t\t time\n");
 int num_rows = mysql_num_rows(rs);
	    if(num_rows == 0) {
	     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_INTENSITY);
	    	printf("No assignments in the date range\n");
	    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_INTENSITY);
		}
		else {
			while (record = mysql_fetch_row(rs))  {
  	        int characters = strlen(record[1]);
             printf("%s\t\t %d\t\t\t %s\t\t %s\n", record[0],characters,record[2],record[3]);
      }
	}
    mysql_free_result(rs);
    mysql_close(conn);
}

   void Viewall(char *usercode){
   MYSQL *conn = mysql_init(NULL);
   MYSQL_ROW record;
  if (conn == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }
       conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
  char query[300];
  sprintf(query,"SELECT asssignmentDetails.assignmentId, asssignmentDetails.expiryDate, asssignmentDetails.expiryTime, scores.marks, scores.timeTaken FROM asssignmentDetails LEFT JOIN scores ON asssignmentDetails.assignmentId = scores.assignmentId WHERE scores.Usercode = '%s'",usercode);
  if (mysql_query(conn, query))
  {
      errors(conn);
  }

  MYSQL_RES *rs = mysql_store_result(conn);

  if (rs == NULL)
  {
      errors(conn);
  }
  printf("-----------------------\n");
  printf("|Attempted Assignments|\n");
  printf("-----------------------\n");
  Sleep(1000);
  printf("Assignmentid\t date\t\t\t\t time\t\t\tmarks \t\t timeTaken\n");
  while (record = mysql_fetch_row(rs))
  {
     printf("%s\t\t %s\t\t\t %s\t\t %s \t\t%s\n", record[0],record[1],record[2],record[3],record[4]);
  }
  Sleep(1500);
  printf("\n\n");
  printf("-----------------------------\n");
  printf("|The Unattempted assignments|\n");
  printf("-----------------------------\n\n");
  unAttempted_assignments(usercode);
  mysql_free_result(rs);
  mysql_close(conn);
}
void Viewassignment() {
	    int assignmentId;
	    printf("Please enter the assignment ID: ");
	    scanf("%d",&assignmentId);
	    MYSQL_ROW record;
    	MYSQL *conn = mysql_init(NULL);
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
	    char query2[300];
		sprintf(query2,"SELECT * FROM asssignmentdetails WHERE assignmentId = %d",assignmentId);
		if(mysql_query(conn,query2)){
			errors(conn);
		}
		printf("\n------------------------\n");
        printf("|AssignmentID %d details|\n",assignmentId);
        printf("------------------------\n\n");	
		MYSQL_RES* rs = mysql_store_result(conn);
		int num_rows = mysql_num_rows(rs);
		if(num_rows == 0) {
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED| FOREGROUND_INTENSITY);
			puts("No assignment found");
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN| FOREGROUND_INTENSITY);
		}
		else{
		printf("Assignmentid Characters\t\t\t date \t\t\t time\n");
		record = mysql_fetch_row(rs);
		int characters = strlen(record[1]);
		printf("%s\t\t %d\t\t\t %s\t\t %s\n\n", record[0],characters,record[2],record[3]);	
		}
				
		mysql_free_result(rs);
		mysql_close(conn);	
}
        char* getRemainingDays(char* date, char* expiryDate) {
        MYSQL_ROW record;
        MYSQL *conn = mysql_init(NULL);
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
	    char query[300];
		sprintf(query,"SELECT DATEDIFF('%s', '%s') AS DateDiff;",expiryDate,date);
		if(mysql_query(conn,query)){
			errors(conn);
		}
		MYSQL_RES* rs = mysql_store_result(conn);
		static char days[5];
		record = mysql_fetch_row(rs);		
		strcpy(days,record[0]);
		mysql_free_result(rs);
		mysql_close(conn);	
        return days;
}
//for retrieving comments
     void viewComments(char* usercode) {
	    MYSQL_ROW record;
    	MYSQL *conn = mysql_init(NULL);
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) {
	    	errors(conn);
		}
	    char query2[300];
		sprintf(query2,"SELECT assignmentId, marks, comment FROM scores WHERE userCode = '%s'",usercode);
		if(mysql_query(conn,query2)){
			errors(conn);
		}
		printf("\n---------------------------------\n");
        printf("|Attempted assignments' comments|\n");
        printf("---------------------------------\n\n");	
		MYSQL_RES* rs = mysql_store_result(conn);	
		int num_rows = mysql_num_rows(rs);
		if(num_rows == 0) {
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED| FOREGROUND_INTENSITY);
			printf("No assignments to comment yet\n");
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN| FOREGROUND_INTENSITY);
		}
		else {
		printf("Assignmentid \t\tmarks\t\t  comment\n");
		while(record = mysql_fetch_row(rs)) {
		  printf("%s\t\t\t %s\t\t", record[0],record[1]);
		  if(strcmp(record[2],"") == 0){
		  	 printf("[No comment yet]\n");
		  }
		 else {      
		 	printf("%s\t\n",record[2]);	
		 }		
		}	
      }
        mysql_free_result(rs);
      	mysql_close(conn);	
  }
        int attemptable_assignments(char* usercode){
		MYSQL *conn = mysql_init(NULL);
    	MYSQL_ROW record;
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) { 
	    	errors(conn);
		}
		time_t t;
      	time(&t);
        char time_string[35];	
	    sprintf(time_string,ctime(&t));
	    char dateToday[15];
	    char timeNow[15];
	    strcpy(dateToday,getDate(time_string));
	    strcpy(timeNow,getTime(time_string));
	    char query[300];
	    sprintf(query,"SELECT COUNT(*) FROM asssignmentdetails WHERE (expiryDate >'%s' OR (expiryDate = '%s' AND expiryTime>'%s')) AND (assignmentId NOT IN (SELECT assignmentId FROM scores where userCode= '%s'));",dateToday,dateToday,timeNow,usercode);
		if(mysql_query(conn,query)){
			errors(conn);
		}
		MYSQL_RES* rs = mysql_store_result(conn);
		record = mysql_fetch_row(rs);
		int Assignment = atoi(record[0]) - 1;
//		printf(">>>>%d\n",Assignment);   
		mysql_free_result(rs);
		return Assignment;
		}
		//for returning the number of assignments to be used to calculate %attempted and %unattempted.
        int Assignments() {
     	MYSQL *conn = mysql_init(NULL);
    	MYSQL_ROW record;
    	if(conn == NULL){
    		fprintf(stderr,"mysql_init() failed\n");
    		exit(1);
		}
	    conn = mysql_real_connect(conn,"127.0.0.1","root","","kindercare",3306,NULL,0);
	    if(conn == NULL) { 
	    	errors(conn);
		}
		time_t t;
      	time(&t);
        char time_string[35];	
	    sprintf(time_string,ctime(&t));
	    char dateToday[15];
	    char timeNow[15];
	    strcpy(dateToday,getDate(time_string));
	    strcpy(timeNow,getTime(time_string));
	    char query[300];
	    sprintf(query,"SELECT COUNT(*) FROM asssignmentdetails");
		if(mysql_query(conn,query)){
			errors(conn);
		}
		MYSQL_RES* rs = mysql_store_result(conn);
		record = mysql_fetch_row(rs);
		return atoi(record[0]);	
	 }
	 
