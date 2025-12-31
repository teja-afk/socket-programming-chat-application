# C++ Socket Programming Chat Application

A **multithreaded TCP chat application** built in **C++ using Winsock (Windows)**.  
This project demonstrates low-level **socket programming**, **client–server architecture**, and **multithreading** using the Winsock API.

---

## 📌 Project Overview

This application consists of:
- A **TCP server** that accepts multiple client connections
- Multiple **TCP clients** that can send and receive messages concurrently
- A **broadcast mechanism** where messages from one client are delivered to all others

The project is intended for **learning system programming concepts** and is suitable for **interview discussion and resume use**.

---

## 📂 Project Structure

socket-programming-chat-application/
│
├── server/
│ └── server.cpp # Multithreaded TCP chat server
│
├── client/
│ └── client.cpp # TCP chat client
│
└── README.md

## ✨ Features

- TCP-based client–server communication
- Supports multiple concurrent clients
- Multithreaded server (one thread per client)
- Separate send and receive threads on client
- Real-time message broadcasting
- Graceful connection handling

---

## 🛠️ Tech Stack

- **Language:** C++
- **Networking API:** Winsock2
- **Concurrency:** `std::thread`
- **Protocol:** TCP (IPv4)
- **Platform:** Windows

---

## 🧠 How It Works

### Server
1. Initializes the Winsock library
2. Creates and binds a TCP socket
3. Listens for incoming client connections
4. Accepts clients in a loop
5. Spawns a new thread for each connected client
6. Receives messages and broadcasts them to all connected clients

---
<img width="1024" height="1536" alt="image" src="https://github.com/user-attachments/assets/4a529799-d3f1-4b0f-af0d-e41b795bb35d" />

### Client
1. Initializes the Winsock library
2. Connects to the server using IP and port
3. Uses two threads:
   - One for sending messages
   - One for receiving messages
4. Displays incoming messages in real time

<img width="1024" height="1536" alt="image" src="https://github.com/user-attachments/assets/54220abb-c093-419e-b22d-3d1cc27520d1" />

---

## ▶️ How to Run

### Prerequisites
- Windows OS
- Visual Studio (or any C++ compiler with Winsock support)
- Basic knowledge of socket programming

---

### 1️⃣ Compile and Run Server

Using **Visual Studio**:
- Open `server.cpp` project
- Build and run the server

Using command line (MinGW example):
```bash
g++ server.cpp -o server -lws2_32
server.exe
