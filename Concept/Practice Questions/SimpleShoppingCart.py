def show_cart(my_list):
    num = 1
    for i in my_list:
        print(f"item {num}: {i}")
        num += 1

cart = []
print("Add 3 items")
for i in range(3):
    item = input()
    cart.append(item)

rem = input("Add item to remove: ")
if rem in cart:
    cart.remove(rem)
else:
    print("Item not found")
print("-----------")

show_cart(cart)