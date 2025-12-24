phoneNumbers = {"Ahmed" : "01129694555" , "Omar" : "01134422344" , "Yossef" : "01123414583"}

phoneNumbers["Mohamed"] = "01124389335"
phoneNumbers["Ahmed"] = "01249386250"

phoneNumbers.pop("Omar")

for key,value in phoneNumbers.items():
    print(f"NAME: {key}, VALUE: {value}")