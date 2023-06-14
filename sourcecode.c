#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct books{
  char code[10];
  char title[256];
  int quantity;
  float price;
  float value;
};
//Delete \n when using fgets function;
void delete_newline(char* str) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}


void addbook(struct books book[],int* k,int n){
  for(int i=0;i<n;i++){
    printf(" Book %d:\n",*k+1);
    printf(" Enter code: ");
    scanf("%s",book[i].code);
    printf(" Enter title: ");
    getchar();
    fgets(book[*k].title,sizeof(book[*k].title),stdin);
    delete_newline(book[i].title);
    printf(" Enter quantity: ");
    scanf("%d",&book[*k].quantity);
    printf(" Enter price: ");
    scanf("%f",&book[*k].price);
    book[*k].value = book[*k].quantity*book[*k].price;
    (*k)++;
    printf("\n");
  }
}



void displaymenu(){
  printf("Select options:\n");
  printf("1.Enter the list of books\n");
  printf("2.Display the list of books\n");
  printf("3.Sort the list of books by code\n");
  printf("4.Load data from file\n");
  printf("5.Find the <first> max price\n");
  printf("6.Find by code and edit the book\n");
  printf("7.Find by code and delete the book\n");
  printf("0.Exit\n");
  
  
  
}

void display_list_book(struct books book[],int k){

  printf("Code\tTitle\tQuantity\tPrice\tValue\n");
  for(int i=0;i<k;i++){
    printf("%s\t%s\t%d\t\t%.2f\t%.2f\n", book[i].code, book[i].title, book[i].quantity, book[i].price, book[i].value);
  }
  printf("\n");
  getchar();
}
 
void sortofbook(){

}



int main()
{
  int choice;
  int k=0,n;
  struct books* book;
  

  do{
  displaymenu();
  printf("Your selection <0 -> 7>: ");
  scanf("%d",&choice);
  switch (choice) {
      case 1:
        printf("\nEnter the number of book: ");
        scanf("%d",&n);
        book = (struct books*)malloc(n* sizeof(struct books));
        addbook(book,&k,n);
        break;
      case 2:
        display_list_book(book,k);
        break;
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 0:
      default:
        displaymenu();
        break;
    }
  }while(choice != 0);
  free(book);
  return 0;
}
