text = input("Enter a text\n")

while True:
    old = input("\nEnter the part you wanna change\n")
    new = input("\nEnter the new part\n")

    text = text.replace(old, new)

    print("\nThe new text")
    print(text + "\n")

    repeat = input("Enter 'r' to repeat over the same text\n")
    if repeat != "r":
        break
