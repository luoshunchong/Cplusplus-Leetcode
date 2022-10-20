import torch
import torch.nn as nn
import torch.nn.funcational as F
import math

def check(q, k, v):
    Q = nn.Linear(10, 20)(q)
    K = nn.Linear(10, 20)(k)
    V = nn.Linear(10, 20)(v)

    d_k = q.size(-1)
    sorce = torch.bmm(Q, K.transpose(-1, -2)) / math.sqrt(d_k)
    p = F.softmax(sorce, -1)
    output = torch.bmm(p, v)
    return output

q = torch.randn(2, 4, 10)
k = torch.randn(2, 4, 10)
v = torch.randn(2, 4, 10)
o = check(q, k, v)
print(o)
