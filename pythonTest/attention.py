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


# 由chatGPT实现：

class Attention(nn.Module):
    def __init__(self, hidden_size):
        super(Attention, self).__init__()
        self.hidden_size = hidden_size
        self.attn = nn.Linear(self.hidden_size * 2, hidden_size)
        self.v = nn.Parameter(torch.rand(hidden_size))
        stdv = 1. / math.sqrt(self.v.size(0))
        self.v.data.normal_(mean=0, std=stdv)

    def forward(self, hidden, encoder_outputs):
        timestep = encoder_outputs.size(0)
        h = hidden.repeat(timestep, 1, 1).transpose(0, 1)
        encoder_outputs = encoder_outputs.transpose(0, 1)  # [B*T*H]
        attn_energies = self.score(h, encoder_outputs)
        return F.softmax(attn_energies, dim=1).unsqueeze(1)

    def score(self, hidden, encoder_outputs):
        # [B*T*2H]->[B*T*H]
        energy = F.relu(self.attn(torch.cat([hidden, encoder_outputs], 2)))
        energy = energy.transpose(1, 2)  # [B*H*T]
        v = self.v.repeat(encoder_outputs.size(0), 1).unsqueeze(1)  # [B*1*H]
        energy = torch.bmm(v, energy)  # [B*1*T]
        return energy.squeeze(1)  # [B*T]
