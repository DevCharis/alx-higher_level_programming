#!/usr/bin/python3
for i in range(26):
    print("{:c}".format(122 - i + (i % 2) * 32), end="")
for i in range(26):
    char = chr(122 - i)  # Start from 'z' (122) and go to 'a'
    if i % 2 == 0:
        print(char, end="")
    else:
        print(char.upper(), end="")
