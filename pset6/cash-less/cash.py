from cs50 import get_float

coins = 0

# Prompting user for input

while True:
    cash = get_float("Change owed:")
    if cash > 0:
        break
cents = round(cash*100)

# Calculating coins

while cents >= 1:
    if cents - 25 >= 0:
        cents -= 25
        coins += 1
        
    elif cents - 10 >= 0:
        cents -= 10
        coins += 1
    
    elif cents - 5 >= 0:
        cents -= 5
        coins += 1
        
    elif cents - 1 >= 0:
        cents -= 1
        coins += 1
        
# Printing minimum number of coins
print(coins)