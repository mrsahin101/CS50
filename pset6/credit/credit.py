from cs50 import get_string
import math
import sys

# Prompting user for input.
while True:
    number = get_string("Credit card number:")
    nDigits = math.floor(math.log10(abs(int(number)))) + 1
    if nDigits < 13:
        print("INVALID")
        sys.exit(1)
    if nDigits >= 13:
        break

thesum = 0
temp = 0
temp_one = 0
temp_two = 0

# Checking for total sum. We do same math magic to get numbers to digits

for i in range(0, len(number), 1):
    if len(number) % 2 == 0:
        if i % 2 == 0:
            temp = (int(number[i])) * 2
            if temp > 9:
                temp_one = int(math.floor(temp / 10))
                temp_two = int(((temp * 10) - 100) / 10)
                thesum += temp_one
                thesum += temp_two
            else:
                thesum += temp
        else:
            thesum += int(number[i])
    else:
        if i % 2 == 0:
            thesum += int(number[i])
        else:
            temp = (int(number[i])) * 2
            if temp > 9:
                temp_one = int(math.floor(temp / 10))
                temp_two = int(((temp * 10) - 100) / 10)
                thesum += temp_one
                thesum += temp_two
            else:
                thesum += temp
if thesum % 10 == 0:
    if len(number) == 15 and int(number[0]) == 3 and (int(number[1]) == 4 or int(number[1]) == 7):
        print("AMEX")
    elif len(number) == 16 and int(number[0]) == 5 and (int(number[1]) == 1 or int(number[1]) == 2 or int(number[1]) == 3 or int(number[1]) == 4 or int(number[1]) == 5):
        print("MASTERCARD")
    elif (len(number) == 13 or len(number) == 16) and int(number[0]) == 4:
        print("VISA")

else:
    print("INVALID")