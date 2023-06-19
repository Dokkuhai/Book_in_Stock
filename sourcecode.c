#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int MAX=100;

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




void addbook(struct books book[],int *k,int n){
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



//The function will print out console the list menu

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

//The function will print out console the list of books
void display_list_book(struct books book[],int k){

   printf("\n%-8s  %-20s  %-8s  %-8s  %-8s\n", "Code", "Title", "Quantity", "Price", "Value");
  for (int i = 0; i < k; i++) {
    printf("%-8s  %-20s  %-8d  %-8.2f  %-8.2f\n", book[i].code, book[i].title, book[i].quantity, book[i].price, book[i].value);
  }
  printf("--------------------------------------------------------\n");
  getchar();
}
 
/*void sortofbook(struct books book[],int k){
  for(int i=0;i<k;i++){
    for(int j=i+1;j<k;j++){
      if(strcmp(book[i].code,book[j].code) >= 0){
        struct books temp = book[i];
        book[i] = book[j];
        book[j] = temp;
      }
    }
  }
}
*/


//This function will sort the k books using Selection sorts
void sortofbook(struct books book[],int k){
int indexmin;
  for(int i=0;i<k;i++){
    indexmin = i;
    for(int j=i;j<k;j++){
      if(strcmp(book[j].code,book[indexmin].code) <= 0) indexmin =j;
    }
 struct books temp = book[i];
        book[i] = book[indexmin];
        book[indexmin] = temp;
  }
}

void load_data_from_file(){
  FILE *fp = NULL;
  fp = fopen("database.dat","r");
  /*while(fscanf(b "",)){

  }*/
}

void find_max_price(struct books book[] , int k){

}


void find_book_and_edit(struct books book[],int k){
  char find[10];
  printf("Find what book?(code):");
  scanf("%s",find);
  for (int i=0;i<k;i++){
    if(strcmp(book[i].code,find) == 0){
      printf("\n%-8s  %-20s  %-8s  %-8s  %-8s\n", "Code", "Title", "Quantity", "Price", "Value");
      printf("%-8s  %-20s  %-8d  %-8.2f  %-8.2f\n", book[i].code, book[i].title, book[i].quantity, book[i].price, book[i].value);
      printf(" Book %d:\n",i);
      printf(" Edit code: ");
      scanf("%s",book[i].code);
      printf(" Edit title: ");
      getchar();
      fgets(book[i].title,sizeof(book[i].title),stdin);
      delete_newline(book[i].title);
      printf(" Edit quantity: ");
      scanf("%d",&book[i].quantity);
      printf(" Edit price: ");
      scanf("%f",&book[i].price);

    } 
    else{
      printf("No book found!");
    } 

  }
}

void find_book_and_delete(struct books book[], int k){
  char find[10];
  char check;
  printf("Find what book?(code):");
  scanf("%s",find);
  for (int i=0;i<k;i++){
    if(strcmp(book[i].code,find) == 0){
      printf("\n%-8s  %-20s  %-8s  %-8s  %-8s\n", "Code", "Title", "Quantity", "Price", "Value");
      printf("%-8s  %-20s  %-8d  %-8.2f  %-8.2f\n", book[i].code, book[i].title, book[i].quantity, book[i].price, book[i].value);
      printf("---------------------------------------------------------------------------------------------");
      printf("Do you want to delete this book(y/n)");
      scanf("%s",&check);
      }
  }
  
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
        sortofbook(book,k);
        display_list_book(book,k);
        break; 
      case 4:
        
      case 5:
      case 6:
         find_book_and_edit(book,k);
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
