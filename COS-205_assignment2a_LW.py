#This program's purpose is to calculate the area of an triangle
#by obtaining the sides from the user
import math 
print("Please input the x of the triangle: ")
x=int(input(""))
print("Please input the y of the triangle: ")
y=int(input(""))
print("Please input the z of the triangle: ")
z=int(input(""))
#The following lines calculate the perimeter and area of the triangle
p=(x+y+z)/2#perimeter
area = math.sqrt(p*(p-x)*(p-y)*(p-z))
print("The area of the triangle: ", area)
