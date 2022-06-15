#This program calculates of the surface area and volume of an sphere
#from user inputted radius
from math import pi
#Defining the surface area function
def sphere_area(r):
    return (4*pi*r*r)
#Defining the volume function
def sphere_volume(r):
    return((4/3)*pi*r*r*r)
#Requests the radius from the user and prints the area amd volume
def main():
    r=float(input("Enter the radius of spehere: "))
    area=sphere_area(r)
    volume=sphere_volume(r)

    print("The surface area of the sphere is : ",area)
    print("Volume of the sphere is : ",volume)

main()
