import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
 # ### Step 2 : Load the inbuilt data or the csv/excel file into pandas data frame and clean the data
df = pd.read_csv("Mallcustomer.csv")
df.head()
# ### Step 3 : Create the Feature Matrix and check the top 5 rows
x = df.iloc[:, 1:-1].values
print("x[5] = ",x[:5]) #Encode Gender Column using LabelEncoder
from sklearn.preprocessing import LabelEncoder
x[:, 0] = LabelEncoder().fit_transform(x[:, 0])
print("After Label encoder : ", x[:5])
# ### Step 4 : Instantiate a EM Model and K-Means Model and train them
from sklearn.mixture import GaussianMixture
from sklearn.cluster import KMeans
em_cluster = GaussianMixture(n_components = 5)
km_cluster = KMeans(n_clusters=5)
em_cluster.fit(x)
km_cluster.fit(x)
# ### Step 6 : Use the model to predict the cluster labels
em_predictions = em_cluster.predict(x)
km_predictions = km_cluster.predict(x)
print("EM prediction : ", em_predictions)
print("K-Means prediction : ", km_predictions)
# ### Step 7 : Visualize the Clusters from both EM and K-Means
import matplotlib.pyplot as plt
#plt.scatter(x[:, 1], x[:, 2], c=em_predictions)
plt.scatter(x[:, 1], x[:, 2],c=em_predictions)
plt.show()
plt.scatter(x[:, 1], x[:, 2],c=km_predictions)
