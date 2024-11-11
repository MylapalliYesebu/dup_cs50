import pandas as pd
import numpy as np

from sklearn import datasets

wine = datasets.load_wine()

print(wine.feature_names)


print(wine.target_names)



x=pd.DataFrame(wine['data'])
x.head()
print(x)


print(wine.target)


from sklearn.model_selection import train_test_split

x_train,x_test,y_train,y_test = train_test_split(wine.data,wine.target,test_size=0.30,random_state=100)

from sklearn.naive_bayes import GaussianNB 

gnb = GaussianNB()
gnb.fit(x_train,y_train)

y_pred = gnb.predict(x_test)
print(y_pred)

from sklearn import metrics
print(metrics.accuracy_score(y_test,y_pred))

from sklearn.metrics import confusion_matrix
print(np.array(confusion_matrix(y_test,y_pred)))
print()

