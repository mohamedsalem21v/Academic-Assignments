Subjects = int(input("Enter number of subjects: "))
print("Enter your grades: ")
grades = []
for i in range(Subjects):
    gr = int(input())
    grades.append(gr)

avg = 0.0
for i in grades:
    avg += i
avg = round(avg/Subjects)
grades.sort()

print("---------")
print(f"Highest grade: {grades[Subjects-1]}")
print(f"Lowest grade: {grades[0]}")
print(f"Average grade (rounded): {avg}")
print("----------")

if avg >= 85:
    print("Excellent")
elif avg >= 70:
    print("Good")
else:
    print("Needs Improvement")