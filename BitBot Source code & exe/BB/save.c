#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
char* randomstr(char *s1[]){
	int n=0;
	while(s1[n]!='\0'){
		n++;
	}
	srand(time(NULL));
	int index=rand()%n;
	return s1[index];
}
void hang(int count){
    
	printf("\n\n\n");
	switch(count){
        case 1:
            printf("                                 / \\__                                               \n");
            printf("                                (    @\\___                                         O  \n");
            printf("                                /         O                                       /|\\\n");
            printf("                              /   (_____/                                         / \\\n");
            printf("                              ___                                                     \n");
            break;
		case 2:
			printf("                                       / \\__                                         \n");
            printf("                                      (    @\\___                                   O  \n");
            printf("                                      /         O                                 /|\\\n");
            printf("                                    /   (_____/                                   / \\\n");
            printf("                                    ___                                               \n");
            break;
        case 3:
            printf("                                              / \\__                                  \n");
            printf("                                             (    @\\___                            O  \n");
            printf("                                             /         O                          /|\\\n");
            printf("                                           /   (_____/                            / \\\n");
            printf("                                          /___                                        \n");
            break;
        case 4:
            printf("                                                   / \\__                             \n");
            printf("                                                  (    @\\___                       O  \n");
            printf("                                                  /         O                     /|\\\n");
            printf("                                                /   (_____/                       / \\\n");
            printf("                                               /___                                   \n");
            break;
        case 5:
            printf("                                                        / \\__                        \n");
            printf("                                                       (    @\\___                  O  \n");
            printf("                                                       /         O                /|\\\n");
            printf("                                                     /   (_____/                  / \\\n");
            printf("                                                    /___                              \n");
            break;
        case 6:
            printf("                                                               / \\__                  \n");
            printf("                                                              (    @\\___            O  \n");
            printf("                                                              /         O          /|\\\n");
            printf("                                                            /   (_____/            / \\\n");
            printf("                                                           /___                        \n");
            break;
        case 7:
            printf("                                                                     / \\__          \n");
            printf("                                                                    (    @\\___   O  \n");
            printf("                                                                    /         O \\|/ \n");
            printf("                                                                   /   (_____/  / \\ \n");
            printf("                                                                 /___                \n");
            break;
	}
}
void save_kid()
{
	printf("Welcome to Save The Kid Game..\n\n");
	printf("Rules:-\n\n");
	printf("-->You're given a random word in blanks and you need to guess the word.\n\n");
	printf("-->You have atmost 7 chances to save the kid form DOG\n");
    printf("\n");
    printf("                               / \\__                                           \n");
    printf("                              (    @\\___                                     O  \n");
    printf("                              /         O                                   /|\\\n");
    printf("                            /   (_____/                                     / \\\n");
    printf("                           /___                                                 \n");
    printf("\n");
    printf("Don't enter the same character twice).\n\n");
	char *s[]={"mango", "plum", "orange", "grape", "rose","melon",NULL};
	char *r;
	r=randomstr(s);
//	printf("%s",r);
    char a[50];
    strcpy(a,r);
    char a1[50];
    strcpy(a1,a);
//	printf("%s",a);
    int i;
    for(i=0;a[i]!='\0';i++){
    	a[i]='_';
	}
	a[i]='\0';
	printf("Your word is...\n\n");
	for(i=0;a[i]!='\0';i++){
	printf("%c",a[i]);
    }
	printf("\n\n(Hint:The first letter of the word is: \"%c\")",a1[0]);
    int count=0,flag=0,flag1=0;
    char c;
    while(1){
    	printf("\n\nEnter character\n\n");
    	scanf("%c",&c);
    	getchar();
    	flag1=0;
    	for(i=0;a[i]!='\0';i++){
    		if(c==a1[i]){
    			flag1=1;
    			a[i]=c;
    			break;
			}
		}
		if(flag1!=1){
			count++;
			hang(count);
			if(count>6){
				printf("You lost.The correct word was: %s\n\n",a1);
				break;
			}
		}
		flag=0;
	    for(i=0;a[i]!='\0';i++){
		if(a[i]==a1[i]){
			flag++;
		}
	}
	if(flag==strlen(a1)){
		printf("%s\n\n",a);
		printf("Hurrayy!!\n\n");
        printf("          _       ____            \n");
        printf("         / \\     |___|            \n");
        printf("   ^   (   @\\___   | 0            \n");
        printf("  /_\\  /        O  |/|\\          \n");
        printf(" /   \\(________/    / \\          \n");
        printf("/_____/ U\n");
        printf("\n\n");
		printf("You won\n\n");
		break;
	}
	printf("%s\n\n",a);
  }
	//return 0;
	//gamemain();
}