
import crypt

def testpass(cryptpass):
    salt = cryptpass[0:2]
    with open('dictionary.txt', 'r') as dictfile:
        for word in dictfile.readlines():
            word = word.strip('\n')
            cryptword = crypt.crypt(word, salt)
            if cryptword == cryptpass:
                print('[+] Found Password: ' + word + '\n')
                return
        print('[-] Password Not Found.\n')
        return


if __name__ == '__main__':
    with open('passwords.txt', 'r') as pass_file:
        for line in pass_file.readlines():
            if ':' in line:
                user = line.split(':')[0]
                cryptpass = line.split(':')[1].strip(' ')
                print('[*] Cracking Password For: ' + user)
                testpass(cryptpass)