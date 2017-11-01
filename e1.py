# 简单的0/1背包问题
# m为背包载重 n为物品数量
def knap(m, n, l):
    if m == l[n-1]:
        return True
    elif m > l[n-1]:
        if n > 1:
            if knap(m-l[n-1], n-1, l)==True:
                return True
            else:
                return knap(m, n-1, l)
        else:
            return False
    else:
        if n > 1:
            return knap(m, n-1, l)
        else:
            return False


m=20
n=5
l=[3,5,8,79,30]
print(knap(m, n, l))
