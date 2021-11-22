### 线性回归

1.给定数据集
$$
D={(x_1,y_1),(x_2,y_2),(x_3,y_3),(x_4,y_4)}……(x_n,y_n)
$$
希望可以得到
$$
f(x_i)=wx_i+b
$$
使得$f(x_i)$与$y_i$之间的差别尽可能小，这时我们引入损失函数
$$
loss（w,b)=\sum_{i=1}^{n}(f(x_i)-y_i^2)
$$
此损失函数是基于均方差来构造的，可通过最小二乘法来进行求解。

#### 1.一元线性回归

可直接对w和b求偏导，让其导数为零，即可求解出w,b

![](https://img-blog.csdnimg.cn/4b6e7245efa24f81834831f484c7f145.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA5piv5b-Y55Sf5ZWK,size_13,color_FFFFFF,t_70,g_se,x_16)

#### 2.多元线性回归

​	![](https://img-blog.csdnimg.cn/90f6abb1dfde4d6e853861811a76f229.jpg?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA5piv5b-Y55Sf5ZWK,size_20,color_FFFFFF,t_70,g_se,x_16)

x为特征矩阵，y为标签矩阵。假设函数为
$$
f(x_i)=w_1*x_1+w_2*x_2+w_3*x_3+……+w_i*x_i+w_0
$$
为了计算方便，我们给x添加一个特征1，

![](https://img-blog.csdnimg.cn/33393bf6db124e4e98c6a11abdeeeb39.jpg?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA5piv5b-Y55Sf5ZWK,size_20,color_FFFFFF,t_70,g_se,x_16)

则$f=WX$

损失函数为$loss=\sum_{i=1}^{m}(x_i*W-y_i）^2$

该函数可写成矩阵相乘形式，对矩阵进行求导，可解得
$$
w=(X^TX)^{-1}XY
$$
例子：希望通过分析pizza半径与价格的关系，来预测任意半径pizza的价格

![](https://img-blog.csdnimg.cn/1ca50faabb5a451b9c5dd0e02106adda.png)

```python

#导入必要的模块
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
from  sklearn import metrics
```


```python
pizza=pd.read_csv("pizza.csv",index_col='ld')
pizza.head()
dia=pizza.loc[:,'Diameter'].values
price=pizza.loc[:,'Price'].values

print(dia)
print(price)
dia_new=dia.T
print(dia_new.shape)
print(price.shape)
```

    [ 6  8 10 14 18]
    [ 7.   9.  13.  17.5 18. ]
    (5,)
    (5,)



```python
dia_new=np.mat(dia).reshape(-1,1)
print(dia_new.shape)
#打印散点图
plt.scatter(dia,price)
plt.show()

```

    (5, 1)




![](https://cdn.jsdelivr.net/gh/liwangshengya/picture/img/202111221307310.png)
    



```python
#将dia矩阵添加一个 为 1 的特征
one_colum=np.ones((dia_new.shape[0],1))
print(one_colum.shape)
x_new=np.concatenate((one_colum,dia_new),axis=1)
print(x_new)
```

    (5, 1)
    [[ 1.  6.]
     [ 1.  8.]
     [ 1. 10.]
     [ 1. 14.]
     [ 1. 18.]]

$$
 w=(X^TX)^{-1}XY
$$

```python
#手动计算最小二乘法
theta=np.dot(np.dot(np.linalg.inv(np.dot(x_new.T,x_new)),x_new.T),price)
print(theta)
```

    [[1.96551724 0.9762931 ]]



```python
#导入模型
model=LinearRegression()
#训练模型
model.fit(dia_new,price)
#打印w
print(model.coef_)
#打印b
print(model.intercept_)
```

    [0.9762931]
    1.965517241379315

对一个模型好坏的判断有MSE(均方误差)，RMSE（均方根误差），决定系数$R^2$等。
$$
MSE=\frac{1}{n}_sum_{i=1}^{m}w_i(y_i-\hat{y_i})^2
$$

$$
RMSE=\sqrt{MSE}
$$

$$
R^2=1-\frac{MSE}{var(\vec{y})}
$$

$R^2$越接大，拟合效果越好，越小则拟合效果越差

```python
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
```

    MSE:  1.7495689655172406
    RMSE: 1.3227127297781784
    r2:  0.9100015964240102



```python
#w
w=model.coef_
#截距
b=model.intercept_
x0=min(dia)
x1=max(dia)
y0=w*x0+b
y1=w*x1+b
plt.scatter(dia,price)
plt.plot([x0,x1],[y0,y1],c='r',alpha=0.5)
plt.show()
```


![](https://cdn.jsdelivr.net/gh/liwangshengya/picture/img/202111221307828.png)
    



```python

```

