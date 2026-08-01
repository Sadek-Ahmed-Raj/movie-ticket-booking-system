🎬 Computerized Movie Ticket Booking System
A console-based Movie Ticket Booking System built in C, developed as a Mini Lab Project for the course CSE113: Programming and Problem Solving, Department of Computer Science and Engineering, Daffodil International University.

📖 Overview
This system allows users to manage cinema seat reservations through a simple text-based menu. It uses C structures, 2D arrays, and file handling to persist seat data even after the program closes.

✨ Features
View Seating Chart — Displays available (O) and sold (X) seats in a clear grid format
Purchase Ticket — Book a seat by entering row, column, passenger name, and ID
Cancel Ticket — Free up a previously booked seat
Edit Ticket Info — Update passenger name or ID for a booked seat
Search Ticket — Find a reservation by passenger name or ID
Show Summary — View total, available, and sold seat counts
Reset Seating — Clear all bookings and start fresh
Save & Exit — Persist all seat data to seats.dat for the next session
🧱 Design
Seating Layout: 5 rows × 10 columns = 50 seats
Data Structure: Each seat is represented by a Seat struct containing:
status (0 = available, 1 = sold)
name (passenger name)
id (passenger ID)
Storage: A 2D array Seat seating[ROWS][COLS] models the cinema hall; all data is saved to and loaded from seats.dat using binary file I/O (fread/fwrite).
🛠️ How to Compile & Run
gcc main.c -o ticket_system
./ticket_system
Copy
📋 Menu Options
===== Movie Ticket System =====
1. Display Seating Chart
2. Purchase Ticket
3. Cancel Ticket
4. Edit Ticket Info
5. Show Available & Sold Count
6. Search Ticket by Name/ID
7. Reset Seating
8. Save & Exit
Copy
🧪 Testing
The system was tested for:

Booking a seat successfully
Attempting to book an already reserved seat (should fail)
Cancelling a booking and confirming the seat becomes available
Editing ticket information and verifying updates
Searching a ticket by name or ID
Confirming correct available/sold counts in the summary
👥 Team Members
Student Name	Student ID
MD Jabir Hossain Sadi	251-15-124
Sadek Ahmed Raj	251-15-511
Mahfujur Rahman	251-15-453
Md Asifur Islam	251-15-388
Ankur Paul	251-15-738
Supervised by: Mehadi Hasan, Lecturer, Department of CSE, Daffodil International University

📚 References
C Programming Language — Brian W. Kernighan and Dennis M. Ritchie
Online C Tutorials: w3schools.com, TutorialsPoint
📄 License
This project was developed for academic purposes as part of the CSE113 course at DIU.
