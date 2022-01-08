from cs50 import get_int

# Forever loop until user gives input in range

while True:
    height = get_int("Height:")
    if height > 0 and height < 9:
        break

# Nested loop for printing out the pyramid

for i in range(height):
    for j in range(height - i - 1):
        print(end=" ")
    for k in range(i + 1):
        print("#", end="")
    print()
