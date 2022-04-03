# asking the user for mode
mode = input("Enter 'e' to encode, 'd' to decode: ")

# if the user wants to encode
if mode == "e":
    # getting user input
    text = input("Enter text: ")
    # seperating the text into words
    words = text.split()
    # copying the words into a new list
    temp = words
    # getting rid of duplicates
    words = list(dict.fromkeys(words))
    # sorting the words in alphabetical order
    words.sort()
    # creating formatted text
    formatted_text = ""
    # looping through the words
    count = -1
    for word in words:
        count += 1
        for i in range(len(temp)):
            if word == temp[i]:
                temp[i] = str(count)
    # creating a dictionary
    dict = open("dictionary.txt", "w+")
    # writing the words to the dictionary
    for i in range(len(words)):
        dict.write(words[i] + "\n")
    # closing the dictionary
    dict.close()
    # creating a zip file
    zipped = open("zip.txt", "w+")
    # writing the text to the zip file
    for i in range(len(temp)):
        zipped.write(temp[i] + " ")
    # closing the zip file
    zipped.close()
    print("Your text has been zipped and saved to zip.txt")
elif mode == "d":
    # opening the dictionary file
    dict = open("dictionary.txt", "r")
    # adding the words to a list
    words = []
    for line in dict:
        words.append(line.strip()) # strip() removes the newline character
    # opening the zip file
    zipped = open("zip.txt", "r")
    # creating a temp list to store the unzipped text
    temp = ""
    for line in zipped:
        temp += line
    temp = temp.split()
    # creating a raw text file
    raw_text = ""
    # looping through the zip file
    for i in range(len(temp)):
        for j in range(len(words)):
            if temp[i] == str(j):
                raw_text += words[j] + " "
    # closing the dictionary
    dict.close()
    # closing the zip file
    zipped.close()
    # printing the unzipped text
    print(raw_text)
else:
    print("Invalid mode")
