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


//-------------------------------------------------------------------------------------------------------
void clear_screen() {
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Unix/Linux
    #endif
}

// Edit the value of MAX if user input more 100 books
int edit_max(int n){
  char check;
  printf("You are inputting over 100 books! If you want to continue, you need edit it!\n");
  printf("Do you want to continue(y/n): ");
  scanf("%s",&check);
  if(check == 'Y' || check == 'y'){
    printf("Max = ");
    scanf("%d",&MAX);
    return MAX;
  }else return MAX;//if user don't want edit max, only 100 books will be inputted!

}

//Delete \n when using fgets function;
void delete_newline(char* str) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
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


//the function will check book code in array, return 1 if exist or return 0 if not

int find_code(struct books book[],int k, char code[10]){
	int i;
  for(i=0;i<k;i++){
    if(strcmp(book[i].code,code) == 0){
      return 1;
    }
  }
  return 0;
}

//---------------------------------------------------------------------------------------------------------


void addbook(struct books book[],int *k,int n,float total_value){
  int i;
  for(i=1;i<=n;i++){
    printf(" Book %d:\n",i);
    while(1){// This loop will run until user input code book appove!
       printf(" Enter code: ");
       scanf("%s",book[*k].code);
       if(find_code(book,*k, book[*k].code) == 1){
        printf("Code is already exist! Please input again!\n");
       }
       else
        break;
    }
    printf(" Enter title: ");
    getchar();
    fgets(book[*k].title,sizeof(book[*k].title),stdin);
    delete_newline(book[*k].title);
    printf(" Enter quantity: ");
    scanf("%d",&book[*k].quantity);
    printf(" Enter price: ");
    scanf("%f",&book[*k].price);
    book[*k].value = book[*k].quantity*book[*k].price;
    total_value += book[*k].value;
    (*k)++;
    printf("\n");
  }
}




//The function will print out console the list of books
void display_list_book(struct books book[],int k){
  clear_screen();
  int i=0;
  printf("\n%-8s  %-30s  %-8s  %-8s  %-8s\n", "Code", "Title", "Quantity", "Price", "Value");
  while(i<k){
    printf("%-8s  %-30s  %-8d  %-8.2f  %-8.2f\n", book[i].code, book[i].title, book[i].quantity, book[i].price, book[i].value);
    i++;
     if(i % 5 ==0){
	 	
     	printf("----------------------------------------------------------------------\n");
    	getchar();
	}
  }
  getchar();
}

// This function will sort the k books using Linear sorts
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
int indexmin,i,j;
  for(i=0;i<k;i++){
    indexmin = i;
    for(j=i;j<k;j++){
      if(strcmp(book[j].code,book[indexmin].code) <= 0) indexmin =j;
    }
 struct books temp = book[i];
        book[i] = book[indexmin];
        book[indexmin] = temp;
  }
}

//Load data from file

void load_data_from_file(struct books book[], int* k) {
  clear_screen();
  FILE* fp = fopen("database1.txt", "r");
  if(fp == NULL) {
  	printf("Load file failed!");
  	exit(0);
  }else printf("Loading files...\n");
  (*k)++;
  /*char line[100];
  int count=0;
  while (fgets(line, sizeof(line), fp) && !feof(fp)) {
    if (count >= MAX) {
      printf("The maximum number of books inputted has been reached!\n");
      break;
    }

    /*char* token = strtok(line, ",");
    strcpy(book[*k].code, token);
    token = strtok(NULL, ",");
    strcpy(book[*k].title, token);
    token = strtok(NULL, ",");
    book[*k].quantity = atoi(token);
    token = strtok(NULL, ",");
    book[*k].price = atof(token);
    book[*k].value = book[*k].quantity * book[*k].price;
    (*k)++;
    count++;
  }*/
  int count = 0; 
  while (fscanf(fp, "%s %[^\n] %d %f", book[*k].code, book[*k].title, &book[*k].quantity, &book[*k].price) != '\0') {
  	if (count >= MAX) {
      printf("The maximum number of books inputted has been reached!\n");
      break;
    }
    book[*k].value = book[*k].quantity * book[*k].price;
    (*k)++;
    count++;
  }
  fclose(fp);
}

