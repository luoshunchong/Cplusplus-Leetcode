

# # python内置函数map的用法
# def check(num):
#     return num * num

# res = list(map(check, [2,3,4]))
# print(res)
# print(type(res))  # 是一个列表

# 怎么得到list中的index、value值

mylist = [1,2,2,3]
print(mylist.index(2))
print([i for i, j in enumerate(mylist) if j == 2])