#include <stdio.h>
#include <stdlib.h>

struct books{
  char code[10];
  char title[256];
  int quantity;
  float price;
  float value;
};

void addbook(struct books book[],int n){
  int *k;
  *k=1;
  for(int i=1;i<=n;i++){
    printf(" Book %d:",*k);
    printf("\n Enter code: ");
    scanf("%c",book[i].code);
    printf(" Enter title: ");
    fgets(book[*k].title,sizeof(book[*k].title),stdin);
    printf(" Enter quantity: ");
    scanf("%d",&book[*k].quantity);
    printf(" Enter price: ");
    scanf("%f",&book[*k].price);
    book[*k].value = book[*k].quantity*book[*k].price;
    *k++;
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

void display_list_book(int arr[],int k){
  for(int i=0;i<k;i++){
    printf("");
  }
}
 
void sortofbook(){

}



int main()
{
  int choice;
  int *k,n;
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
        addbook(book,n);
        break;
      case 2: 
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
  }while(choice == 0);
  return 0;
}
