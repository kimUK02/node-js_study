import socket
socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
socket.connect(('127.0.0.1',8585))
socket.send("hello".encode())
data = socket.recv(65535)
print("recived data:",data)