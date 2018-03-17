/**
    A very simple console diary notebook
    @author lianggaoquan
    @create 2018-3-17
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define N 10

void ReadFile(char *filename){
    FILE *fp;
    char ch;
    fp = fopen(filename,"r");

    if(fp){
        ch = fgetc(fp);
        while(ch != EOF){
            putchar(ch);
            ch = fgetc(fp);
        }
    }else{
        printf("File not exist!");
    }
    printf("\n");
    fclose(fp);
}

void WriteFile(char *filepath){
    FILE *fp;
    char ch;

    if(fp=fopen(filepath,"a")){
        printf("File is opened for writing.");

        printf("\n\n>");
        scanf("%c",&ch);

        while(ch != '<'){
            fputc(ch,fp);
            scanf("%c",&ch);

            if(ch == '\n'){
                printf(">");
            }

        }

    }else{
        printf("can't open file.");
    }
    printf("\n");
    fclose(fp);
}

/**
input the Strings in console,and sign it to the variables.
*/
void getString(char *p,int len){
    char c;
    int i = 0;

    while((c = getchar()) != '<'){
        if(i < len){
           p[i] = c;
           i++;
        }else{
            break;
        }

    }
    p[i] = '\0';
}

void concat(char *p){
    strcat(p,"\n");
}

void sign_up(){
    char name[N];
    char passwd[N];

    printf("Enter the user name: (No more than 10 letters, \nif you want to stop typing,use '<')\n");

    getString(name,N);

    printf("\nCongraduations ! You just create an account successfully.\n");

    FILE *fp1;
    char *ch1 = name;
    char *user_path = "D:\\workspace\\C\\user.txt";
    char *line = "\n";

    if(fp1 = fopen(user_path,"w")){
        fwrite(ch1,sizeof(char),strlen(ch1),fp1);

        fwrite(line,sizeof(char),strlen(line),fp1);
    }

    printf("\nPlease reboot and login.\n");

    fflush(fp1);
    fclose(fp1);
    exit(0);
}

/**
    use strcmp(str1,str2),if str1 == str2,return 0.
*/
void login(){

    FILE *fp1 = fopen("D:\\workspace\\C\\user.txt","r");

    char strLine[N];
    char user[N];

    printf("Enter name:\n");
    getString(user,N);
    concat(user);

    bool isUserMatch = false;

    while(!feof(fp1)){
        fgets(strLine,N,fp1);

        if(strcmp(strLine,user) == 0){
            isUserMatch = true;
            break;
        }
    }

    if(isUserMatch){
        printf("login successfully!\n\n");
        WriteFile("D:\\workspace\\C\\aaa.txt");

    }else{
        printf("Incorrect user name!\n");
    }
    fflush(fp1);
    fclose(fp1);

}

void step(){

    printf("choosing your next step.\n");
    printf("|__1.sign up;\n");
    printf("   |__2.login;\n");
    printf("      |__3.look your diary;\n");
    printf("         |__4.exit;\n");

    int choose = 0;
    printf("\n");
    scanf("%d",&choose);
    char a[] = "D:\\workspace\\C\\";

    fflush(stdin);

    if(choose == 1){
        sign_up();
    }else if(choose == 2){
        login();
    }else if(choose == 3){
        printf("input your diary name:\n");
        char b[100];
        char path[500];
        scanf("%s",&b);

        strcat(path,a);
        strcat(path,b);
        strcat(path,".txt");
        printf("\n");
        ReadFile(path);
    }else if(choose == 4){
        exit(1);
    }else{
        printf("Incorrect input!\n");
        exit(1);
    }
}


int main(){
    step();
    return 0;
}
