#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

char elements[][20] = {"hydrogen", "helium", "lithium", "beryllium", "boron", "carbon", "nitrogen", "oxygen", "fluorine", "neon", "sodium",
                       "magnesium", "aluminium", "silicon", "phosphorus", "sulphur", "chlorine", "argon", "potassium", "calcium" };
// Option 1
void learn_by_no(){
    int number=0;
    printf("Atomic Number: ");
    scanf(" %d", &number);
    if (number<0){
        printf("Sorry only elements with atomic number 1-20 are supported.");
    } else{
        printf("The element is %s .", elements[number-1]);
    }
    printf("\n----------------------------\n");
}

// Option 2
void learn_by_name(){
    char str[100];
    int i;
    printf("\n Element name[only in small letters]: ");
    scanf(" %s", str);

    for (i = 0; i < 20; ++i) {
        if (!strcmp(str, elements[i])) {
            break;
        }
    }

    if (i != 20) {
        printf("The atomic number of %s is %d.", str, i+1);
    }else {
        printf("%s is not present within atomic number 1-20.", str);
    }
    printf("\n----------------------------\n");
}

// Option 3
void no_blank(){
    int ans_blank_no;
    int m = generateRandomNumber(20);
    printf("The atomic number of %s is ________ .", elements[m]);
    printf("\nYour answer: ");
    scanf("%d", &ans_blank_no );

    if (ans_blank_no == m+1){
        printf("Correct!");
    }else{
        printf("Wrong!");
    }
    printf("\n----------------------------\n");
}

// Option 4
void name_blank(){
    char ans_blank_name[20];
    int n = generateRandomNumber(20);
    printf("Element with atomic no.%d is _______.", n+1);
    printf("\nYour answer: ");
    scanf("%s", ans_blank_name );

    if (strcmp(ans_blank_name, elements[n])==0){
        printf("\n-->Your Answer is correct!");
    }else{
        printf("\n-->Sorry! You are wrong. It is %s.", elements[n]);
    }
    printf("\n----------------------------\n");
}

// Option 5
void show_list(){
    printf("\t\tAtomic No.\t Elements\n");
    for (int p=0; p<20; p++){
        printf("\t\t   %d \t\t %s \n", p+1, elements[p]);
    }
    printf("\n----------------------------\n");
}

int main() {

        int choice=0;
        printf("===========================\n");
        printf("Let's Learn 20 Elements!");
        printf("\n===========================");
        printf("\n\nChoose: \n");
        printf(" 1.Learn by atomic no.\n 2.Learn by names.\n 3.Practice(Blank1)\n 4.Practice(Blank2)\n 5.Show in List\n 6.Exit\n");
        printf(">>> ");
        scanf("%d", &choice);

        int times=3;
        if (choice<5 && choice>0) {
            printf("How many times?");
            scanf("%d", &times);
            printf("\n");
        }

        if (choice==1){
            for(int t=0; t<times; t++){
                learn_by_no();
            }
        }else if (choice==2){
            for(int t=0; t<times; t++){
                learn_by_name();
            }
        }else if (choice==3){
            for(int t=0; t<times; t++){
                no_blank();
            }
        }else if (choice==4){
            for(int t=0; t<times; t++){
                name_blank();
            }
        }else if (choice==5){
            show_list();
        }else if (choice==6){
            printf("Have a good day! Don't forget to come back again!");
            exit(0);
        }else{
            printf("!Invalid Input!");
            exit(0);
        }

        char response;
        printf("Would you like to continue learning?[y/n]: ");
        scanf("%s", &response);

        if (response=='n'){
            printf("\nBye Bye! See you! Don't forget to learn the elements again later!");
        }else if(response=='y'){
            printf("\n\n\n");
            main();
        }

    return 0;
}

// MKST 10.8.22
