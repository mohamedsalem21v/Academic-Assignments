for i in range(1,16):
    if i%2 == 0:
        continue
    if i%5 == 0:
        print("Multiple of 5")
        pass
    print(f"Processing number {i}")