#https://stackoverflow.com/questions/56657814/creating-an-algorithm-to-solve-a-problem-in-python#:~:text=Eight%20houses%2C%20represented%20as%20cells,0%20represents%20an%20inactive%20cell.
def cellCompete(states, days):
    # WRITE YOUR CODE HERE
    # pass
    s = len(states)
    for day in range(days):
        houses = [0]+states+[0]
        states = [houses[i-1]^houses[i+1] for i in range(1, s+1)]
    return states


#gcd for multiple numbers
def find_gcd(x, y): 
    while(y): 
        x, y = y, x % y 
    return x

def generalizedGCD(num, arr):
    # WRITE YOUR CODE HERE
    #pass
    num1 = arr[0] 
    num2 = arr[1] 
    gcd = find_gcd(num1, num2) 
    for i in range(2, num):
        gcd = find_gcd(gcd, arr[i])
    return gcd