INF = 9999

def dijkstra(graph, n, source):

    distance = [INF] * n
    visited = [False] * n

    distance[source] = 0

    for _ in range(n - 1):

        # Find the unvisited router
        # with the smallest distance
        min_distance = INF
        u = -1

        for i in range(n):
            if not visited[i] and distance[i] < min_distance:
                min_distance = distance[i]
                u = i

        # Mark router as visited
        visited[u] = True

        # Update neighboring routers
        for v in range(n):

            if (not visited[v]
                    and graph[u][v] != 0
                    and distance[u] + graph[u][v] < distance[v]):

                distance[v] = distance[u] + graph[u][v]

    print("\nShortest distances from Router", source)

    for i in range(n):
        print("Router", i, "=", distance[i])


# Main program

n = int(input("Enter number of routers: "))

print("Enter the cost matrix:")

graph = []

for i in range(n):
    row = list(map(int, input().split()))
    graph.append(row)

source = int(input("Enter source router: "))

dijkstra(graph, n, source)
