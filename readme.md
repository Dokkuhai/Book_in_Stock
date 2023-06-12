**Book_of_Stock**
Design and code a program that manages the list of books in a local bookstore.  Information about a book includes: • a code, • a title • a quantity • a price for each book.  Design your program according to structured design principles.  Your program uses parallel arrays or array of structs and includes functions to validate the input and to sort the items by code.  You may assume that there are no more than 100 books to process, but write your code so that you can change this limit by editing a single statement. Preface each function header with a comprehensive description of the function purpose, the function parameters and the function return value. On running, your program displays the menu as below:

Select options:
1.Enter the list of hooks
2.Display the list of books
3.Sort the list of books by code
4.Load data from file
5.Find the (first> max price
6.Find by code and edit the book
7.Find by code and delete the book
0.EXIT 
 Your selection (0 -> 7 ?):
If you select 1, then the output from your program looks something like:

Enter number of books: 3 
 Book 1: 
  Enter code: A02 
  Enter title:Hello 
  Enter quantity: 34 
  Enter price: 27.5 
 Book 2: 
  Enter code:A01 
  Enter title:Well 
  Enter quantity: 5 
  Enter price: 12.6 
 Book 3: 
  Enter code:A02 
  The code A02 already exists, please renter! 
  Enter code:A03 
  Enter title:Come 
  Enter quantity: 7 
  Enter price: 6.9

Select 2: Code Title Quantity Price Value 
          A02  Hello 34       27.5  935.0 
          A01  Well  5        12.6  63.0 
          A03  Come  7        6.9   48.3 
                       Total value: 1046.3

If you select 3, the list will be sorted by code.
Select 2 to display the list after sorting: 
Code Title Quantity Price Value 
A01  Well  5        12.6  63.0 
A02  Hello 34       27.5  935.0 
A03  Come  7        6.9   48.3 
             Total value: 1046.3
