import torch
import torch.nn as nn
import numpy as np

# 构建输入
# x = torch.FloatTensor([[0, 0], [0, 1], [1, 0], [1, 1]])
# print(x.shape)
# y = torch.FloatTensor([1, 0, 0, 1])
# print(y.shape)

x = np.mat('0 0;'
           '0 1;'
           '1 0;'
           '1 1')
x = torch.tensor(x).float()
y = np.mat('1;'
           '0;'
           '0;'
           '1')
y = torch.tensor(y).float()


# 搭建网络
myNet = nn.Sequential( 
    nn.Linear(2,10),
    nn.ReLU(),
    nn.Linear(10,1),
    nn.Sigmoid()
    )
print(myNet)

# 设置损失函数和优化器
optimzer = torch.optim.SGD(myNet.parameters(), lr=0.05)
loss_func = nn.MSELoss()

for epoch in range(5000):
    out = myNet(x)
    loss = loss_func(out, y)
    optimzer.zero_grad()
    loss.backward()
    optimzer.step()

# 打印结果
print(myNet(x).data)

# tensor变量其实是包含两个部分的，一部分是tensor数据，另一部分是tensor的自动求导参数，我们加上.data意思是输出取tensor中的数据