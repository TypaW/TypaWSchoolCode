#A very simple program that counts the words in the file.
name = input("Enter the filename: ")
tFile = open(name,"r")
num_words = 0

for lines in tFile:
    for words in lines.split():
        num_words += 1
#The line below prints out the number of words in the file
print (num_words)
