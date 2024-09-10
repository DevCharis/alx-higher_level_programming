#!/usr/bin/python3
for i in range(97, 123):
    if chr(i) != 'e' and chr(i) != 'q':  # Skip 'e' and 'q'
        print("{:c}".format(i), end="")
