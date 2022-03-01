
/*
Login Page in C
Provide By Hamed Nahali 

*/
#include<stdio.h>
#include<string.h>

struct Person{
	char name[50];
	char username[50];
	char password[50];
};

int username_check(char username[50]){
	// Returns 2 for user exists, 1 for user doesnt exist and 0 for file failure
    FILE *file;   

    char data[160]; 
  
    file = fopen("data.txt", "r"); 
    if ( file == NULL ){ 
        return 0;
    } 
    else{ 
        while( fgets ( data, 160, file ) != NULL ) 
        { 
          	char * sub = strtok(data, "*");
		    if ( strcmp(sub, username) == 0)
		    	return 2;

         } 
          

        fclose(file) ; 
    } 
    return 1;
}

int sign_in(struct Person p){
	// Returns 2 for user success, 1 for not valid and 0 for file failure
    FILE *file;   

    char data[160]; 
  
    file = fopen("data.txt", "r"); 
    if ( file == NULL ){ 
        return 0;
    } 
    else{ 
        while( fgets ( data, 160, file ) != NULL ) 
        { 

          	char * sub = strtok(data, "*");

		    if ( strcmp(sub, p.username) == 0){
		    	sub = strtok(NULL, "*");

		    	if ( strcmp(sub, p.password) == 0)
					return 2;
		    	}


         } 
          

        fclose(file) ; 
    } 
    return 1;
}


int sign_up(struct Person p){
	// Returns 2 for success, 1 for username failure and 0 for file failure
	 FILE *file ; 
      
    char data[160]="";
    strcat(data, p.username);
    strcat(data,"*");
    strcat(data, p.password);
    strcat(data,"*");
    strcat(data, p.name);
 	//username*password*name
 
    file = fopen("data.txt", "a") ; 
      
  	
    if ( file == NULL ) { 
        return 0;
    } 
    else{ 
        fputs(data, file) ;    
        fputs("\n", file) ; 
        fclose(file) ; 
    } 
    return 2;
}

int main(){
	int answer;
	printf("Welcome to program. Enter\n1 to sign in\n2 to sign up\n3 to quit\n:");
	
	while(1){
		scanf("%d", &answer);
		system("cls");
		if (answer == 3){
			printf("Good bye.");
			break;
		}
		else if (answer == 2){
			while(1){
				struct Person p;
				printf("Enter your name: ");
				scanf("%s", p.name);
				printf("Enter your username: ");
				scanf("%s", p.username);
				printf("Enter your password: ");
				scanf("%s", p.password);
				if(username_check(p.username) == 2){
					printf("The username exists! Try again\n");
				}else{
					sign_up(p);
					printf("Dear %s, you are registered.\n", p.name);
					break;
				}
			}
		}
		else if (answer == 1){
			while(1){
				struct Person p;
				printf("Enter your username: ");
				scanf("%s", p.username);
				printf("Enter your password: ");
				scanf("%s", p.password);
				
				if (sign_in(p) == 2){
					printf("you are signed in.\n");
					break;
				}else{
					printf("Data is not valid! Try again.\n");
				}
			}
				
		}
		printf("Enter\n1 to sign in\n2 to sign up\n3 to quit\n:");
	}
	


	return 0;
}