//Find max price of books

void find_max_price(struct books book[] , int k){
  clear_screen();
  double Max_price=book[0].price;
  int indexmax=0;
  int i;
  for(i = 1;i<k;i++){
    if(book[i].price > Max_price) {
      Max_price = book[i].price;
      indexmax=i;
    }
  }
  printf("\n%-8s  %-30s  %-8s  %-8s  %-8s\n", "Code", "Title", "Quantity", "Price", "Value");
  printf("%-8s  %-30s  %-8d  %-8.2f  %-8.2f\n", book[indexmax].code, book[indexmax].title, book[indexmax].quantity, book[indexmax].price, book[indexmax].value);
  printf("\n");
}


void find_book_and_edit(struct books book[],int k){
  int i;
  char find[10];
  printf("\nFind what book?(code):");
  scanf("%s",find);
  for (i=0;i<k;i++){
    if(strcmp(book[i].code,find) == 0){
      printf("\n%-8s  %-30s  %-8s  %-8s  %-8s\n", "Code", "Title", "Quantity", "Price", "Value");
      printf("%-8s  %-30s  %-8d  %-8.2f  %-8.2f\n", book[i].code, book[i].title, book[i].quantity, book[i].price, book[i].value);
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
      book[i].value = book[i].quantity*book[i].price;
    }
  }
}


void find_book_and_delete(struct books book[], int *k){
  int i,h;
  char find[10];
  char check;
  printf("Find what book?(code):");
  scanf("%s",find);
  for (i=0;i<*k;i++){
    if(strcmp(book[i].code,find) == 0){
      printf("\n%-8s  %-30s  %-8s  %-8s  %-8s\n", "Code", "Title", "Quantity", "Price", "Value");
      printf("%-8s  %-30s  %-8d  %-8.2f  %-8.2f\n", book[i].code, book[i].title, book[i].quantity, book[i].price, book[i].value);
      printf("Do you want to delete this book(y/n): ");
      scanf(" %c",&check);
      if(check == 'y' || check == 'Y'){
        //Delete book by shifting
        for(h=i;h<(*k)-1;h++){
          strcpy(book[h].code,book[h+1].code);
          strcpy(book[h].title,book[h+1].title);
          book[h].quantity=book[h+1].quantity;
          book[h].price = book[h+1].price;
          book[h].value = book[h+1].value;
        }
        //Update book count
        (*k)--;
        if (*k < 0) {
          *k = 0;  // Ensure count doesn't become negative
        }
        printf("Book deleted!.\n");
      }
    }
  }
}

//-------------------------------------------------------------------------------------------------------------------

int main(){
  float sum_value;
  int choice;
  int k=0,n;
  struct books* book = malloc(MAX * sizeof(struct books));
  do{
  displaymenu();
  printf("Your selection <0 -> 7>: ");
  scanf("%d",&choice);
  switch (choice) {
      case 1:
        printf("\nEnter the number of book: ");
        scanf("%d",&n);
        if(n > MAX){
          n = edit_max(n);
        }
        book = (struct books*)malloc(n* sizeof(struct books));
        addbook(book,&k,n,sum_value);
        break;
      case 2:
        display_list_book(book,k);
        getchar();
        break;
      case 3:
        sortofbook(book,k);
        break;
      case 4:
        load_data_from_file(book,&k);
        getchar();
        break;
      case 5:
        find_max_price(book,k);
        break;
      case 6:
        find_book_and_edit(book,k);
        break;
      case 7:
        find_book_and_delete(book,&k);
        break;
      case 0:
        exit(0);
      default:
        printf("Syntax error! Please input again! \n");
        break;
    }
  }while(choice != 0);
  free(book);
  return 0;
  }

