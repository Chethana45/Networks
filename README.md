# 🌐 Computer Networks

A collection of **Computer Networks laboratory programs and socket programming exercises** implemented using **C and Python**.

This repository contains practical implementations of networking concepts such as **TCP, UDP, client-server communication, DNS lookup, HTTP communication, and web clients**.

---

<p align="center">

<img src="https://img.shields.io/badge/C-Network%20Programming-00599C?style=for-the-badge&logo=c&logoColor=white" />
<img src="https://img.shields.io/badge/Python-Networking-3776AB?style=for-the-badge&logo=python&logoColor=white" />
<img src="https://img.shields.io/badge/TCP%2FIP-Socket%20Programming-8B5CF6?style=for-the-badge" />
<img src="https://img.shields.io/badge/Computer-Networks-16A34A?style=for-the-badge" />

</p>

---

## 📡 About This Repository

This repository contains my **Computer Networks laboratory programs** practiced during college.

The programs focus mainly on understanding how applications communicate over networks using **socket programming**.

The implementations cover both **C and Python**, providing practice with different approaches to network programming.

---

# 🧠 Concepts Covered

### 🔌 Socket Programming

Programs demonstrating the basic structure of network communication using sockets.

```text
Client
   │
   │  Request
   ▼
Server
   │
   │  Response
   ▼
Client
```

---

### 🔵 TCP

Programs involving **Transmission Control Protocol (TCP)** client-server communication.

TCP provides:

- Connection-oriented communication
- Reliable data transmission
- Ordered delivery
- Error detection and retransmission

Example files:

```text
client1.c
server.c
```

---

### 🟢 UDP

Programs implementing **User Datagram Protocol (UDP)** communication.

UDP is:

- Connectionless
- Lightweight
- Faster than TCP for many use cases
- Suitable for applications where low overhead is important

Example files:

```text
client2.c
server2.c
client4.py
server4.py
```

---

### 🌍 HTTP

The repository contains programs that demonstrate basic HTTP communication and webpage retrieval.

Example:

```text
webclient.py
webclient2.py
UDP.py
```

These programs provide practice with sending requests and receiving data from network services.

---

### 🔎 DNS

A Python program is included for practicing **DNS lookup**.

Example:

```text
client5.py
```

The program demonstrates how a hostname can be resolved to network information.

```text
Domain Name
     ↓
 DNS Lookup
     ↓
IP Address
```

---

# 📂 Repository Structure

```text
Networks/
│
├── UDP.py
│
├── client1.c
├── client2.c
├── client3.c
│
├── client4.py
├── client5.py
│
├── server.c
├── server2.c
├── server3.c
│
├── server4.py
├── server5.py
│
├── webclient.py
└── webclient2.py
```

---

# 🧩 Programs

## `client1.c`

Basic client-side network programming practice.

---

## `client2.c`

C implementation involving **UDP client communication**.

---

## `client3.c`

Additional C client-side socket programming practice.

---

## `client4.py`

Python implementation of a network client.

---

## `client5.py`

Python program implementing **DNS lookup**.

---

## `server.c`

Basic **TCP server** implementation using C.

---

## `server2.c`

UDP server implementation using C.

---

## `server3.c`

Additional server-side socket programming practice.

---

## `server4.py`

Python-based server implementation.

---

## `server5.py`

Additional Python server-side networking practice.

---

## `webclient.py`

Basic web client implementation for retrieving webpage data.

---

## `webclient2.py`

Additional Python web client implementation.

---

## `UDP.py`

Python-based UDP/network programming practice.

---

# 🔄 Client-Server Communication

The basic communication model used by many programs in this repository is:

```text
              NETWORK
                 │
        ┌────────┴────────┐
        │                 │
        ▼                 ▼
     CLIENT             SERVER
        │                 │
        │ ── Request ──► │
        │                 │
        │ ◄─ Response ──  │
        │                 │
        └─────────────────┘
```

The client initiates communication while the server waits for incoming connections or requests.

---

# 🔵 TCP Communication

A typical TCP workflow is:

```text
Server
  ↓
Create Socket
  ↓
Bind
  ↓
Listen
  ↓
Accept
  ↓
Receive / Send
  ↓
Close
```

The client follows:

```text
Client
  ↓
Create Socket
  ↓
Connect
  ↓
Send / Receive
  ↓
Close
```

---

# 🟢 UDP Communication

UDP does not require a connection to be established before sending data.

```text
Client
  │
  │ Datagram
  ▼
Server
  │
  │ Response
  ▼
Client
```

Typical operations include:

```text
socket()
   ↓
bind()
   ↓
sendto()
   ↓
recvfrom()
```

---

# 🌐 HTTP Client

The web client programs demonstrate the basic idea of retrieving information from a web server.

```text
Client
   │
   │ HTTP Request
   ▼
Web Server
   │
   │ HTTP Response
   ▼
Client
```

This provides practical exposure to how application-layer communication works over networks.

---

# 🔍 DNS Lookup

DNS converts human-readable domain names into network addresses.

```text
www.example.com
        ↓
      DNS
        ↓
    IP Address
```

The DNS-related program provides practice with this resolution process.

---

# 🛠️ Technologies Used

### Programming Languages

- C
- Python

### Networking Concepts

- Socket Programming
- TCP
- UDP
- Client-Server Architecture
- HTTP
- DNS
- Network Communication

### Tools

- GCC
- Python
- Linux / Ubuntu
- VS Code
- Git
- GitHub

---

# ▶️ Running C Programs

Compile a C program using GCC:

```bash
gcc client1.c -o client1
```

Run:

```bash
./client1
```

For a server:

```bash
gcc server.c -o server
./server
```

Usually, run the **server first** and then start the client in another terminal.

---

# ▶️ Running Python Programs

Run a Python program using:

```bash
python filename.py
```

Example:

```bash
python client5.py
```

or:

```bash
python server4.py
```

---

# 🖥️ Running Client and Server

For client-server programs, use two terminals.

### Terminal 1

```bash
./server
```

### Terminal 2

```bash
./client
```

The exact commands depend on the particular program.

---

# 🧪 Practical Learning

These programs provide hands-on practice with:

```text
Application Layer
       ↓
HTTP / DNS
       ↓
Transport Layer
       ↓
TCP / UDP
       ↓
Socket Programming
       ↓
Client-Server Communication
```

---

# 📚 Learning Objectives

Through these programs, I practiced:

- Understanding network communication
- Creating sockets
- Establishing client-server communication
- Implementing TCP communication
- Implementing UDP communication
- Working with network addresses
- DNS lookup
- HTTP communication
- Sending and receiving data
- Understanding client-server architecture
- Implementing networking concepts in both C and Python

---

# 🎯 Purpose

This repository serves as my **Computer Networks laboratory practice collection**.

The main purpose is to understand networking concepts through actual implementations rather than only studying them theoretically.

---

# 🌱 Future Additions

More networking programs can be added covering:

- 🔹 TCP applications
- 🔹 UDP applications
- 🔹 DNS
- 🔹 HTTP / HTTPS
- 🔹 Routing algorithms
- 🔹 Network simulation
- 🔹 Packet analysis
- 🔹 Multithreaded servers
- 🔹 Advanced socket programming

---

# 👩‍💻 Author

## Chethana Sri

**B.E. Computer Science Engineering**  
**Madras Institute of Technology**

---

<p align="center">

### 🌐 Learn Networks • Build Sockets • Understand Communication 🚀

</p>
