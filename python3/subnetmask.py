
ip = input("IP Address :")
sub = input("Subnet Mask :")
if sub == "":
    sub = "255.255.255.0"
    print("Default Subnet Mask : {0}".format(sub))
ip_arr = ip.split('.')

ip_len = len(ip_arr)
for i in range(ip_len):
    ip_arr[i] = int(ip_arr[i])
#####################################################################################
print("-"*40)
#     ####################################################################################
sub_arr = sub.split('.')

sub_len = len(sub_arr)

for i in range(0,sub_len):
    sub_arr[i] = int(sub_arr[i])

net_arr =[0]*sub_len
net_str = ""

for i in range(0,sub_len):
    net_arr[i] = (ip_arr[i] & sub_arr[i])
    net_arr[i] = str(net_arr[i])
#     #####################################################    
net_str = ".".join(net_arr)
print(net_str)

# #----------------------------------------------------------------------------------