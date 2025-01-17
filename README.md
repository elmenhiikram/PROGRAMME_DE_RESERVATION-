Chicram's Hotel Reservation System
This C program simulates a hotel reservation system, allowing users to view hotel information, check room availability, make reservations, and view reservation details. The system is designed for a simple hotel with different types of rooms (Single, Double, Triple) and allows users to book rooms, calculate the cost, and manage their reservations.

Features
Room Availability: Check the availability of rooms for Single, Double, and Triple types.
Hotel Information: View hotel amenities, location, and detailed room descriptions.
Reservation System: Allows users to make room reservations, input customer information, and calculate the total bill based on the number of days, room type, and number of rooms.
Reports: Displays all reservations stored in a file, including customer name, room type, reservation date, and bill amount.
Data Storage: Reservation data is stored in a file (file.txt).
Prerequisites
C Compiler (e.g., GCC)
Windows Operating System (for conio.h and windows.h functions)
Files
hotel.c: Main source code file.
file.txt: A file where reservation data is stored.
Setup and Compilation
Clone or download this repository to your local machine.

Open a terminal or command prompt in the directory where the source code is located.

Compile the code using your C compiler:
gcc hotel.c -o hotel
Run the program:
./hotel
Usage
When you run the program, a menu will appear with the following options:

D - Display reservations.
H - View hotel information (amenities, location, room details).
A - View room availability.
R - Make a reservation.
E - Exit the program.
Example Workflow
Choose R to make a reservation.
Enter your details, such as name, date, room type, number of persons, and the number of days of stay.
The system will calculate your total bill based on room type and the number of days.
Choose D to see the list of all reservations.
Contributions
Feel free to fork this repository and submit a pull request with improvements or bug fixes.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Author
Chicram's Hotel - The main developer.
