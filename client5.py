import socket 

 

HOST = '127.0.0.1' 

PORT = 8053 

 

# Create a UDP socket 

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 

client_socket.settimeout(2.0)  # Set 2-second timeout 

 

domain_to_lookup = "google.com" 

 

try: 

    print(f"Querying DNS server for IP of: {domain_to_lookup}") 

     

    # Send domain query over UDP 

    client_socket.sendto(domain_to_lookup.encode('utf-8'), (HOST, PORT)) 

 

    # Receive IP resolution response 

    ip_address, _ = client_socket.recvfrom(1024) 

    print(f"Resolved IP: {ip_address.decode('utf-8')}") 

 

except socket.timeout: 

    print("DNS Request timed out.") 

finally: 

    client_socket.close() 
