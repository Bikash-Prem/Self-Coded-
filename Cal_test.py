from Cal_mod import *
print("====    Simple Calculator    ====")
a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))
print('''1. Addition
2. Subtraction
3. Multiplication
4. Division (No decimal value)
5. Division (With decimal value)
6. Remainder of 1st divided by 2nd
7. 1st to the power of 2nd
8. Exit Calculator''')
choice = input("Enter the choice: ")

if choice == '8':
    print("BYE!")
else:
    if choice == "1":
        print("Result:", add(a, b))
    elif choice == "2":
        print("Result:", sub(a, b))
    elif choice == "3":
        print("Result:", mul(a, b))
    elif choice == "4":
        print("Result:", int_div(a, b))
    elif choice == "5":
        print("Result:", float_div(a, b))
    elif choice == "6":
        print("Result:", remainder(a, b))
    elif choice == "7":
        print("Result:", power(a, b))
    else:
        print("Invalid choice.")
