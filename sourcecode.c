#include <stdio.h>

struct books{
  char codebook[10];
  char title[256];
  int quantity;
  float price;
  float value;
};

void addbook(books book){
  int n;
  printf("Enter number of book: ");
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    printf(" Book %d:\n",i);
    printf("  Enter code: ");
    fgets(book.codebook,sizeof(book.codebook),stdin);
    

  }
}



void displaymenu(){

}



void sortofbook(){

}



int main(int argc, char *argv[])
{ 
  

  return 0;
}
