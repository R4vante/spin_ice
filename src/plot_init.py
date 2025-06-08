import numpy as np
import matplotlib.pyplot as plt

N = 10
grid = np.zeros((N, N, 4), dtype=int)  # up, right, down, left

# Lees de configuratie in
with open("ice_grid_1.dat") as f:
    for i, line in enumerate(f):
        values = line.strip().split()
        for j, val in enumerate(values):
            grid[i, j] = list(map(int, list(val)))


print(grid)

# Maak de plot
fig, ax = plt.subplots(figsize=(8, 8))
for i in range(N):
    for j in range(N):
        x, y = j, N - i - 1  # N-i-1 om Y-as goed te richten (anders wordt het omgedraaid)

        u, r, d, l = grid[i, j]  # Pijlconfiguratie van de vertex

        ax.plot(x, y, 'ko', markersize=5)

        # Teken de pijlen met respect voor de richting (0 voor tegenovergestelde richting, 1 voor richting)
        if u == 1:  # Up-pijl wijst naar boven
            ax.arrow(x, y, 0, 1, head_width=0.15, color='blue', length_includes_head=True)  

        if d == 1:  # Up-pijl wijst naar boven
            ax.arrow(x, y, 0, -1, head_width=0.15, color='red', length_includes_head=True)  

        if r == 1:  # Right-pijl wijst naar rechts
            ax.arrow(x, y, 1, 0, head_width=0.15, color='blue', length_includes_head=True)

        if l == 1:  # Left-pijl wijst naar links
            ax.arrow(x, y, -1, 0, head_width=0.15, color='red', length_includes_head=True)

# Stijl de plot
ax.set_xlim(-1, N)
ax.set_ylim(-1, N)
ax.set_aspect('equal')
ax.axis('off')
plt.title("Six-Vertex Model — Full Arrows")
plt.show()

