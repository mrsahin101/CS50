from cs50 import get_int

# Prompting user for input until its in range

while True:
    height = get_int("Height:")
    if height > 0 and height < 9:
        break

# Printing out desired structure 

for i in range(height):
    for j in range(height - i - 1):
        print(end=" ")
    for k in range(i + 1):
        print("#", end="")
    print(end="  ")
    for ith in range(i + 1):
        print("#", end="")
    print()
