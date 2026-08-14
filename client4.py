import socket

HOST = '127.0.0.1'
PORT = 8080

# Create TCP socket
client_socket = socket.socket(
    socket.AF_INET,
    socket.SOCK_STREAM
)

# Connect to server
client_socket.connect((HOST, PORT))

# Construct HTTP GET request
http_request = (
    "GET / HTTP/1.1\r\n"
    f"Host: {HOST}:{PORT}\r\n"
    "User-Agent: PythonSocketClient/1.0\r\n"
    "Connection: close\r\n"
    "\r\n"
)

# Send request
client_socket.sendall(
    http_request.encode('utf-8')
)

# Receive response
response = b""

while True:
    data = client_socket.recv(1024)

    if not data:
        break

    response += data

# Display response
print("--- HTTP Response Received ---")
print(response.decode('utf-8'))

# Close socket
client_socket.close()
