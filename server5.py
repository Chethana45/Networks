import socket 

 

HOST = '127.0.0.1' 

PORT = 8053  # Using custom UDP port for testing 

 

# Simple mock domain database 

DNS_RECORDS = { 

    "example.com": "93.184.216.34", 

    "google.com": "142.250.190.46", 

    "localhost": "127.0.0.1" 

} 

 

# Create a UDP socket 

dns_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 

dns_socket.bind((HOST, PORT)) 

 

print(f"DNS Server listening on UDP {HOST}:{PORT}...") 

 

while True: 

    # Receive hostname query and client address 

    data, client_address = dns_socket.recvfrom(1024) 

    domain_query = data.decode('utf-8').strip() 

     

    print(f"Received query for: {domain_query}") 

 

    # Resolve domain or return default failure message 

    resolved_ip = DNS_RECORDS.get(domain_query.lower(), "NXDOMAIN (Not Found)") 

 

    # Send answer back to client 

    dns_socket.sendto(resolved_ip.encode('utf-8'), client_address) 

  
