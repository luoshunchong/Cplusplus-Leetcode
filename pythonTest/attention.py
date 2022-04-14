import torch
import torch.nn as nn
import torch.nn.functional as F
import math

def selfAttention(Q, K, V):
    q = nn.Linear(10, 20)(Q)
    k = nn.Linear(10, 20)(K)
    v = nn.Linear(10, 20)(V)

    d_k = Q.size(-1)
    socre = torch.bmm(q, k.transpose(-1, -2)) / math.sqrt(d_k)
    p = F.softmax(socre, -1)
    output = torch.bmm(p, v)
    return output


Q = torch.randn(2, 4, 10) # [batch_size, seq_len, dim]
K = torch.randn(2, 4, 10) # [batch_size, seq_len, dim]
V = torch.randn(2, 4, 10) # [batch_size, seq_len, dim]
output = selfAttention(Q, K, V)
print(output.size())
# print(output)