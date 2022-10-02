# # selfattention
# import torch
# import torch.nn as nn
# import torch.nn.functional as F
# import math

# # Q [2, 4, 10]

# def attention(Q, K, V):
#     q = nn.Linear(10, 20)(Q)
#     k = nn.Linear(10, 20)(K)
#     v = nn.Linear(10, 20)(V)
#     d_k = Q.size(-1)
#     score = torch.bmm(q, k.transpose(-1, -2)) / math.sqrt(d_k)
#     p = F.softmax(score, -1)
#     output = torch.bmm(p, v)
#     return output

# Q = torch.randn(2, 4, 10)
# K = torch.randn(2, 4, 10)
# V = torch.randn(2, 4, 10)
# output = attention(Q, K, V)

# # 自定义神经网络
# import torch
# import torch.nn as nn
# import torch.nn.functional as F

# x = torch.FloatTensor([0, 0], [2, 3], [5, 6]) #[3, 2]
# label = torch.FloatTensor([1, 0, 1])

# # 搭建神经网络
# myNet = nn.Linear(2, 10)

# # 设置损失函数和优化器
# opt = torch.optim.SGD(myNet.parameters(), lr=0.05)
# loss = nn.MSELoss()

# # 开始循环训练
# for epoch in range(100):
#     out = myNet(x)
#     los = loss(out, label)
#     opt.zero_grad()
#     los.backward()
#     opt.step()

# 自定义模型
# import torch
# import torch.nn as nn
# import torch.nn.functional as F

# class myNet(nn.Module):
#     def __init__(self):
#         super(myNet, self).__init__()
#         self.linear = nn.Linear(5, 1)

#     def forward(self, x):
#         y = self.linear(x)
#         return y

# x = torch.randn(2, 5)
# net = myNet(x)
# print(net)