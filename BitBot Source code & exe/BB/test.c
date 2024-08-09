#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#include<dirent.h>
#include<time.h>
void welcometest(){
    system("cls");
        printf("\033[32m");
    printf("\r" "-------------------------------");
    printf("\033[1m");
    printf("TRAVASSO's TypePro");
    printf("-------------------------------\n");
    printf("\033[0m");
}
char loginID[50];
void readuser(char *acc,char line[]) {
    int maxLength=strlen(line);
    int i = 0;
    char ch;
    printf("\n                      ");
  while (i < maxLength-1 && (ch = _getch()) != '\r') {
        if (ch == '\b' && i > 0){
            printf("\b \b");
            i--;
        } else if(ch==line[i]){
            printf("\033[32m%c\033[0m",ch);//green
            acc[i]=ch;
            i++;
        }else{
            printf("\033[31m%c\033[0m",ch);//red
            acc[i]=ch;
            i++;
        }
    }
    
    if(i!=maxLength-1){
        printf(" Wromg sentence");
        return;
    }
    line[i]='\0';
    getchar();
    acc[i] = '\0';
}
void test(){

    char store0[20];
    FILE *fname;
    fname=fopen("name","r");
    fscanf(fname, "%99s", store0);
    char sname[20];
    strcpy(sname,store0);
    sprintf(loginID,"%s@travasso.com",strlwr(store0));
    // printf("%s",loginID);
    setdir();
    FILE *fp1=fopen("Speed Test Scoor","r");
	int highscoor;
  	fscanf(fp1, "%d",&highscoor);
    char highname[100];
    fscanf(fp1,"%s",highname);
    welcometest();
    printf("\033[1m\033[32m                            Highscore is %d by %s\033[0m\033[0m\n\n",highscoor,highname);
    printf("                                                         Try to beat it\n");

     printf("\033[1;33m");
    printf("\n\n                                         Heylooo...\n\n");
    printf("                           This is just a test for your typing script\n\n");
    printf("                       Just type the sentence given for you in white colour\n\n");
    printf("            Your correctly typed characters will be displayed in green and errors in red\n\n");
    printf("                                  Type Enter to start the Test.");
    printf("\033[0m");
    getche();
    welcometest();
FILE *fp;
fp=fopen("text.txt", "r");
int count_lines=1;
char cha;
if(fp==NULL){
        printf(RED"                                              Error opening the file\n");
        exit(1);
    }
   
        while((cha=fgetc(fp))!=EOF){
            if(cha=='\n'){
                count_lines++;
            }
        }
    rewind(fp);
    char line[1024];
    if(fp==NULL){
        printf("Error");
    }
    else{
        srand(time(NULL));
        int rand_num=rand()%count_lines;
        int count_line=0;
        while((fgets(line,1024,fp))!=NULL){
            if(count_line==rand_num){
                break;
            }
            count_line++;
        }
    }
    rewind(fp);
    // for(int i=0;i<strlen(line);i++){
    //     if(line[i]=='\n' || line[i]==' '){
    //         printf("%c",line[i]);
    //     }
    //     else{
    //         printf("\033[37m%c\033[0m",line[i]);//white
    //     }
    // }
    printf("                       %s",line);
    // printf("\r");
    printf(BHYEL"\n          Start typing:");
    // printf("                      ");
    //rewind(fp1);
    time_t start_time;
    time(&start_time);
    // printf("\n\033[35mStart: %s\033[0m\n",ctime(&start_time));
    char ch;
    int count=0;
    int count1=0;
    int i=0;
    
    // char line2[100];
    // strcpy(line2,line);
    time(&start_time);
//  int cout=strlen(line2);
    char acc[strlen((line))+1];
    readuser(acc,line);
    // printf("\n");
    welcometest();
    // printf("%s",acc);
    // line2[strlen(line2)-1]='\0';
    if(strcmp(acc,line)!=0){
        welcometest();
        printf(RED"\n\n\n\n\n                                  Wrong Sentence...Try again later\n");
        // printf("%s",acc,strlen(acc));
        // printf("\n%s",line);
        if(!SetCurrentDirectoryA(loginID))
	    printf("Error going to userid");
        return;
    }
    
    time_t end_time;
    time(&end_time);
    // printf("\n\033[35mEnd: %s\033[0m\n",ctime(&end_time));
    int restime=difftime(end_time,start_time);
    printf("\033[36m");
    printf(BHGRN"\n\n\n\n                                    Time taken: %d sec\n\n",restime);
    int score;
    // printf("Line lenght=%d",strlen(line));
    score=100-restime;
    
    printf(BHGRN"                                  Overall Score: \"%d\"\033[0m\n\n",score);
    fclose(fp); 

	if(score>highscoor){
	fp1=fopen("Speed Test Scoor","w");
	printf(BHGRN"\n\n                                       WOW...! You bet the Highscore\n");
	fprintf(fp1,"%d\n",score);
    fprintf(fp1,"%s\n",sname);
	fclose(fp1);
    }
     if(!SetCurrentDirectoryA(loginID))
     
	printf(RED"Error going to userid");
	

    // return 0;


    
}

