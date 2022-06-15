#This assignment was to calculate investment's future value.
def main():
    print("This program calculates the future value of a investment.")
#These are the variables requested from the user to calculate the Investment future
    principal = float(input("Enter the initial principal: "))
    apr = float(input("Enter the annual interest rate(0.05=5%): "))
    period = int(input("Enter the number of periods: "))
    duration = int(input("Enter the duration(years): "))
#This function calculates the new principal by applying the interest over time    
    for i in range(duration*period):
        principal = principal+(principal * (apr/period))
#This prints the new principal
    newPrincipal = "${:.2f}".format(principal)
    print("The value in",duration,"years is:", newPrincipal)
main()

