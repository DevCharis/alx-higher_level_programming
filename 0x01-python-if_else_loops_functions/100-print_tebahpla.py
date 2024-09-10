#!/usr/bin/python3
for i in range(26):
    if i % 2 == 0:
        print(chr(122 - i), end="")  # Lowercase
    else:
        print(chr(90 - i), end="")    # Uppercase
