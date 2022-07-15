import torch
import torch.nn as nn

class LinearNet(nn.Module):
    def __init__(self):
        super(LinearNet, self).__init__()
        self.linear=nn.Linear(5, 1) #使用torch.nn中的线性回归函数
        
    #定义前向传播
    def forward(self, x):
        y = self.linear(x)
        return y
    

net =LinearNet()
print(net)   #使用print可以打印出网络的结构