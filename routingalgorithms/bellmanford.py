INF = 9999

n = int(input("Enter number of routers: "))

print("Enter the cost matrix:")
cost = []

for i in range(n):
    row = list(map(int, input().split()))

    for j in range(n):
        if row[j] == 0 and i != j:
            row[j] = INF

    cost.append(row)

# Distance Vector algorithm
for k in range(n):
    for i in range(n):
        for j in range(n):

            new_distance = cost[i][k] + cost[k][j]

            if new_distance < cost[i][j]:
                cost[i][j] = new_distance

print("\nShortest Path Cost Matrix:")

for i in range(n):
    for j in range(n):
        if cost[i][j] == INF:
            print("INF", end="\t")
        else:
            print(cost[i][j], end="\t")
    print()
