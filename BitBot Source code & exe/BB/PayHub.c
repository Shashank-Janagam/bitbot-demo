#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define RES "\033[0m"
#define BGRN "\e[1;32m"

#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"
char loginID[50];
struct start_date{
    int year;
    int month;
    int day;
};
struct deposite {
    int amount;
    int tenure;
    struct start_date date;
}ch;
void welcomepay(){
    system("cls");
        printf("\033[32m");
    printf("\r" "-------------------------------");
    printf("\033[1m");
    printf("Travasso's PayHub");
    printf("-------------------------------\n");
    printf("\033[0m");
}
void setdir(){
    char currentDirectory[MAX_PATH];

    
    DWORD result = GetCurrentDirectoryA(MAX_PATH, currentDirectory);
    if (result == 0) {
        fprintf(stderr, "Error getting current directory\n");
        
    }

    
    char *lastBackslash = strrchr(currentDirectory, '\\');
    if (lastBackslash == NULL) {
        fprintf(stderr, "Error: Current directory is the root directory\n");
        
    }

    
    *lastBackslash = '\0';
    
    if (!SetCurrentDirectoryA(currentDirectory)) {
        fprintf(stderr, "Error setting parent directory as current directory\n");
        
    }
}
void change(int balance){
    if(!SetCurrentDirectoryA(loginID))
    printf("Error...");
    FILE *fp=fopen("savings.txt","w");
    fprintf(fp,"%d",balance);
    printf(BHGRN"                         Remaining Balance :$%d\n"RES,balance);
    fclose(fp);

}
void changedipo(int balance){
    FILE *fp=fopen("savings.txt","w");
    fprintf(fp,"%d",balance);
    // printf("Remaining Balance :$%d\n",balance);
    fclose(fp);

}
void read2(char *acc, int maxLength) {
    int i = 0;
    char ch;
    maxLength++;
  while (i < maxLength - 1 && (ch = _getch()) != '\r') {
        if (ch == '\b' && i > 0) {
            printf("\b \b");
            i--;
        } else {
            acc[i++] = ch;
            printf("%c",ch);
        }
    }
    acc[i] = '\0';
}
void readPassword(char *password, int maxLength) {
    int i = 0;
    char ch;
  while (i < maxLength - 1 && (ch = _getch()) != '\r') {
        if (ch == '\b' && i > 0) {
            printf("\b \b");
            i--;
        } else {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
}

int isMatured(struct deposite fd) {
    struct start_date current_date;

    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    current_date.year = tm_struct->tm_year + 1900;  
    current_date.month = tm_struct->tm_mon + 1;     
    current_date.day = tm_struct->tm_mday;          
    int maturity_year = fd.date.year + fd.tenure;
    int maturity_month = fd.date.month;
    int maturity_day = fd.date.day;
    if (current_date.year > maturity_year ||
        (current_date.year == maturity_year && current_date.month > maturity_month) ||
        (current_date.year == maturity_year && current_date.month == maturity_month && current_date.day >= maturity_day)) {
        return ((current_date.year-fd.date.year)*fd.amount*6.5/100)+fd.amount;
    } else {
        return 0;
    }
}

int returnbalance(){
    setdir();
    FILE*saving=fopen("savings.txt","r");
    if(saving==NULL)
    printf("Errorfffffff");
    int check;
    fscanf(saving,"%d",&check);
    fclose(saving);
    return check;
}
int count_files_in_folder(const char *folder_path) {
    WIN32_FIND_DATAA findFileData;
    HANDLE hFind;
    char search_path[MAX_PATH];
    int file_count = 0;

   snprintf(search_path, MAX_PATH, "%s\\*", folder_path);

    hFind = FindFirstFileA(search_path, &findFileData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {

            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                file_count++;
            }
        } while (FindNextFileA(hFind, &findFileData) != 0);

        FindClose(hFind);
    } else {
        fprintf(stderr, "Error opening directory %s\n", folder_path);
        return -1;
    }

    return file_count;
}

const char* getCurrentDirectoryPath() {
    const int bufferSize = MAX_PATH;
    static char buffer[MAX_PATH]; 


    DWORD result = GetCurrentDirectoryA(bufferSize, buffer);
    if (result == 0) {
        fprintf(stderr, "Error getting current directory\n");
        return NULL;
    }

    
    return buffer;
}

void displaydepo(){
    welcomepay();
    if(!SetCurrentDirectoryA("Deposits"))
    printf(BHRED"\n\n\n                     No deposite accounts Found\n"RES);
    else{
    FILE *de;
    printf(BHBLU"Your Deposits :");
    int i=count_files_in_folder(getCurrentDirectoryPath());
    for(int j=1;j<=i;j++){
        char file[20];
        struct deposite display;
        sprintf(file, "%d.Deposite",j); 
        FILE *fp=fopen(file,"r");
        fread(&display,sizeof(display),1,fp);
        
        printf(BHGRN"\n\n                        Deposite Number %d"RES,j);
        if(display.amount==0){
            printf(BHWHT"-Withdrawn\n"RES);
            continue;
        }
        printf("\n");
        printf("\033[0m");
        printf(BHBLU"\n                        Amount           "BHGRN"- $%d\n",display.amount);
        printf(BHBLU"\n                        Tenure           "BHGRN"- %d\n",display.tenure);
        printf(BHBLU"\n                        Date of Deposite "BHGRN"- %d/%d/%d\n",display.date.day,display.date.month,display.date.year);
        printf("\n\n");
    }
    setdir();
    }




}
void checkdipo(){
    welcomepay();
    if(!SetCurrentDirectoryA("Deposits"))
    printf(BHRED"\n\n\n\n            No Deposite accounts Found\n"RES);
    else{
    setdir();
    displaydepo();
    if(!SetCurrentDirectoryA("Deposits"))
    printf("");
    printf("\n\n");
    printf(BHYEL"                   Enter the Number of Diposite:"RES);
    char np;
    read2(&np,1);
        printf("\n");
    welcomepay();
    char chechd[50];
    sprintf(chechd,"%c.Deposite",np);
    FILE *fp=fp=fopen(chechd,"r");
    struct deposite checkd;
    fread(&checkd,sizeof(checkd),1,fp);
    fclose(fp);
    if(checkd.amount==0){
        printf(RED"\n\n                           All ready Withdrawn\n"RES);
        setdir();
    }else{
    int res=isMatured(checkd);
    if(res!=0){
        
        printf(BHGRN"\n                        Your Deposite is Meatured \n");
        printf(BHGRN"\n               Total Amount to be Withdrawn With intrest :"BHCYN" $%d",res);
        printf("\n");
        printf(BHGRN"\n                  Successfully Added in to Savings Account\n");
        struct deposite winding;
        
       
        winding.amount=0;
        fp=fopen(chechd,"w");
        fwrite(&winding,sizeof(winding),1,fp);
        int chan=res;
        chan=chan+returnbalance(); 
        changedipo(chan);
        fclose(fp);   
    }
    else{
        printf(RED"\n                       Your Deposite is Still Active\n"RES);
                setdir();

    }
    }
    
    }
    getche();
}
void createdep(){
    welcomepay();
     LPCSTR Deposits= "Deposits";
        if(!SetCurrentDirectoryA("Deposits"))
        if(CreateDirectoryA("Deposits",NULL))
            printf("");
            if(SetCurrentDirectoryA("Deposits"))
            printf("");       
        int i=count_files_in_folder(getCurrentDirectoryPath());
        printf(YEL"                       Total Number of Deposits already Exixted:%d\n",i);
        i++;
        printf(BHGRN"\n\n       ThankYou For Opening Your %d Deposite PayHub Generates 6.5%% Intrest Per Annum\n"RES,i);
        
        
        
    char file[20];
    sprintf(file, "%d.Deposite",i);   
    while(1){
    printf(BHBLU"\n                             Enter the Deposite Ammount-"BHGRN);
    scanf("%d",&ch.amount);
    printf(RES);
    if(ch.amount>0){
        break;
    }
    printf(RED"\r                                Enter Amount Greater Than $0\n");
    }
    printf(BHBLU"                                       Enter Tenure-"BHGRN);
    scanf("%d",&ch.tenure);
    printf(BHBLU"                     Enter Date Of Deposite in DD/MM/YYYY formate-"BHGRN);
    scanf("%d/%d/%d",&ch.date.day,&ch.date.month,&ch.date.year);
    FILE* dip=fopen(file,"wb");
    fwrite(&ch,sizeof(ch),1,dip);
    fclose(dip);
    printf("\n\n                            Deposite Opened Successfully\n"RES);
   setdir();

}
void add_money(){
    welcomepay();
    FILE *know=fopen("savings.txt","r"),*beni;
    int am;
    while(1){
    printf(BHBLU"\n\n\n               Enter the amount to be Added-"BHGRN);
        
        scanf("%d",&am);
        printf(RES);
        if(am>0){
            break;
        }
        printf(RED"\r               Please Enter amount Greater than 0\n"RES);

    }
    int check;
        fscanf(know, "%d\n",&check);
        //printf("%d",check);
        fclose(know);
        know=fopen("savings.txt","w");
        welcomepay();
        printf("\n\n");
        fprintf(know, "%d\n",check+am);
        printf(BHGRN"                          %d Added Successfully,",am);
        printf("\n                           Total Balance :$%d\n",check+am);
        fclose(know);
        getche();
    


}

void checkbalance(){
    FILE*saving=fopen("savings.txt","r");
    if(saving==NULL)
    printf("Errorfffffff");
    int check;
    welcomepay();
    fscanf(saving,"%d",&check);
    printf("\n\n\n\n");
    printf(BHBLU"                     Balance in Your saving account :"BHGRN" $%d\n",check);
    fclose(saving);

}



void transfer() {
    welcomepay();
    FILE *usr = fopen("savings.txt", "r");


    int balance, beneficiaryBalance, amount;
    char beneficiaryId[40];
    fscanf(usr, "%d",&balance);
    int cc=0;
    printf(YEL"\n\n                     Enter the ID of the Beneficiary: "BHGRN);
    scanf("%s", beneficiaryId);
    printf(RES);

    setdir();
    if (!SetCurrentDirectoryA(beneficiaryId)) {
         printf("\033[31m");
        welcomepay();
        printf(RED"\n\n\n                          Beneficiary not found...!\n");
         printf(RES);
        fclose(usr);
        getchar();
         if(!SetCurrentDirectoryA(loginID))
        printf("Error... Going to User");
        return;
        
    }
    
    
    welcomepay();
    FILE *benir = fopen("savings.txt", "r");

    fscanf(benir, "%d", &beneficiaryBalance);
    while(1){
    printf(BHBLU"\n\n                      Enter the amount to be transferred: "BHGRN);
    scanf("%d", &amount);
    printf(RES);
    if(amount<0){      
    welcomepay();
        printf(RED"\r                             Enter Amount Greater than $0"RES);    
    }
    else if (amount > balance) {
        welcomepay();
        printf(RED"\r                                Insufficient Balance\n"RES);
        // setdir();
    } 
    else {  
        balance -= amount;
        beneficiaryBalance += amount;
        FILE *beniw = fopen("savings.txt", "w");
        fprintf(beniw, "%d\n", beneficiaryBalance);
        fclose(beniw);
        welcomepay();
        setdir();
        printf(BHGRN"\n\n\n\n                           Transaction Processing..");
        sleep(1);
        printf(BHGRN"\r                           Transaction Processing...");
        sleep(1);
        printf(BHGRN"\r                           Transaction Processing.....");
        sleep(1);
        printf(BHGRN"\r                          -Transaction successful-\n"RES);
        change(balance);
        getchar();

        break;
    }
     
     getchar();
}
}





void PAYHUB(){
    
    char store[20];
    FILE *fname;
    fname=fopen("name","r");
    fscanf(fname, "%99s", store);
    sprintf(loginID,"%s@travasso.com",strlwr(store));
    // printf("%s",loginID);
    FILE* bank;
    bank=fopen("bankdetails","r");
    char accnum[11];
    if(bank==NULL){
        welcomepay();
        printf(RED"\n\n      BANK account not linked YET Type 'Link' to Get Start Linking:"RES);
        char link[5];
        read2(link,4);
        printf("\n");
        char pin1[5],pin2[5];
        if(strcmp(link,"link")==0||strcmp(link,"Link")==0){
            welcomepay();
            printf(BHYEL"\\n\n                Enter Account Number (10 DIGITS)-"BHGRN);
            scanf("%s",accnum);
            welcomepay();
            printf(BHYEL"\n\n                           Set a PIN CODE (4 DIGITS)");
            while(1){
            printf(BHYEL"\n\n                                        PIN-"BHGRN);
            readPassword(pin1,5);
            if(strlen(pin1)!=4){   
                welcomepay();
                printf(RED"\n\n                     Please Enter a 4 DIGIT PIN\n"RES);
                continue;
            }
            printf(BHYEL"\r                                   Re-Enter-");
            read2(pin2,4);
            if(strcmp(pin1,pin2)==0)
                break;
            welcomepay();
            printf(RED"\n\n                            PIN s Didn't Match Try Again...\n"RES);
            }
            bank=fopen("bankdetails","w");
            fprintf(bank,"%s%s",pin1,accnum);
            fclose(bank);
        }
 
    
        // printf("\nThere are 2 Types of Accounts,\t1.Savings Account\t2.Deposit Accounts\n");
        welcomepay();
    printf(BHYEL"\n\n             Enter a Approximate amount in Savings Account   -"BHGRN);
    int savings;
    scanf("%d",&savings);
    FILE *file;
    file = fopen("savings.txt", "w");
    fprintf(file, "%d\n", savings);
    fclose(file);
    
    printf(BHYEL"                   Do you wanna open a Deposite account:"BHGRN);
    char dep[5];
    scanf("%s",dep);
    if(strcmp(dep,"yes")==0||strcmp(dep,"Yes")==0||strcmp(dep,"YES")==0)
    createdep();  
    welcomepay();  
    printf(BHGRN"\n\n\n                         Account Created Successfully\n");
    sleep(2);

    }
    else{
        
        char pincheck[5];
        int attempts=0;
        bank=fopen("bankdetails","r");
        int flag2=0;
        while(attempts<3){
        
        
        printf("\n");
        char c;
        char stored[5];
        int i=0;
        while(i<4){
            c=getc(bank);
            stored[i]=c;
            i++;          
        }
        rewind(bank);
        int k=0; 
        flag2=0;
        printf(BHBLU"\n\n\n\n                            Enter PIN to LOGIN-"YEL);
        readPassword(pincheck,5);
        while(k<4){
            
            if(pincheck[k]!=stored[k]){
                attempts++;
                flag2=1;
                if(attempts==3){
                printf("Sorry Try Again Later\n");
                flag2=1;
                }
                else if(attempts<3){
                    welcomepay();
                printf(RED"\r                Wrong PIN  Try again.. %d attempt(s) more"RES,3-attempts);
                // printf("\nPIN-");
                       }
                break;
            }
            k++;
        }
        if(flag2==0)
        break;
        
    }
    if(flag2==0){
    welcomepay();
    printf("\n\n\n\n\n") ;
   printf(BHGRN"                            Login in to PayHub..");
   sleep(1);
    printf(BHGRN"\r                            Login in to PayHub....");
    sleep(1);
   printf(BHGRN"\r                            Login in to PayHub......");
   sleep(1);
   // printf("Enter\n");
   while(1){
   welcomepay();
   
   
   printf("\n\n");
    printf(BGRN"\n                       1.Check Balance        2.Withdraw Deposits\n\n");
    printf("                       3.know Your Deposits   4.Transfer Money\n\n");
    printf("                       5.Add Deposits         6.Add Money to account\n\n");
    printf(BHYEL"                                       7.EXIT PayHub\n"RES);


    char choice;
    
    read2(&choice,1);
        printf("\n");

    switch(choice){
        case '1':
            checkbalance();
            getchar();
            break;
        case '2':
            checkdipo();
            // getche();
            break;
        case '3':
            displaydepo();
            getchar();
            break;
        case '4':
            transfer();
            getchar();
            break;
        case '5':
            createdep();
            getche();
            break;

        case '6':
            add_money();
            // getchar();
            break;
        case '7':
            system("cls");
            printf(BHYEL"\n\n\n\n\n\n\n\n                                 EXITING PayHub"RES);
            sleep(1);
            printf(BHGRN"\r                                 EXITING PayHub"RES);
            sleep(1);
            return;

    }   

   }
    }   
}
}