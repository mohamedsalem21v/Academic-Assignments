for i in range(1, 21):
    if i % 2 == 0:
        continue
    elif i % 5 == 0:
        print("Found a multiple of 5!")
        pass
    else:
        print("Processing number:", i)

print("Done analyzing numbers!")