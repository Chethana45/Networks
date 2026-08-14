import socket 

 

# Server details 

host = "example.com" 

port = 80 

 

# 1. Create TCP socket 

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 

 

# 2. Connect to web server 

client_socket.connect((host, port)) 

 

# 3. Create HTTP request 

request = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n" 

 

# 4. Send request 

client_socket.sendall(request.encode()) 

 

# 5. Receive response 

response = b"" 

 

while True: 

    data = client_socket.recv(4096) 

 

    if not data: 

        break 

 

    response += data 

 

# 6. Close TCP connection 

client_socket.close() 

 

# 7. Separate HTTP headers and webpage body 

headers, body = response.split(b"\r\n\r\n", 1) 

 

print("HTTP RESPONSE HEADERS:") 

print(headers.decode(errors="ignore")) 

 

# 8. Save webpage 

with open("webpage.html", "wb") as file: 

    file.write(body) 

 

print("\nWebpage downloaded successfully!") 

print("Saved as webpage.html") 
