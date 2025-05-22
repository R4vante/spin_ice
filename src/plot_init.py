import numpy as np
import matplotlib.pyplot as plt

N = 10
grid = np.zeros((N, N, 2), dtype=int)  # Alleen up en right

with open("ice_grid.txt") as f:
    for i, line in enumerate(f):
        values = line.strip().split()
        for j, val in enumerate(values):
            grid[i, j] = list(map(int, list(val)))

fig, ax = plt.subplots(figsize=(8, 8))
for i in range(N):
    for j in range(N):
        x, y = j, N - i  # om y-as om te draaien

        u, r = grid[i, j]

        ax.plot(x, y, 'ko', markersize=5)

        if u:
            ax.arrow(x, y - 1, 0, 1., head_width=0.15, color='blue', length_includes_head=True)
        else:
            ax.arrow(x, y + 1, 0, -1, head_width=0.15, color='red', length_includes_head=True)

        if r:
            ax.arrow(x - 1, y, 1, 0, head_width=0.15, color='blue', length_includes_head=True)
        else:
            ax.arrow(x + 1, y, -1, 0, head_width=0.15, color='red', length_includes_head=True)

ax.set_xlim(-1, N)
ax.set_ylim(-1, N)
ax.set_aspect('equal')
ax.axis('off')
plt.title("Six-Vertex Model")
plt.show()

