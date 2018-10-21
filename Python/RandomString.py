import string
import random

var1 = input("How many times would you like to generate a random string? ")

for x in range(var1):
    var2 = input("How many characters would you like the string to be? ")
    print ''.join(random.choice(string.ascii_uppercase+string.ascii_lowercase+string.digits) for _ in range(var2))
    
