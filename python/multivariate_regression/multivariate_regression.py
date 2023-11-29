import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv('realestate.csv')
column_names = ["No", "transaction date", "house age", "distance to the nearest MRT station", "number of convenience stores", "latitude", "longitude", "house price of unit area"]
data.columns = column_names
print(data.head())

# split the data into X and y
y = data["house price of unit area"].values.reshape(-1, 1)
X = data.iloc[:, 1:5].values

# scatter plot
plt.figure(figsize=(10, 6))
for i in range(X.shape[1]):
    plt.scatter(X[:, i], y, label=f"{column_names[i+1]}", alpha=0.5)
plt.title("Scatter Plot of Independent Variables vs. Dependent Variable")
plt.xlabel("Independent Variables")
plt.ylabel("House Price of Unit Area")
plt.legend()

# apply multivariate regression
def model(X, y, learning_rate, iterations):
    m = y.size  # number of data points
    theta = np.zeros([X.shape[1], 1])
    cost_list = []
    for i in range(iterations):
        y_pred = np.dot(X, theta)
        cost = (1 / (2 * m)) * np.sum(np.square(y_pred - y))

        d_theta = (1 / m) * np.dot(X.transpose(), (y_pred - y))
        theta = theta - learning_rate * d_theta

        cost_list.append(cost)
        if(i%(iterations/10)==0):
            print("Cost after iteration {}: {}".format(i, cost))
    return theta, cost_list

# set parameters
iteration = 100000
learning_rate = 0.0000000005

# run the model
theta, cost_list = model(X, y, learning_rate, iteration)

# plot the cost
rng = np.arange(0, iteration)
plt.figure(figsize=(10, 6))
plt.plot(rng, cost_list)
plt.show()