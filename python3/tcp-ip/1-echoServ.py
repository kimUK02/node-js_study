import socket

serv_sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
serv_sock.bind(('127.0.0.1',8585))
serv_sock.listen(0)

client_socket, addr = serv_sock.accept()
data = client_socket.recv(65535)
client_socket.send(data)
print("recived Data",data.decode())