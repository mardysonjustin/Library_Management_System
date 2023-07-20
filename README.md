# Library_Management_System
Librarizz is a command-line based Library Management System designed to manage and organize books in a library. Users can register, log in, search for books, borrow them, return them, view which books are available and which are not, add new books, delete existing books, and submit book suggestions using its functions. The system also allows users to log in as regular users or administrators (to perform specialized duties like adding and removing books). However, the system does not contain books’ contents, it only contains the book’s title, author and its genre as a means to show how a bigger library system management works. <br/>
## Configuration Guide<br/>
	Register – username and a password is needed to register an account.<br/>
	Log in – users must first be registered to access the program.<br/>
	Admin – there is only 1 admin user in this program.<br/>
	Log in as a normal user – normal users can search, borrow, return books and view the available books. They can also submit their suggestions on which book the admin should add next.<br/>
	Log in as administrator – users can do what a normal user can do but more. Users can add and remove books. Moreover, they have the access to view the submitted suggested books by the users.<br/>

 ## Error Handlings <br/>
	Same username of users – this was prevented in the registerd() function such that when a same username is created, it will alert the user that the username has already been taken.
	Character input in main menu – system clears and ignores the input and will return to the start of the loop.
	Case sensitivity in search – the search() function has a function in itself that transform user inputs to small letters so it would not miss the books with the same keyword with different capitalizations.
	Separator for title, author, and genre in printing – in the search() function, a delimiter (comma) was used to determine which is the title, author, and genre when printing the details.
	User input book not found in the database – as part of the search() function, when the keyword is not found in the database, it will print out that there are no such books were found and will prompt the user to press any key to continue.
	Duplication of books – a condition in functions borrow() and return() were added to avoid duplication of files such that when a book is on the other list, it will not be added to that list anymore.

## Developers
- Agres, Zyrach Adrian A.
- Guernaldo, Mardyson Justin D.
- Lejano, Nathaniel O.

## Course Information <br/>
Course: Data Structures and Algorithm<br/>
Course Facilitator: Mr. Maurice Oliver Dela Cruz
