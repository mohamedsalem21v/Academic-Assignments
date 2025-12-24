def avg(*grades):
    cnt = 0
    sum = 0
    for i in grades:
        cnt += 1
        sum += i
    return sum/cnt

def get_result(*grades):
    if avg(*grades) >= 60.0:
        print("Pass")
    else:
        print("Fail")
name = input("Enter your name: ")
grades = list(map(float, input("Enter your three grades: ").split()))
print(name)
print(avg(*grades))
get_result(*grades)
