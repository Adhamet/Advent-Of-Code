#Part 1

import hashlib

hashNum = 0

while(True):
    hashNumBytes = bytes(str(hashNum) , 'utf-8')
    bencryption = hashlib.md5(b"yzbqklnj"+hashNumBytes)
    aencryption = bencryption.hexdigest()

    if aencryption[0:5] == "00000":
        print(hashNum)
        break
    else: 
        hashNum += 1 
        if (hashNum % 10000 == 0):
            print(hashNum)


#Part 2, just change the range of aencryption to 0:6 and add a 0 in its equivalent.