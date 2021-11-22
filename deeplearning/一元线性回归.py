import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
from  sklearn import metrics
pizza=pd.read_csv("pizza.csv",index_col='ld')
pizza.head()
dia=pizza.loc[:,'Diameter'].values
price=pizza.loc[:,'Price'].values
#print(dia)
#print(price)
#dia_new=dia.T
#print(dia_new.shape)
print(price.shape)

dia_new=np.mat(dia).reshape(-1,1)
print(dia_new.shape)
#打印散点图
#plt.scatter(dia,price)
#plt.show()

#将dia矩阵添加一个 为 1 的特征
one_colum=np.ones((dia_new.shape[0],1))
print(one_colum.shape)
x_new=np.concatenate((one_colum,dia_new),axis=1)
#print(x_new)

#手动计算最小二乘法
theta=np.dot(np.dot(np.linalg.inv(np.dot(x_new.T,x_new)),x_new.T),price)
print(theta)


#梯度下降法
learing_rate=0.1
step=14
theta=np.zeros([2,1],dtype=np.float32)
for i in range(step):
    grad=np.dot(np.dot(x_new.T,x_new),theta)-np.dot(x_new.T,price).reshape(-1,1)
   # grad = np.dot(np.dot(X_train.T, X_train), theta) - np.dot(X_train.T, y_train).reshape(-1, 1)
    theta=theta-learing_rate*grad
    loss=np.sqrt(np.sum((np.dot(x_new,theta)-price)**2))
    #theta = theta - learning_rate * grad
    #loss = np.sqrt(np.sum((np.dot(X_train, theta) - y_train) ** 2))
    print('loss=',loss)
print('theta=',theta)

#导入模型
model=LinearRegression()
#训练模型
model.fit(dia_new,price)
#打印w
print(model.coef_)
#打印b
print(model.intercept_)

#预测价格
predict_price=model.predict(dia_new)
#mse
mse=metrics.mean_squared_error(price,predict_price)
print('MSE: ',mse)
#rmse
rmse=np.sqrt(mse)
print('RMSE:',rmse)
#r2
r2=metrics.r2_score(price,predict_price)
print('r2: ',r2)

w=model.coef_
b=model.intercept_
x0=min(dia)
x1=max(dia)
y0=w*x0+b
y1=w*x1+b
plt.scatter(dia,price)
plt.plot([x0,x1],[y0,y1],c='r',alpha=0.5)
#plt.show()

# def predict():
#     a=eval(input('请输入pizze的半径：'))
#     price_new=a*w+b
#     print('gaipizza的价格为：',price_new)
#
# predict()