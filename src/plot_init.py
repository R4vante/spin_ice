# plot_ice.py
import numpy as np
import matplotlib.pyplot as plt

N = 10
grid = np.zeros((N, N, 4), dtype=int)

with open("ice_grid.txt") as f:
    for i, line in enumerate(f):
        values = line.strip().split()
        for j, val in enumerate(values):
            grid[i, j] = list(map(int, val))

# pijlen tekenen
fig, ax = plt.subplots(figsize=(8, 8))
for i in range(N):
    for j in range(N):
        x, y = j, N - i
        u, d, l, r = grid[i, j]

        if u: ax.arrow(x, y, 0, 0.4, head_width=0.1, color='blue')
        else: ax.arrow(x, y + 0.4, 0, -0.4, head_width=0.1, color='red')

        if d: ax.arrow(x, y, 0, -0.4, head_width=0.1, color='blue')
        else: ax.arrow(x, y - 0.4, 0, 0.4, head_width=0.1, color='red')

        if l: ax.arrow(x, y, -0.4, 0, head_width=0.1, color='blue')
        else: ax.arrow(x - 0.4, y, 0.4, 0, head_width=0.1, color='red')

        if r: ax.arrow(x, y, 0.4, 0, head_width=0.1, color='blue')
        else: ax.arrow(x + 0.4, y, -0.4, 0, head_width=0.1, color='red')

ax.set_xlim(-1, N)
ax.set_ylim(-1, N)
ax.set_aspect('equal')
ax.axis('off')
plt.title("Six-Vertex Ice Model")
plt.show()

