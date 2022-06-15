#This assignment was created to calculate the Greatest Common Divisor
#The first function is defining gcd to be called upon
def gcd(a, b):
  
    while b:
        a, b = b, a%b
    return a

#The following fuctions requests the input and informs the user to input only
#postive numbers then prints the GCD after valid input is recieved
while True: 
  
    while True:

        n1=int(input('\nEnter a positive whole number: '))

        if n1==0 or n1 < 0:
            print('The number entered is not a positive whole number!')
            continue
        else:
            break
  
    while True:
      
        n2=int(input('Enter a second positive whole number: '))

        if n2==0 or n2 <0:
            print('The number entered is not a positive whole number!')
            continue
        else:
            break
      

    if n1 < n2:
        print('First number should be greater than second number')
        continue

    r=gcd(n1,n2)

    print('gcd(%d,%d) is %d \n' %(n1,n2,r))


#The while statement requests for user to input Y to continue or N to end
    while True:
      
        choice=input('Compute another (Y/N) ')

        if choice.lower() == 'yes' or choice.lower()=='y':
            break
        elif choice.lower() == 'no' or choice.lower()=='n':
            break
        else:
            print('Enter an valid character of Yes or Y/No or N')
            continue
      
    if choice.lower() == 'yes' or choice.lower()=='y':
            continue
    elif choice.lower() == 'no' or choice.lower()=='n':
            break
