import numpy as np
import matplotlib.pyplot as plt

# Grootte van de lattice
L = 5  # LxL grid

# Genereer een willekeurige bindingstoestand voor de lattice
# bond[0] = 1 betekent er is een verbinding naar boven (↑)
# bond[1] = 1 betekent er is een verbinding naar beneden (↓)
# bond[2] = 1 betekent er is een verbinding naar links (←)
# bond[3] = 1 betekent er is een verbinding naar rechts (→)
bonds = np.random.randint(0, 2, size=(L, L, 4))

# Functie om de lattice te tekenen met pijltjes
def plot_lattice(L, bonds):
    fig, ax = plt.subplots(figsize=(8, 8))

    # Grid en cellen tekenen
    ax.set_xticks(np.arange(L + 1) - 0.5, minor=True)
    ax.set_yticks(np.arange(L + 1) - 0.5, minor=True)
    ax.grid(which='minor', color='k', linestyle='-', linewidth=2)

    # Pijlen tekenen
    for i in range(L):
        for j in range(L):
            # Teken pijltjes naar boven (↑)
            if bonds[i][j][0] == 1 and i > 0:
                ax.annotate('', xy=(j, i), xytext=(j, i-1), 
                            arrowprops=dict(facecolor='blue', edgecolor='blue', arrowstyle='->', lw=1))
            # Teken pijltjes naar beneden (↓)
            if bonds[i][j][1] == 1 and i < L-1:
                ax.annotate('', xy=(j, i), xytext=(j, i+1), 
                            arrowprops=dict(facecolor='blue', edgecolor='blue', arrowstyle='->', lw=1))
            # Teken pijltjes naar links (←)
            if bonds[i][j][2] == 1 and j > 0:
                ax.annotate('', xy=(j, i), xytext=(j-1, i), 
                            arrowprops=dict(facecolor='blue', edgecolor='blue', arrowstyle='->', lw=1))
            # Teken pijltjes naar rechts (→)
            if bonds[i][j][3] == 1 and j < L-1:
                ax.annotate('', xy=(j, i), xytext=(j+1, i), 
                            arrowprops=dict(facecolor='blue', edgecolor='blue', arrowstyle='->', lw=1))

    # Asinstellingen
    ax.set_xlim(-0.5, L - 0.5)
    ax.set_ylim(L - 0.5, -0.5)
    ax.set_xticks([])
    ax.set_yticks([])

    plt.title("Lattice Visualisatie met Pijlen")
    plt.show()

# Visualiseer de lattice
plot_lattice(L, bonds)

