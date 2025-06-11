import numpy as np
import matplotlib.pyplot as plt

FILE = "quantities.dat"

def main() -> None:
    # unpack entropy file
    step, S, M= np.loadtxt(FILE, skiprows=1, unpack=True)

    _, ax = plt.subplots(1, 2, figsize=(12, 5), sharex=True)

    ax[0].plot(step, S)
    ax[0].set_xlabel("MC Step")
    ax[0].set_ylabel(r"$S/k_B N$")
    ax[0].grid(True)

    ax[1].plot(step, M)
    ax[1].set_xlabel("MC Step")
    ax[1].set_ylabel(r"$M/N$")
    ax[1].grid(True)

    plt.show()

if __name__ == "__main__":
    main()
