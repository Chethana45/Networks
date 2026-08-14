import socket

HOST = '127.0.0.1'
PORT = 8080

# Create TCP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Allow reuse of address
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# Bind socket to host and port
server_socket.bind((HOST, PORT))

# Listen for incoming connections
server_socket.listen(1)

print(f"HTTP Server listening on http://{HOST}:{PORT}...")

while True:

    # Accept client connection
    client_connection, client_address = server_socket.accept()

    # Receive HTTP request
    request = client_connection.recv(1024).decode('utf-8')

    print(f"\n--- Received Request from {client_address} ---")

    if request:
        print(request.splitlines()[0])
    else:
        print("Empty request")

    # HTML response body
    html_body = """
<html>
<body>
<h1>Hello! HTTP Server Simulation</h1>
</body>
</html>
"""

    # HTTP response
    http_response = (
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html; charset=UTF-8\r\n"
        f"Content-Length: {len(html_body)}\r\n"
        "Connection: close\r\n"
        "\r\n"
        + html_body
    )

    # Send response
    client_connection.sendall(
        http_response.encode('utf-8')
    )

    # Close connection
    client_connection.close()
