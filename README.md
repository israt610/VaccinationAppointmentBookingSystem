Implement Vaccine Booking Management in C language: This project is made to make the vaccine booking system more easier.We conducted this project in C language which is the basic programming language.

For this project we needed two header files,which are stdio.h and string.h .We also needed a file which we named vaccine.txt .

This program contists 5 functions.The name of the functions and a short description about each function is given in the below:

(1)Main Function:The "main()" function is the entry point of the program. It presents a menu to the user with options for signing up, logging in, changing the password, booking a vaccine appointment and exiting the program. It uses an array v to track the availability of vaccines.

(2)Registration Function:The "registration()" function allows a user to register with a username, password, full name, age and phone number. The user's information is stored in a file named "vaccine.txt."

(3)Login Function:The "login()" function allows a user to log in by entering their username and password. It reads user information from the "vaccine.txt" file and checks if the provided credentials match any existing user.

(4)Change Password Function:The "change_password()" allows a user to change their password. It reads user information from the file, finds the user by index, and updates their password.

(5)Booking Function:The "booking()" function allows a logged-in user to book a vaccine appointment. It displays available vaccines and vaccination centers, and the user can choose one. The program updates the availability of vaccines and confirms the booking.

Here are some screenshots after running this program:



