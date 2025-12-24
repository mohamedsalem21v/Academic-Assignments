grades = {}
while (True):
    choice = int(input("1. Add student\n"
                       "2. Update grade\n"
                       "3. Show all\n"
                       "4.Exit\n"))
    if choice == 1:
        name = input("Enter student name: ")
        grade = int(input("Enter the grade: "))
        grades[name] = grade

        print(f"Added {name} with grade {grade}.\n")

    elif choice == 2:
        name = input("Enter student name: ")

        found = False
        for i in grades.keys():
            if (i == name):
                found = True

        if found == False:
            print("Not found!\n")
            continue

        grade = int(input("Enter the new grade: "))
        grades[name] = grade
        print(f"Updated {name} to grade {grade}.\n")

    elif choice == 3:
        for key, value in grades.items():
            print(f"Student name: {key}, grade: {value}")
        print()

    elif (choice == 4):
        print("Exiting the program.")
        break
    
    else:
        print("Invalid choice. Please try again.\n")
