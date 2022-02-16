        #include<stdio.h>
        #include <string.h>
        #include <time.h>
        char* getDate(char *str);
        char* getTime(char *str);
        char* getMonth(char *month);
        int main () {
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
	    sprintf(query,"SELECT * FROM asssignmentdetails WHERE expiryDate >='%s' OR (expiryDate = '%s' AND expiryTime>'%s' );",dateToday,dateToday,timeNow);
	    puts(query);
		}
		
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