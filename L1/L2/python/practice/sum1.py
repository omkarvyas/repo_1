print("Type Intergers, each floowed by Enterl or just enter to finish")

total = 0
count = 0

while True:
    line = input("Integer: ")
    if line:
        try:
            number = int(line)
        except ValueError as err:
            print(err)
            continue
        total += number
        count += 1
    else:
        break

    if count:
        print("count = ", count, "total = ", total, "mean = ", total/count)


        
        
