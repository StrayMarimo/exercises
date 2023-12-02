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

for i in range(X.shape[1]):
    column_values = X[:, i]
    max_value = column_values.max()
    X[:, i] = column_values / max_value

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
    y = np.dot(X, theta)
    return theta, cost_list, y

# set parameters
iteration = 10000
learning_rate = 0.0005

# run the modelt
theta, cost_list, new_y = model(X, y, learning_rate, iteration)

# scatter plot
plt.figure(figsize=(10, 6))
for i in range(X.shape[1]):
    plt.scatter(X[:, i], y, color='black')
    plt.scatter(X[:, i], new_y,color='blue')
plt.xlabel('Scaled Feature Values')
plt.ylabel('Target Variable')
plt.title('Original vs Predicted Y values')
plt.legend()

# plot the cost
rng = np.arange(0, iteration)
plt.figure(figsize=(10, 6))
plt.title("Cost over Iterations")
plt.xlabel("Number of Iterations")
plt.ylabel("Cost")
plt.plot(rng, cost_list)
plt.show()