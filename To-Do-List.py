st = []
done = []
n = int(input("Enter the number of works: "))
for i in range(1, n+1):
    work = input(f"{i}. ")
    st.append(work.upper())
    do = input("Is it done? (Y/N) ")
    done.append(do)

j = 1
if 'Y' in done:
    print("\n\n====    COMPLETED LIST   ====")
    for i in range(1, n+1):
        if done[i-1] == 'Y':
            print(f"{j}. {st[i-1]}")
            j += 1

j = 1
if 'N' in done:
    print("\n\n====    TO-DO-LIST    ====")
    for i in range(1, n+1):
        if done[i-1] == 'N':
            print(f"{j}. {st[i-1]}")
            j += 1
