#1.Import Data

from sklearn.datasets import load_iris
iris = load_iris()
print("Feature Names:",iris.feature_names,"Iris Data:",iris.data,"Target Names:",iris.target_names,"Target:",iris.target)

#2. Split the data into Test and Data
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(
        iris.data, iris.target, test_size = .25)

#neighbors_settings = range(1, 11)
#for n_neighbors in neighbors_settings:

#3.Build The Model
from sklearn.neighbors import KNeighborsClassifier
clf = KNeighborsClassifier()
clf.fit(X_train, y_train)

#4.Calculate Accuracy of the Test  data with the trained data
print(" Accuracy=",clf.score(X_test, y_test))


#5 Calculate the prediction with the labels of the test data 
print("Predicted Data")
print(clf.predict(X_test))

prediction=clf.predict(X_test)

print("Test data :")
print(y_test)

#6 To identify the miss classification
diff=prediction-y_test
print("Result is ")
print(diff)
print('Total no of samples misclassied =', sum(abs(diff)))

