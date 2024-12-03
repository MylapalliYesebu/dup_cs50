# Python program to show a linear graph
import matplotlib.pyplot as plt  # Corrected import statement

# Initializing the data
x = [10, 20, 30, 40]
y = [20, 25, 35, 55]

# Creating the figure and adding axes
fig = plt.figure(figsize=(5, 4))  # Corrected figure size
ax = fig.add_axes([0.1, 0.1, 0.8, 0.8])  # Axes positioned within the figure

# Plotting the datasets
ax.plot(x, y, label='Line 1')  # First dataset with label
ax.plot(y, x, label='Line 2')  # Second dataset with label

# Setting the title and labels
ax.set_title("Linear Graph")
ax.set_xlabel("X-Axis")
ax.set_ylabel("Y-Axis")

# Adding the legend
ax.legend()  # Automatically uses labels from the plot commands

# Displaying the plot
plt.show()
