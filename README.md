# Concurrent Library Management System

A simple and robust **Library Management System** implemented in **C++**, showcasing advanced programming concepts like **object-oriented design**, **file handling**, and **multithreading with locks**. This project demonstrates an efficient and scalable solution for managing library operations with concurrent user interactions.

## Technologies & Tools
- **Programming Language:** C++
- **Core Concepts:**
  - Object-Oriented Programming (OOP)
  - Encapsulation and Modularity
  - File Handling and Persistence
  - Multithreading and Locks (for synchronization)
- **IDE:** Visual Studio Code (VS Code)

## Features
- **Book Management**
  - Add, remove, and update book details.
  - Maintain real-time book availability status.
- **User Management**
  - Register, remove, and update user profiles.
  - Track user borrowing history.
- **Transaction Management**
  - Record borrowing and returning transactions.
  - Assign unique transaction IDs for tracking.
- **Concurrent Operations**
  - Allow multiple users to borrow or return books simultaneously.
  - Use multithreading and locks to ensure data consistency and synchronization.
- **File Persistence**
  - Save and load data (books, users, transactions) to/from files.
  - Ensure data is retained between program sessions.

## Project Structure
- **Classes Used:**
  - **Book:** Represents book details like title, author, genre, and availability.
  - **User:** Manages user information and borrowed books.
  - **Transaction:** Handles borrowing and returning operations with unique IDs.
  - **Library:** Core class implementing the system’s functionality, including multithreading.

## Core Functionalities
- Object-oriented design principles for modularity and scalability.
- Locks and thread safety for concurrent access management.
- File handling for persistent storage of data.

## Sample Menu Options

<img width="856" alt="Screenshot 2025-01-18 at 3 23 39 PM" src="https://github.com/user-attachments/assets/a37452b5-96f7-44aa-ac66-15c47a7e3e35" />



## Motivation Behind the Project
The idea for this project hit me as when I thought about how traditional library systems struggle with efficiency, especially in managing simultaneous operations like issuing and returning books. This inspired me to create a solution that not only automates library management but also incorporates advanced concepts like multithreading and locks to handle concurrent tasks. By allowing multiple users to interact with the system at the same time while maintaining data accuracy, this project reflects a real-world scenario where scalability and consistency are essential. The addition of these features not only enhances performance but also demonstrates how thoughtful design and problem-solving can elevate a simple system into something robust and future-ready. It’s a project that bridges fundamental programming concepts with practical, real-world applications.
