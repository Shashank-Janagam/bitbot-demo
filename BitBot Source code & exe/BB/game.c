#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<windows.h>
char loginID[50];
const char *game(int r)
{
	const char *s;
	if(r>=0 && r<33){
		s="rock";
	}
	if(r>=33 && r<66){
		s="paper";
	}
	if(r>=66 && r<100){
	  s="scissors";
	}
	return s;
}

void setdire(){
    char currentDirectory[MAX_PATH];

    // Get the current directory
    DWORD result = GetCurrentDirectoryA(MAX_PATH, currentDirectory);
    if (result == 0) {
        fprintf(stderr, "Error getting current directory\n");
        
    }

    // Find the last backslash in the current directory path
    char *lastBackslash = strrchr(currentDirectory, '\\');
    if (lastBackslash == NULL) {
        fprintf(stderr, "Error: Current directory is the root directory\n");
        
    }

    // Null-terminate the path at the last backslash to truncate to the parent directory
    *lastBackslash = '\0';
    // Set the parent directory as the current directory
    if (!SetCurrentDirectoryA(currentDirectory)) {
        fprintf(stderr, "Error setting parent directory as current directory\n");
        
    }
}

void gamemain()
{
	char store[20];
    FILE *fname;
    fname=fopen("name","r");
    fscanf(fname, "%99s", store);
    sprintf(loginID,"%s@travasso.com",strlwr(store));
    printf("%s",loginID);
	char s1[30],count=0,count1=0;
	printf("Welcome..\n\n");
	printf("Rules:-\n\n1.For your every victory in the game,your score increases by 1\n\n");
	printf("2.And your score decreases by 1,if you lose\n\n");
	printf("3.It remains unchanged incase if it is a tie\n\n");
	printf("4.Enter \"exit\" to exit the game\n\n");
	printf("5.Enter \"start\" to start the game\n\n");
	char s2[30];
	scanf("%s",s2);
	for(int i=0;s2[i]!='\0';i++){
		s2[i]=tolower(s2[i]);
	}
	if(strcmp(s2,"start")==0){
	while(1){
	printf("Enter Rock ,Paper or Scissors\n\n");
	printf("You: ");
	scanf("%s",s1);
	for(int i=0;s1[i]!='\0';i++){
		s1[i]=tolower(s1[i]);
	}
	if(strcmp(s1,"exit")==0){
		printf("Game finished\n\n");
	    break;
   }
	srand(time(NULL));
	int r=rand()%100;
	const char *res=game(r);
	printf("\nComputer: %s\n\n",res);
	if(strcmp(res,s1)==0){
		printf("Tie\n");
	}
	if(strcmp(res,"rock")==0 && strcmp(s1,"scissors")==0){
		printf("You lost\n\n");
		
		count1++;
	}
	if(strcmp(res,"rock")==0 && strcmp(s1,"paper")==0){
		printf("You won\n\n");
		count++;
	}
	if(strcmp(res,"scissors")==0 && strcmp(s1,"rock")==0){
		printf("You won\n\n");
		count++;
	}
	if(strcmp(res,"scissors")==0 && strcmp(s1,"paper")==0){
		printf("You lost\n\n");
		
		count1++;
	}
	if(strcmp(res,"paper")==0 && strcmp(s1,"scissors")==0){
		printf("You won\n\n");
		count++;
	}
	if(strcmp(res,"paper")==0 && strcmp(s1,"rock")==0){
		printf("You lost\n\n");
		count1++;
	}
   }
  }
  printf("Your score -\n%d\n\n",count);
  printf("Computer's score -\n%d\n\n",count1);
  if(count1>count){
  	printf("Sorry!But well played(:\n\n");
  }
  else if(count>count1){

  	printf("You're a Champ!!\n\n");
	setdire();
	FILE*fp=fopen("highscoor1","r");
	int highscoor;
  	fscanf(fp, "%d",&highscoor);
	// printf("hih-%d",highscoor);
	if(count>highscoor){
	fp=fopen("highscoor1","w");
	printf("\nWOW...! You bet the Highscoor\n");
	fprintf(fp,"%d\n",count);
	fclose(fp);
	if(!SetCurrentDirectoryA(loginID))
	printf("Error");
  }
  
}
else if(count1==count){
  	printf("It's a deadlock!No winner this round\n\n");
  }
}