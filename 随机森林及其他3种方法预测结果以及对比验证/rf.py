import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import csv
import neuralnetwork as NN
from sklearn.model_selection import train_test_split  # random forest
from sklearn.ensemble import RandomForestClassifier
from sklearn.ensemble import RandomForestRegressor
#tree
from sklearn import tree
#NB
from sklearn.naive_bayes import GaussianNB
from sklearn.naive_bayes import BernoulliNB
from sklearn.naive_bayes import MultinomialNB
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score
from sklearn.metrics import confusion_matrix
from sklearn.metrics import classification_report
#SVM
from sklearn import svm
'''
from NeuralNetwork import NeuralNetwork
from keras.models import Sequential
from keras.layers import Dense, Dropout
from keras.optimizers import RMSprop
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
mnist=input_data.read_data_sets('MNIST_data/',one_hot=True)
'''
csv_file_1=open('train.csv')    #打开csv文件
csv_reader_lines_1 = csv.reader(csv_file_1)   #逐行读取csv文件
data1=[]    #创建列表准备接收csv各行数据
num = 0
for one_line in csv_reader_lines_1:
    one_line=list(map(float,one_line))
    data1.append(one_line)    #将读取的csv分行数据按行存入列表‘date’中
    num = num + 1    #统计行数（这里是学生人数）
'''
i=0
while i < num:
    print (date[i])    #访问列表date中的数据验证读取成功（这里是打印所有学生的姓名）
    i = i+1
'''
csv_file_2=open('train_y.csv')    #打开csv文件
csv_reader_lines_2 = csv.reader(csv_file_2)   #逐行读取csv文件
data2=[]    #创建列表准备接收csv各行数据
num = 0
for one_line in csv_reader_lines_2:
    one_line=list(map(float,one_line))
    data2.append(one_line)    #将读取的csv分行数据按行存入列表‘date’中
    num = num + 1    #统计行数（这里是学生人数）
#random forest
x_train,x_test,y_train,y_test = train_test_split(data1,data2,test_size=0.3,random_state=0)
rf = RandomForestClassifier()
rf.fit(x_train,y_train)
pre_test_rf = rf.predict(data1)
print(accuracy_score(pre_test_rf, data2))
conf_mat = confusion_matrix(data2, pre_test_rf)
print(conf_mat)
print(classification_report(data2, pre_test_rf))
#tree
clf=tree.DecisionTreeClassifier()
clf=clf.fit(x_train,y_train)
pre_test = clf.predict(data1)
print(accuracy_score(pre_test, data2))
conf_mat = confusion_matrix(data2, pre_test)
print(conf_mat)
print(classification_report(data2, pre_test))
#贝叶斯
NB=BernoulliNB()
NB.fit(x_train,y_train)
pre_test=NB.predict(data1)
print(accuracy_score(pre_test, data2))
conf_mat = confusion_matrix(data2, pre_test)
print(conf_mat)
print(classification_report(data2, pre_test))
#SVM
svm = svm.SVC()
svm.fit(x_train, y_train)
pre_test=svm.predict(data1)
print(accuracy_score(pre_test, data2))
conf_mat = confusion_matrix(data2, pre_test)
print(conf_mat)
print(classification_report(data2, pre_test))
print(classification_report(data2, pre_test))
#Regressor回归
rf_regressor = RandomForestRegressor()
rf_regressor.fit(x_train,y_train)
pre_test_regressor = rf_regressor.predict(data1)

#Neural Networks
from tensorflow import keras
from tensorflow.keras.utils import to_categorical
from keras.models import Sequential
from keras.layers.core import Dense, Activation
model = Sequential()  #层次模型
model.add(Dense(31,activation= 'linear', input_shape=(2740,31), use_bias= True)) #输入层

model.add(Dense(20,input_shape=(2740,20)))
model.add(Dense(15,input_shape=(2740,15)))
model.add(Dense(10,input_shape=(2740,10)))
#model.add(Dense(5,input_shape=(2740,5)))
model.add(Dense(6,activation='softmax',input_shape=(2740,6)))  #输出层
model.compile(loss='categorical_crossentropy',optimizer='adam',metrics=['accuracy']) #编译模型
#print(np.shape(x_train),np.shape(y_train))

y_train = to_categorical(y_train)
#print(y_train)
x_train = np.array(x_train)
y_train = np.array(y_train)
model.fit(x_train, y_train, batch_size=32, epochs=1000, verbose=1) #训练模型1000次
data3 = to_categorical(data2)
data1 = np.array(data1)
data3 = np.array(data3)
score=model.evaluate(data1,data3)
print(score)

pre_test=model.predict(data1)
print(pre_test)
pre_test =np.argmax(pre_test, axis=1)

print(accuracy_score(pre_test, data2))
conf_mat = confusion_matrix(data2, pre_test)
print(conf_mat)
print(classification_report(data2, pre_test))
print(classification_report(data2, pre_test))

for i in pre_test_regressor:
    a=(str(i))
    f1 = open('output.txt', 'a')
    f1.write(a)
    f1.write('\n')

f1.close()
#auc_score = roc_auc_score(Y_test,pre_test)
#pre_score = precision_score(Y_test,pre_test)


#print("auc_score,pre_score:",auc_score,pre_score)
